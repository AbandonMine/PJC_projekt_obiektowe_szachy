#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <iostream>
using namespace std;
namespace Ui {
class Menu;
}

//! Klasa odpowiedzialna za implementację menu startowego programu.
class Menu : public QMainWindow
{
    Q_OBJECT

public:

//! Konstruktor klasy.
    /*!
     * \param parent wskaźnik na obiekt rodzica przekazywany do konstruktora klasy bazowej.
     */
    explicit Menu(QWidget *parent = nullptr);

//! Destruktor klasy.
    ~Menu();

private slots:

//! Slot obsługujący wciśnięcie RadioButtona odpowiedzialnego za wybór trybu rozgrywki 960.
    void on_tryb_960_in_clicked();

//! Slot obsługujący wciśnięcie RadioButtona odpowiedzialnego za wybór trybu rozgrywki standardowego.
    void on_tryb_klasyczny_in_clicked();

//! Slot obsługujący zmianę wybranej opcji w ComboBoxie dotyczącej rodzaju graczy biorących udział w rozgrywce.
    void on_wybor_rozgrywki_currentIndexChanged(int index);

//! Slot obsługujący zmianę wybranej opcji w ComboBoxie dotyczącej sposobu hostowania gry w internecie.
    void on_wybor_net_currentIndexChanged(int index);

//! Slot obsługujący wpisanie adresu ip w pole tekstowy w przypadku wybrania gry przez internet.
    void on_ip_in_textChanged();

//! Slot obsługujący wpisanie numeru portu w pole tekstowy w przypadku wybrania gry przez internet.
    void on_port_in_textChanged();

//! Slot obsługujący wciśnięcie przycisku rozpoczynającego grę.
    void on_rozpocznij_gre_clicked();

//! Slot obsługujący wciśnięcie przycisku wyjścia z aplikacji.
    void on_exit_button_clicked();


private:

//! Wskaźnik do ustawienia ui obiektu.
    Ui::Menu *ui;

//! Zmienna przechowująca informację o tym czy gra jest w formacie standardowym czy 960.
    bool czy_standard;

//! Zmienna przechowująca infromację czy gra odbywa się przez internet.
    bool czy_internet;

//! Zmienna przechowująca infromację czy gra odbywa się z między graczami czy z silnikiem szachowym.
    bool czy_komputer;

//! Zmienna przechowująca infromację czy w przypadku gry przez internet gracz pełni rolę hosta.
    bool czy_host;

//! Zmienna tekstowa przechowująca podany adres ip.
    string ip_podane;

//! Zmienna tekstowa przechowująca podany numer portu.
    string port_podane;

};

#endif // MENU_H
