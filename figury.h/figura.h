#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include <cstdlib>
#include <pole.h>
using namespace std;

//! Klasa Figura.
/*!
 * \brief Abstrakcyjna klasa figury zapewniająca wszystkie funkcjonalności wspólne dla wszystkich bierek.
 */

class Figura
{
public:

    Figura() = delete;

//! Konstruktor klasy.
    /*!
     * \param kolor  zmienna przekazująca kolor utworzonej figury.
     * \param symbol zmienna przekazująca symbol utworzonej figury.
     */

    Figura(string kolor, char symbol);

//! Metoda zwracająca kolor figury.
    string podaj_kolor();

//! Metoda zwracająca symbol figury.
    char podaj_symbol();

//! Wirtualna metoda pozwalająca na sprawdzenie możliwości ruchu figury do danego pola.
    /*!
     * \param polozenie pole do którego sprawdzana jest możliwość ruchu przez figurę.
     * \return jeżeli figura może się ruszyć do danego pola zwaracana jest prawda, w przeciwnym razie fałsz.
     */
    virtual bool moze_sie_ruszyc_do(Pole* polozenie);

//! Metoda pozwalająca na zapisanie w figurze wskaźnika do jej położenia na planszy.
    /*!
     * \brief Metoda pozwala na znacznie efektywniejsze sprawdzanie szacha oraz mata oraz możliwości ruchu figury.
     * \param nowe_polozenie Wskaźnik do pola zajmowanego przez figurę na planszy.
     */
    void zajmij_polozenie(Pole* nowe_polozenie);

//! Metoda zwracająca zapisane wskaźnik do pola zajmowanego przez figurę na planszy.
    /*!
     * \brief Metoda pozwala na znacznie efektywniejsze sprawdzanie szacha oraz mata.
     * \return zwracany jest wskaźnik do pola na planszy.
     */
    Pole* znajdz_polozenie();

//! Wirtualny destruktor.
    virtual ~Figura();

protected:

//! Zmienna przechowująca kolor figury.
    string kolor_figury;

//! Zmienna przechowująca symbol figury.
    char symbol_figury;

//! Zmienna przechowująca wskaźnik do pola zajmowanego przez figurę.
    Pole* polozenie;
};

#endif // FIGURA_H
