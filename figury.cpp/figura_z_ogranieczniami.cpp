#include "figury.h/figura_z_ogranieczniami.h"

Figura_z_ogranieczniami::Figura_z_ogranieczniami(string kolor, char symbol) : Figura(kolor, symbol)
{
    czy_ruszono = false;
}

void Figura_z_ogranieczniami::ruszono()
{
    czy_ruszono = true;
}

bool Figura_z_ogranieczniami::sprawdz_czy_ruszono()
{
    return czy_ruszono;
}

Figura_z_ogranieczniami::~Figura_z_ogranieczniami()
{
}
