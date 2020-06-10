#include "ruch.h"

Ruch::Ruch(int skad_rzad, int skad_kolumna, int dokad_rzad, int dokad_kolumna, Plansza* plansza)
{
    rzad_s = skad_rzad;
    kolumna_s = skad_kolumna;
    rzad_k = dokad_rzad;
    kolumna_k = dokad_kolumna;
    start = plansza->zlap_pole(kolumna_s, rzad_s);
    koniec = plansza->zlap_pole(kolumna_k, rzad_k);
}

Ruch::Ruch(Pole *skad, Pole *dokad)
{
    start = skad;
    koniec = dokad;
    rzad_s = skad->podaj_rzad();
    kolumna_s = skad->podaj_kolumne();
    rzad_k = dokad->podaj_rzad();
    kolumna_k = dokad->podaj_kolumne();
}

Pole *Ruch::podaj_koniec()
{
    return koniec;
}

Pole* Ruch::podaj_start()
{
    return start;
}

int Ruch::podaj_rzad_start()
{
    return rzad_s;
}

int Ruch::podaj_kolumne_start()
{
    return kolumna_s;
}

int Ruch::podaj_rzad_koniec()
{
    return rzad_k;
}

int Ruch::podaj_kolumne_koniec()
{
    return kolumna_k;
}

bool Ruch::czy_roszada()
{
    // Algorytm pozwalający sprawdzić czy dany ruch jest roszadą.

    if((rzad_s == 4) && (kolumna_s == 0))
        if(((rzad_k == 0) && (kolumna_k == 0)) || ((rzad_k == 7) && (kolumna_k == 0)) )
            return true;
    if((rzad_s == 4) && (kolumna_s == 7))
        if(((rzad_k == 0) && (kolumna_k == 7)) || ((rzad_k == 7) && (kolumna_k == 7)) )
            return true;
    return false;
}

string Ruch::podaj_etykiete()
{
    return etykieta;
}

void Ruch::ustaw_etykiete(string etykieta_podana)
{
    etykieta = etykieta_podana;
}
