#include "gra_control.h"
#include "ui_gra_control.h"
#include "network.h/server_mode.h"
#include "network.h/client_mode.h"

Gra_control::Gra_control(QWidget *parent, bool standard, bool komputer, bool internet, bool host, string ip_podane, string port_podane) :
    QMainWindow(parent),
    ui(new Ui::Gra_control)
{
    // Ustawienie gui z odpowiedniego formularza.

    ui->setupUi(this);

    // Dolaczenie sygnalow odpowiedzialnych za obsluge myszy do odpowiednich slotow.

    connect(ui->label, SIGNAL(on_wcisniecie_myszy(double, double)), this,  SLOT(obsluga_wcisniecia_myszy(double, double)));
    connect(ui->label, SIGNAL(on_zwolnienie_myszy(double, double)), this,  SLOT(obsluga_zwolnienia_myszy(double, double)));

    czy_internet = internet;
    czy_komputer = komputer;
    czy_standard = standard;
    czy_host = host;
    connected = false;


    // Stworzenie modelu rozgrywki i zainicjowanie go.
    gra = new Gra_model(czy_standard, czy_internet, czy_komputer, czy_host);
    gra->inicializuj();

    // Wyswietlenie aktualnego gracza..

    ui->aktualny_kolor_out->setText(QString::fromStdString(gra->aktualny_kolor()));

    // Stworzenie nowej instancji klasy odpowiedzialnej za wyswietlenie rozgrywki i następnie wyświetlenie planszy oraz figur.

    widok_gry = new Gra_view;
    widok_gry->wyswietl_plansze(ui->label);
    widok_gry->wyswietl_figury(gra->podaj_plansze(), ui->label, ui->zbite_1_out, ui->zbite_2_out);

    // Jeżeli gra prowadzona jest przez internet zablokowanie możliwości wczytania pozycji z kodu FEN oraz utworzenie odpowiednich
    // struktur do obsługi komunikacji przez sieć. Podłączenie sygnałów odpowiedzialnych za wykrycie połączenia oraz przekazanie otrzymanego
    // ruchu do odpowiednich slotów obsługujących te sygnały. Jeżeli nie uda się utworzyć instancji wyświetlenie komunikatu błędu.

    if(czy_internet == true)
    {
        ui->wczytaj_z_FEN_in->setEnabled(false);
        if(czy_host == true)
        {
            network = new Server_mode(this, ip_podane, port_podane );
            connect(network, SIGNAL(polaczenie_udane()),    this,  SLOT(gdy_polaczenie_udane()));
            connect(network, SIGNAL(wykonano_ruch(string)), this,  SLOT(gdy_otrzymano_ruch(string)));
            if(network->czy_stworzono() == false)
            {
                polaczenie_nieudane();
                return;
            }
        } else {
            network = new Client_mode(this, ip_podane, port_podane);
            connect(network, SIGNAL(polaczenie_udane()),    this,  SLOT(gdy_polaczenie_udane()));
            connect(network, SIGNAL(wykonano_ruch(string)), this,  SLOT(gdy_otrzymano_ruch(string)));
            if(network->czy_stworzono() == false)
            {
                polaczenie_nieudane();
                return;
            }
            else {
                emit network->polaczenie_udane();
            }
        }
    }

}

Gra_control::~Gra_control()
{
    delete ui;
    delete widok_gry;
    if(czy_internet == true)
    {
        delete network;
    }
    delete gra;
}

// Slot obslugujacy wcisniecie myszy.

void Gra_control::obsluga_wcisniecia_myszy(double x, double y)
{
    // Przeliczenie wspolrzednych myszy na zapis startowego pola ruchu w notacji szachowej.

    int kolumna, rzad;
    kolumna =int(int(x)/80);
    rzad = int(int(640-y)/80);
    char k, r;
    k = char(kolumna + 97);
    r = char(rzad + 49);
    string napis;
    napis += k;
    napis += r;
    polecenie = napis;

    // Wyswietlenie informacji o rozpoczęciu wykonywaniu ruchu w gui.

    ui->pole_start_out->setText(QString::fromStdString(napis));
    setCursor(Qt::ClosedHandCursor);
}

// Slot obslugujacy zwolnienie myszy.

void Gra_control::obsluga_zwolnienia_myszy(double x, double y)
{
    // Przeliczenie wspolrzednych myszy na zapis koncowego pola ruchu w notacji szachowej.

    int kolumna, rzad;
    kolumna =int(int(x)/80);
    rzad = int(int(640-y)/80);
    char k, r;
    k = char(kolumna + 97);
    r = char(rzad + 49);
    string napis;
    napis += k;
    napis += r;
    polecenie += k;
    polecenie += r;

    // Wyswietlenie informacji o polu końcowym ruchu w gui.
    ui->pole_konc_out->setText(QString::fromStdString(napis));
    setCursor(Qt::PointingHandCursor);

    // Jeżeli gra prowadzona jest przez internet i drugi gracz nie jest dołaczony do rozgrywki
    // lub nie wykonał jeszcze swojego ruchu, próba ruchu zostanie zakończona w tym miejscu i
    // wyświetlony zostanie odpowiedni komunikat.

    if(czy_internet == true && ((czy_slucha == true) || (connected == false)))
    {
        if(connected == false)
        {
            ui->komunikat_out->setText("Czekanie na dołaczenie przeciwnika!");
        } else {
            ui->komunikat_out->setText("Czekanie na ruch drugiego gracza!");
        }
        return;
    }

    // Jeżeli metoda obsluz ruch zwraca prawde - ruch wynikajacy z obslugi myszy jest poprawny
    // i zostal wykonany -kontroler sprawdza czy spowodowal on wypromowanie figury. Jeżeli tak
    // wyświetlane jest odpowiednie menu. Jeżeli gra prowadzona jest przez internet wykonany ruch
    // przesylany jest do przeciwnika. Nastepnie aktualizowane jest gui aplikacji. Jeżeli ruch był
    // niepoprawny to wyświetlany jest jedynie komunikat błędu.

    if(gra->obsluz_ruch(polecenie))
    {
        string polecenie_do_przeslania = polecenie;
        if(gra->czy_poromowanie())
        {

            wybor = new Wybor_figury(this);
            connect(wybor, SIGNAL(wybrano_figury(char)), this, SLOT(promowanie_figury(char)));
            wybor->show();

        } else {
            if(czy_internet == true)
            {
                czy_slucha = true;
                network->przeslij_polecenie(polecenie);
            }
        }

        ui->komunikat_out->setText(QString::fromStdString(gra->podaj_komunikat()));
        ui->aktualny_kolor_out->setText(QString::fromStdString(gra->aktualny_kolor()));

        widok_gry->wyswietl_plansze(ui->label);
        widok_gry->wyswietl_figury(gra->podaj_plansze(), ui->label, ui->zbite_1_out, ui->zbite_2_out);
        widok_gry->wyswietl_liste(ui->lista_ruchow, gra->podaj_liste_ruchow());


    } else {
       ui->komunikat_out->setText(QString::fromStdString(gra->podaj_komunikat()));
    }
}

void Gra_control::on_powrot_do_menu_clicked()
{
      menu_startowe.show();
      this->close();
}

void Gra_control::polaczenie_nieudane()
{
    QMessageBox error;
    error.critical(nullptr, "Error", "Polaczenie nieudane. Wroc do menu i sprobuj ponownie!");
}

// Slot oblsugujacy otrzymanie ruchu z struktur sieciowych przy grze przez internet. W przypadku promowania
// symbol wybranej figury jest dolaczony do przesylanego polecenia, co jest sprawdzane takżę w tym kodzie,

void Gra_control::gdy_otrzymano_ruch(string polecenie)
{
    if(czy_slucha == true)
    {

        gra->obsluz_ruch(polecenie);
        if(gra->czy_poromowanie())
        {
            gra->promuj(polecenie[4]);
        }
        widok_gry->wyswietl_plansze(ui->label);
        widok_gry->wyswietl_figury(gra->podaj_plansze(), ui->label, ui->zbite_1_out, ui->zbite_2_out);
        widok_gry->wyswietl_liste(ui->lista_ruchow, gra->podaj_liste_ruchow());
        ui->aktualny_kolor_out->setText(QString::fromStdString(gra->aktualny_kolor()));
        czy_slucha = false;
    }

}

void Gra_control::gdy_polaczenie_udane()
{
    connected = true;
    ui->connect_label->setText("connected");
    if(czy_host == true)
        czy_slucha = false;
    else {
        czy_slucha = true;
    }
}

// Slot obslugujacy promowanie figury po wybraniu jej typu z odpowiedniego menu i w przypadku gry
// przez internet przeslanie ruchu z symbolem figury.

void Gra_control::promowanie_figury(char symbol)
{
    gra->promuj(symbol);
    if(czy_internet == true)
    {
        string polecenie_prom = polecenie;
        polecenie_prom += symbol;
        network->przeslij_polecenie(polecenie_prom);
    }

    widok_gry->wyswietl_plansze(ui->label);
    widok_gry->wyswietl_figury(gra->podaj_plansze(), ui->label, ui->zbite_1_out, ui->zbite_2_out);
    widok_gry->wyswietl_liste(ui->lista_ruchow, gra->podaj_liste_ruchow());
    ui->aktualny_kolor_out->setText(QString::fromStdString(gra->aktualny_kolor()));

}

// Slot obslugujący wczytanie pozycji z kodu FEN i aktualizację gui.

void Gra_control::gdy_wpisano_fen(string kod_FEN)
{
    gra->ustaw_z_FEN(kod_FEN);
    widok_gry->wyswietl_plansze(ui->label);
    widok_gry->wyswietl_figury(gra->podaj_plansze(), ui->label, ui->zbite_1_out, ui->zbite_2_out);
    widok_gry->wyswietl_liste(ui->lista_ruchow, gra->podaj_liste_ruchow());
    ui->aktualny_kolor_out->setText(QString::fromStdString(gra->aktualny_kolor()));
}

// Slot obslugujący zapisywanie kodu fen do pliku textowego po wcisnieciu odpowiedniego przycisku.

void Gra_control::on_zapisz_do_FEN_in_clicked()
{
    // Wywolanie okna dialogowego pobierajacego nazwe pliku do zapisu kodu fen.

    QString pobieranie_nazwy = QFileDialog::getSaveFileName(this,
    tr("Zapisz dane"), "",
    tr("Dane  (*.txt);;All Files (*)"));
    string nazwa_pliku = pobieranie_nazwy.toStdString();

    // Zapis kodu do pliku z kontrola poprawnosci otwarcia pliku.

    fstream plik;
    plik.open(nazwa_pliku.c_str(), std::ios::out);
    if(!plik.good())
    {
        QMessageBox messageBox;
        messageBox.critical(nullptr,"Error","Nie udalo sie zapisac danych !");
        messageBox.setFixedSize(500,200);
        return;
    }
    plik << "Kod FEN zapisanej gry: " << endl;
    plik << gra->wygeneruj_FEN();
    plik.close();

}

// Slot wywołujący menu wczytywania kodu FEN po wciśnięciu odpowiedniego przycisku.

void Gra_control::on_wczytaj_z_FEN_in_clicked()
{
    Wczytanie_fen* menu_wczytywania;
    menu_wczytywania = new Wczytanie_fen(this);
    menu_wczytywania->show();
    connect(menu_wczytywania, SIGNAL(wpisano_fen(string)), this, SLOT(gdy_wpisano_fen(string)));

}
