#include "silnikszachowy.h"

// Miejsce na zaimplementowanie silnika szachowego w przypadku rozwiajania programu

SilnikSzachowy::SilnikSzachowy(string kolor_figur, Plansza * plansza) : Gracz (kolor_figur, plansza)
{
}

Ruch *SilnikSzachowy::pobierz_ruch(string polecenie)
{
    Ruch * wykonany_ruch;
    int rzad_s, kolumna_s, rzad_k, kolumna_k;
    rzad_s = polecenie[0] - 97;
    kolumna_s = polecenie[1] - 49;
    rzad_k = polecenie[2] - 97;
    kolumna_k = polecenie[3] - 49;
    wykonany_ruch = new Ruch(rzad_s, kolumna_s, rzad_k, kolumna_k, szachownica);
    wykonany_ruch->ustaw_etykiete(polecenie);;
    return wykonany_ruch;
}

SilnikSzachowy::~SilnikSzachowy()
{
}

void SilnikSzachowy::ocen_sytuacje(Plansza* plansza)
{
}
