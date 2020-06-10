#include "figury.h/goniec.h"


Goniec::Goniec(string kolor, char symbol) : Figura (kolor, symbol)
{
}

bool Goniec::moze_sie_ruszyc_do(Pole *destynacja)
{
    // Goniec może ruszyć się do danego pola jeżeli znajduję się ono na tej samej przekątnej
    // co pole zajmowane przez figurę - wartości bezwzględne z różnicy numerów rzędów i numerów kolumn
    // muszą być sobie równe.

    int y_p  = znajdz_polozenie()->podaj_rzad();
    int x_p  = znajdz_polozenie()->podaj_kolumne();
    int y_k  = destynacja->podaj_rzad();
    int x_k  = destynacja->podaj_kolumne();
    if(abs(x_p-x_k)==abs(y_p-y_k))
        return true;
    return false;
}

Goniec::~Goniec()
{

}
