#ifndef WYBOR_FIGURY_H
#define WYBOR_FIGURY_H

#include <QMainWindow>

namespace Ui {
class Wybor_figury;
}

//! Klasa Wybor_figury
/*!
 * \brief f Klasa odpowiedzialna za graficzny interfejs użytkownika przy wyborze typu figury do promowania. Klasa pochodna klasy QMainWindow.
 */
class Wybor_figury : public QMainWindow
{
    Q_OBJECT

public:

//! Konstruktor klasy.
    /*!
    * \param parent wskaźnik do obiektu-rodzica przekazywany do konstruktora klasy bazowej.
    */
    explicit Wybor_figury(QWidget *parent = nullptr);

//! Destruktor klasy.
    ~Wybor_figury();

private slots:

//! Slot obsługujący zmianę wybranej opcji w ComboBoxie dotyczącej typu wypromowanej figury.
    void on_ktora_figura_currentIndexChanged(int index);

//! Slot obsługujący kliknięcie przyciska zatwierdzenia.
    void on_zatwierdzono_clicked();

signals:

//! Sygnał przesyłający symbol wybranej figury do kontrolera po wciśnięciu przycisku zatwierdzenia.
    void wybrano_figury(char);

private:

//! Zmienna przechowujący aktualny symbol wybranej figury.
    char symbol_figury;

//! Wskaźnik do ustawienia ui obiektu.
    Ui::Wybor_figury *ui;
};

#endif // WYBOR_FIGURY_H
