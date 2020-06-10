#ifndef KROL_H
#define KROL_H
#include "figura_z_ogranieczniami.h"

//! Klasa implementująca bierkę - króla.
class Krol : public Figura_z_ogranieczniami
{
public:
//! Konstruktor klasy.
    /*!
    * \brief Parametry są przekazywane do konstruktora klasy bazowej.
    * \param kolor  zmienna przekazująca kolor utworzonej figury.
    * \param symbol zmienna przekazująca symbol utworzonej figury.
    */
    Krol(string kolor, char symbol);

//! Metoda sprawdzająca możliwości ruchu konkretnej figury do danego położenia na planszy.
    /*!
    * \brief Implementacja metody wirtualnej.
    * \param destynacja wskaźnik do położenia na planszy do którego próbuje się ruszyć figurę.
    * \return zwraca prawdę jeżeli figura może się ruszyć do danego położenia, fałsz w przeciwnym razie.
    */
    bool moze_sie_ruszyc_do(Pole* destynacja);

//! Destruktor klasy.
    ~Krol();
};

#endif // KROL_H
