#include "figury.h/krol.h"

Krol::Krol(string kolor, char symbol): Figura_z_ogranieczniami (kolor, symbol)
{
}

bool Krol::moze_sie_ruszyc_do(Pole *destynacja)
{
    // Krol moze ruszyć się do danego pola, jeżeli znajduję się ono w sąsiedztwie pola zajmowanego
    // przez króla. Sprawdzane jest to za pomocą dodawania do współrzednych pola zajmowanego przez
    // figurę kolejno wartości z tablic pol_x i pol_y, zawierających wszystkie możliwe inkrementy,
    // i porównywanie ich z współrzędnymi pola do którego gracz próbuje ruszyć figurę.

    int pol_x[8] = { 1, 1,  1,  0, -1, -1, -1, 0};
    int pol_y[8] = {-1, 0,  1,  1,  1,  0, -1, -1};
    int y_p  = znajdz_polozenie()->podaj_rzad();
    int x_p  = znajdz_polozenie()->podaj_kolumne();
    int y_k  = destynacja->podaj_rzad();
    int x_k  = destynacja->podaj_kolumne();

    for(int i = 0; i<8; i++)
        if((x_p+pol_x[i] == x_k) && (y_p+pol_y[i] == y_k))
             return true;
    return false;
}

Krol::~Krol()
{
}
