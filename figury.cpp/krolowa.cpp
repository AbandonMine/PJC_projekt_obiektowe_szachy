#include "figury.h/krolowa.h"


Krolowa::Krolowa(string kolor, char symbol) :Figura(kolor, symbol)
{
}

bool Krolowa::moze_sie_ruszyc_do(Pole *destynacja)
{
    // Krolowa zawiera połaczenie możliwości ruchowych wieży oraz gońca - może poruszyć się
    // do pól znajdujących się w jednym rzędzie, kolumnie lub przękatnej co pole zajmowane
    // przez figurę. Zatem warunkiem będzie aby wartośco bezwzględne róźnicy rzędów i kolumn
    // byly sobie rowne lub aby numery rzedów lub numery kolumn obu pól były identyczne.

    int y_p  = znajdz_polozenie()->podaj_rzad();
    int x_p  = znajdz_polozenie()->podaj_kolumne();
    int y_k  = destynacja->podaj_rzad();
    int x_k  = destynacja->podaj_kolumne();
    if(((x_p == x_k) || (y_p == y_k)) || (abs(x_p-x_k)==abs(y_p-y_k)))
        return true;
    return false;


}

Krolowa::~Krolowa()
{

}

