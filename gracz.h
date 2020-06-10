#ifndef GRACZ_H
#define GRACZ_H
#include "ruch.h"
using namespace std;

//! Klasa Gracz
/*!
 * \brief Abstrakcyjna klasa implementująca gracza biorącego udział w partii szachów.
 */
class Gracz
{
public:

    Gracz() = delete;

//! Konstruktor klasy
    /*!
     * \brief Gracz
     * \param kolor_figur zmienna definiująca kolor figur gracza.
     * \param plansza wskaźnik do planszy na której gra gracz.
     */
    Gracz(string kolor_figur, Plansza * plansza);

//! Metoda zwracająca kolor bierek danego gracza.
    string sprawdz_kolor();

//! Wirtualna metoda odpowiadająca za wykonanie ruchu przez danego gracza.
    /*!
     * \param polecenie pole początkowe i końcowe ruchu w standarowej notacji szachowej, brane pod uwagę gdy ruch wykonywany jest przez gracza ludzkiego.
     * \return ruch zwracany jest w postaci wskaźnika do klasy Ruch.
     */
    virtual Ruch* pobierz_ruch(string polecenie);

//! Wirtualny destruktor klasy.
    virtual ~Gracz();

protected:

//! Zmienna tekstowa przechowująca informację o kolorze figur gracza.
    string kolor_figur_gracza;

//! Zmienna przechowująca wskaźnik do planszy na której gra gracz.
    Plansza * szachownica;

};

#endif // GRACZ_H

