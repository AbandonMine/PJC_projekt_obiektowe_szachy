#ifndef WCZYTANIE_FEN_H
#define WCZYTANIE_FEN_H

#include <QDialog>
#include <iostream>
using namespace std;
namespace Ui {
class Wczytanie_fen;
}

//! Klasa odpowiedzialna za graficzny interfejs użytkownika przy wczytywaniu kodu FEN.
class Wczytanie_fen : public QDialog
{
    Q_OBJECT

public:

//! Konstruktor klasy.
    /*!
     * \param parent wskaźnik do obiektu-rodzica przekazywany do konstruktora klasy bazowej.
     */
    explicit Wczytanie_fen(QWidget *parent = nullptr);

//! Destruktor klasy.
    ~Wczytanie_fen();

signals:

//! Sygnał emitowany i przesyłany do kontrolera, gdy wpisany został kod FEN i kliknięty został przycisk zatwierdź.
    void wpisano_fen(string);

private slots:

//! Slot obsługujący kliknięcie przycisku zatwierdzającego wpisany kod FEN.
    void on_buttonBox_accepted();

//! Slot obsługujący kliknięcie przycisku anulującego wpisanie kody FEN.
    void on_buttonBox_rejected();

//! Slot obsługujący wpisanie przez użytkownika kodu FEN w okno tekstowe.
    void on_kod_FEN_in_textChanged();

private:

//! Zmienna tekstowa przechowująca wpisany w okno tekstowe kod FEN.
    string kod_FEN;

//! Wskaźnik do ustawienia ui obiektu.
    Ui::Wczytanie_fen *ui;

};

#endif // WCZYTANIE_FEN_H
