#ifndef SILNIKSZACHOWY_H
#define SILNIKSZACHOWY_H
#include "gracz.h"


//! Klasa LudzkiGracz
/*!
 * \brief Implementacja gracza sterowanego przez silnik szachowy. W obecnej wersji programu silnik nie został zaimplementowany i klasa zachowuje się tak samo jak klasa LudzkiGracz. Klasa pochodna klasy Gracz.
 */

class SilnikSzachowy : public Gracz
{
public:
//! Konstruktor klasy
    /*!
     * \param kolor_figur zmienna definiująca kolor figur gracza.
     * \param plansza wskaźnik do planszy na której gra gracz.
     */
    SilnikSzachowy(string kolor_figur, Plansza * plansza);

//! Implementacja wirtualnej metody odpowiedzialnej za wykonywanie przez gracza ruchu.
    /*!
     * \brief Obecnie metoda działa tak samo jak w przypadku klasy LudzkiGracz. Przy dalszym rozwoju programu w tym miejscu zostałby umieszczony algorytm generujący ruch automatycznie na podstawie sytuacji na planszy.
     */
    Ruch* pobierz_ruch(string polecenie);

//! Destruktor klasy.
    ~SilnikSzachowy();
private:

//! Niezaimplementowana metoda oceniająca sytuację na planszy za pomocą algorytmu MinMax.
    void ocen_sytuacje(Plansza* plansza);
};

#endif // SILNIKSZACHOWY_H
