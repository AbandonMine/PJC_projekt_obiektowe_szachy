#ifndef KROLOWA_H
#define KROLOWA_H
#include "figura.h"

//! Klasa Krolowa
/*!
 * \brief Klasa implementująca bierkę - królową. Klasa pochodna klasy figura.
 */

class Krolowa : public Figura
{
public:
//! Konstruktor klasy.
    /*!
    * \brief Parametry są przekazywane do konstruktora klasy bazowej.
    * \param kolor  zmienna przekazująca kolor utworzonej figury.
    * \param symbol zmienna przekazująca symbol utworzonej figury.
    */
    Krolowa(string kolor, char symbol);

//! Metoda sprawdzająca możliwości ruchu konkretnej figury do danego położenia na planszy.
    /*!
    * \brief Implementacja metody wirtualnej.
    * \param destynacja wskaźnik do położenia na planszy do którego próbuje się ruszyć figurę.
    * \return zwraca prawdę jeżeli figura może się ruszyć do danego położenia, fałsz w przeciwnym razie.
    */
    bool moze_sie_ruszyc_do(Pole* destynacja);

//! Destruktor klasy.
    ~Krolowa();
};


#endif // KROLOWA_H
