#ifndef GRA_CONTROL_H
#define GRA_CONTROL_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include "gra_model.h"
#include "gra_view.h"
#include "network.h/gra_network.h"
#include "wybor_figury.h"
#include "wczytanie_fen.h"
#include "menu.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace Ui {
class Gra_control;
}

//! Klasa Gra_control
/*!
 * \brief Klasa odpowiadająca za implementacje kontrolera we wzorcu MVC. Pochodna klasy QMainWindow.
 */
class Gra_control : public QMainWindow
{
    Q_OBJECT

public:

//! Konstruktor klasy
    /*!
     * \brief W konstruktorze następuje inicjalizacja modelu i widoku gry oraz struktur sieciowych jeżeli wybrano gre przez internet.
     * \param parent   wskaźnik do obiektu-rodzica przekazywany do konstruktora klasy bazowej.
     * \param standard infromacja czy gra będzie rozgrywała się z pozycji standardowej czy 960.
     * \param komputer informacja czy gra rozgrywa się między graczami czy z silnikiem szachowym.
     * \param internet informacja czy gra rozgrywa się lokalnie czy przez internet.
     * \param host     informacja czy gracz jest hostem rozgrywki w wypadku gry przez internet.
     * \param ip_podane   infomracja o numerze ip w przypadku gry przez internet.
     * \param port_podane infromacja o numerze portu w przypadku gry przez internet.
     */
    explicit Gra_control(QWidget *parent = nullptr, bool standard = true, bool komputer = true, bool internet = false, bool host = true, string ip_podane = "", string port_podane = "");

//! Destruktor klasy
    ~Gra_control();

public slots:

//! Slot obslugujący wciśnięcie przycisku myszy w obrębie planszy.
    void obsluga_wcisniecia_myszy(double x, double y);

//! Slot obslugujący zwolnienie przycisku myszy w obrębie planszy co równoznaczne jest z wykonaniem ruchu.
    void obsluga_zwolnienia_myszy(double x, double y);

//! Slot obslugujący otrzymanie ruchu od przeciwnika w przypadku gry przez internet.
    void gdy_otrzymano_ruch(string polecenie);

//! Slot rozpoczynający grę przez sieć w przypadku uzyskania połączenia.
    void gdy_polaczenie_udane();

//! Slot obslugujący sytuację wybrania figury z menu wyboru przy jej promowaniu.
    void promowanie_figury(char symbol);

//! Slot obslugujący sytuację wpisania i wczytania gry z kodu FEN.
    void gdy_wpisano_fen(string kod_FEN);

private slots:

//! Slot obsługujący wciśnięcie przycisku powrotu do menu startowego programu.
    void on_powrot_do_menu_clicked();

//! Slot obsługujący wytworzenie i zapisanie w komputerze kodu FEN po wciśnięciu odpowiedniego przycisku.
    void on_zapisz_do_FEN_in_clicked();

//! Slot obsługujacy wciśnięcie przycisku odczytania kodu FEN.
    void on_wczytaj_z_FEN_in_clicked();



private:

//! Metoda używana przy wyświetlaniu komunikatu błędu o nieudanym połączeniu.
    void polaczenie_nieudane();

//! Wskaźnik do ustawienia ui obiektu.
    Ui::Gra_control *ui;

//! Zmienna przechowująca informację o tym czy gra jest w formacie standardowym czy 960.
    bool czy_standard;

//! Zmienna przechowująca infromację czy gra odbywa się z między graczami czy z silnikiem szachowym.
    bool czy_komputer;

//! Zmienna przechowująca infromację czy gra odbywa się przez internet.
    bool czy_internet;

//! Zmienna przechowująca infromację czy w przypadku gry przez internet gracz pełni rolę hosta.
    bool czy_host;

//! Zmienna przechowująca infromację czy w danym momencie gracz wykonuje ruch, czy czeka na ruch przeciwnika w przypadku gry przez internet.
    bool czy_slucha;

//! Zmienna mówiąca czy udało się poprawnie uzyskać połączenie z drugim graczem w wypadku gry przez internet.
    bool connected;

//! Zmienna przechowująca wskaźnik do obiektu odpowiedzialnego za wyświetlanie rozgrywki.
    Gra_view * widok_gry;

//! Zmienna przechowująca wskaźnik do modelu - obiektu odpowiedzialnego za logikę rozgrywki.
    Gra_model * gra;

//! Zmienna przechowująca wskaźnik do obiektu odpowiedzailnego za funkcje sieciowe gry,
    Gra_network * network;

//! Zmienna przechowująca wskaźnik do menu wyboru figury w przypadku promowania.
    Wybor_figury* wybor;

//! Zmienna przechowująca startowe menu.
    Menu menu_startowe;

//! Zmienna przechowująca notację ostatniego ruchu.
    string polecenie;


};

#endif // GRA_CONTROL_H
