#include "pole.h"

Pole::Pole(int x, int y)
{
    rzad = y;
    kolumna = x;
    zajety = false;
    zajmujacy = nullptr;
}

bool Pole::czy_zajety()
{
    return zajety;
}

Figura *Pole::kto_zajmuje()
{
    return zajmujacy;
}

void Pole::zajmij(Figura *obecna_figura)
{
    zajmujacy = obecna_figura;
    zajety = true;
}

void Pole::zwolnij()
{
    zajmujacy = nullptr;
    zajety = false;
}

int Pole::podaj_rzad()
{
    return rzad;
}

int Pole::podaj_kolumne()
{
    return kolumna;
}
