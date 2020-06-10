#include "figury.h/wieza.h"



Wieza::Wieza(string kolor, char symbol) : Figura_z_ogranieczniami (kolor, symbol)
{
}

bool Wieza::moze_sie_ruszyc_do(Pole *destynacja)
{
    // Kolumna- może poruszyć się do pól znajdujących się w jednym rzędzie lub kolumnie co pole zajmowane
    // przez figurę. Zatem warunkiem będzie aby numery rzedów lub numery kolumn obu pól były identyczne.

    int y_p  = znajdz_polozenie()->podaj_rzad();
    int x_p  = znajdz_polozenie()->podaj_kolumne();
    int y_k  = destynacja->podaj_rzad();
    int x_k  = destynacja->podaj_kolumne();
    if((x_p == x_k) || (y_p == y_k))
        return true;
    return false;

}

Wieza::~Wieza()
{
}
