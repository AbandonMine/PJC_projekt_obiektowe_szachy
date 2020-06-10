#include "figury.h/figura.h"

Figura::Figura(string kolor, char symbol)
{
    kolor_figury = kolor;
    symbol_figury = symbol;
}

string Figura::podaj_kolor()
{
    return kolor_figury;
}

char Figura::podaj_symbol()
{
    return symbol_figury;
}

bool Figura::moze_sie_ruszyc_do(Pole *polozenie)
{
}

void Figura::zajmij_polozenie(Pole* nowe_polozenie)
{
    polozenie = nowe_polozenie;
}

Pole *Figura::znajdz_polozenie()
{
    return polozenie;
}

Figura::~Figura()
{
}

