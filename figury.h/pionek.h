#ifndef PIONEK_H
#define PIONEK_H
#include "figura_z_ogranieczniami.h"

//! Klasa implementująca bierkę - pionek.
class Pionek : public Figura_z_ogranieczniami
{
public:
//! Konstruktor klasy.
    /*!
    * \brief Parametry są przekazywane do konstruktora klasy bazowej.
    * \param kolor  zmienna przekazująca kolor utworzonej figury.
    * \param symbol zmienna przekazująca symbol utworzonej figury.
    */
    Pionek(string kolor, char symbol);

//! Metoda sprawdzająca możliwości ruchu konkretnej figury do danego położenia na planszy.
    /*!
    * \brief Implementacja metody wirtualnej.
    * \param destynacja wskaźnik do położenia na planszy do którego próbuje się ruszyć figurę.
    * \return zwraca prawdę jeżeli figura może się ruszyć do danego położenia, fałsz w przeciwnym razie.
    */
    bool moze_sie_ruszyc_do(Pole* destynacja);

//! Metoda sprawdzająca czy dany pionek został w ostatnim ruchu ruszony o 2 pola.
    /*!
     * \brief Metoda używana przy sprawdzaniu prawdiłowości bicia w przelocie.
     * \return Zwraca prawdę jeżeli pionek ruszył się o 2 pola, fałsz w przeciwnym razie.
     */
    bool czy_ruszono_o_2_pola();

//! Destruktor klasy.
    ~Pionek();

private:
//! Zmienna przechowująca infromację czy w ostatnim ruchu pionek był ruszony o 2 pola.
    bool ruszono_o_2_pola;
};


#endif // PIONEK_H
