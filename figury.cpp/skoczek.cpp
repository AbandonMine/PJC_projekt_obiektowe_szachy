#include "figury.h/skoczek.h"

Skoczek::Skoczek(string kolor, char symbol) : Figura (kolor, symbol)
{
}

bool Skoczek::moze_sie_ruszyc_do(Pole *destynacja)
{
    // Skoczek ma dosyć specyficzny ruch po literze "L" zatem, aby w łatwy sposób
    // sprawdzić czy dana figura wykonuje ruch po tej literze, ponownie jak w przypadku
    // króla utworzono tablicą inkrementów które po dodaniu do pola figury dają wszystkie
    // możliwe pola końcowe osiągalne przez figurę.

    int y_p  = znajdz_polozenie()->podaj_rzad();
    int x_p  = znajdz_polozenie()->podaj_kolumne();
    int y_k  = destynacja->podaj_rzad();
    int x_k  = destynacja->podaj_kolumne();
    int pol_x[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int pol_y[8] = {1, 2,  2,  1, -1, -2, -2, -1};
    for(int i = 0; i<8; i++)
        if((x_p+pol_x[i] == x_k) && (y_p+pol_y[i] == y_k))
             return true;
    return false;

}

Skoczek::~Skoczek()
{

}
