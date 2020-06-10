#ifndef LUDZKIGRACZ_H
#define LUDZKIGRACZ_H
#include "gracz.h"

//! Klasa implementujaca gracza sterowanego przez człowieka.
class LudzkiGracz : public Gracz
{
public:
//! Konstruktor klasy
    /*!
     * \brief Parametry przekazywane są do konstruktora klasy bazowej.
     * \param kolor_figur zmienna definiująca kolor figur gracza.
     * \param plansza wskaźnik do planszy na której gra gracz.
     */
    LudzkiGracz(string kolor_figur, Plansza * plansza);

//! Implementacja wirtualnej metody odpowiedzialnej za wykonywanie przez gracza ruchu.
    /*!
     * \param polecenie polecenie pole początkowe i końcowe ruchu w standarowej notacji szachowej pobierane z kontrolera.
     * \return ruch zwracany jest w postaci wskaźnika do klasy Ruch.
     */
    Ruch* pobierz_ruch(string polecenie);

//! Destruktor klasy.
    ~LudzkiGracz();
};

#endif // LUDZKIGRACZ_H
