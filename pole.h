#ifndef POLE_H
#define POLE_H
#include <iostream>
class Figura;

class Pole
{
public:
    Pole() =delete;
//! Konstruktor klasy.
    /*!
     * \param x numer kolumny tworzonego pola.
     * \param y numer rzędu tworzonego pola.
     */
    Pole(int x, int y);

//! Metoda sprawdzająca czy dane pole jest zajęte.
    /*!
     * \return zwracana jest prawda jeżeli do pola przypisana jest figura, fałsz w przeciwnym razie.
     */
    bool czy_zajety();

//! Metoda zwracająca wskaźnik do figury zajmującej dane pole.
    /*!
     * \brief W przypadku gdy pole jest puste zwracany jest wskaźnik zerowy: nullptr.
     */
    Figura* kto_zajmuje();

//! Metoda przypisująca do danego pola określoną figurę.
    /*!
     * \param obecna_figura wskaźnik na przypisywaną figurę.
     */
    void zajmij(Figura* obecna_figura);

//! Metoda pozwalająca na zwolnienie danego pola
    /*!
     * \brief Wskaźnik na figurę ustawiany jest jako nullptr.
     */
    void zwolnij();

//! Metoda zwracająca numer rzędu danego pola.
    int podaj_rzad();

//! Metoda zwracająca numer kolumny danego pola.
    int podaj_kolumne();

private:

//! Zmienna przechowująca numer kolumny danego pola.
    int kolumna;

//! Zmienna przechowująca numer rzędu danego pola.
    int rzad;

//! Zmienna przechowująca informacje czy dane pole jest zajęte.
    bool zajety;

//! Zmienna przechowująca wskaźnik do figury zajmującej dane pole.
    Figura* zajmujacy;


};

#endif // POLE_H
