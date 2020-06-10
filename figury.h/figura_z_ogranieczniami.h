#ifndef FIGURA_Z_OGRANIECZNIAMI_H
#define FIGURA_Z_OGRANIECZNIAMI_H
#include "figura.h"

//! Abstrakcyjna klasa reprezentująca figury z pewnymi ograniczeniami możliwości ruchu, jeżeli zostały ruszone.
class Figura_z_ogranieczniami : public Figura
{
public:

    Figura_z_ogranieczniami() = delete;

//! Konstruktor klasy.
    /*!
     * \brief  Konstruktor przekazuje parametru do konstruktora klasy bazowej figura.
     * \param kolor  zmienna przekazująca kolor utworzonej figury.
     * \param symbol zmienna przekazująca symbol utworzonej figury.
     */
    Figura_z_ogranieczniami(string kolor, char symbol);

//! Metoda oznakowująca daną figurę jako poruszoną.
    void ruszono();

//! Metoda sprawdzająca czy dana figura została już poruszona.
    /*!
     * \return prawda jeżeli figura została poruszona, fałsz w przeciwnym razie.
     */
    bool sprawdz_czy_ruszono();

 //! Wirtualny destruktor.
    virtual ~Figura_z_ogranieczniami();

protected:

//! Zmienna przechowująca infromację czy dana figura została poruszona.
     bool czy_ruszono;
};
#endif // FIGURA_Z_OGRANIECZNIAMI_H
