#include "gracz.h"


Gracz::Gracz(string kolor_figur, Plansza * plansza)
{
    kolor_figur_gracza = kolor_figur;
    szachownica = plansza;
}

string Gracz::sprawdz_kolor()
{
    return kolor_figur_gracza;
}

Ruch *Gracz::pobierz_ruch(string polecenie)
{
}

Gracz::~Gracz()
{
}


