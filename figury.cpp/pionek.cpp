#include "figury.h/pionek.h"

Pionek::Pionek(string kolor, char symbol) : Figura_z_ogranieczniami (kolor, symbol)
{
}

bool Pionek::czy_ruszono_o_2_pola()
{
    return ruszono_o_2_pola;
}

bool Pionek::moze_sie_ruszyc_do(Pole *destynacja)
{
    // Ruch pionka zależy od jego koloru - gdy jest biały może poruszać się jedynie w górę planszy o 1 pole,
    // gdy jest czarny jedynie o jedno pole w dol. Dodatkowo możliwy jest do wykonania ruch o dwa pola, jeżeli
    // dany pionek nie był wcześniej ruszony może poruszyć się o dwa pola. Kolejnym ograniczeniem jest to, że pionek
    // w odróżnieniu od innych figur nie ma możliwości bicia równoznacznych z możliwościami przemieszczania - nie może
    // ruszyć się w górę/dół do zajętego pola i może ruszyć się o 1 pole po przękątnej jeżeli dane pole jest zajęte
    // bijąc tym samym znajdującą się tam figure.

    int y_p  = znajdz_polozenie()->podaj_rzad();
    int x_p  = znajdz_polozenie()->podaj_kolumne();
    int y_k  = destynacja->podaj_rzad();
    int x_k  = destynacja->podaj_kolumne();

    if(kolor_figury == "bialy")
    {
        if(y_p == y_k)
        {
            if((x_k == x_p+2) && czy_ruszono == false && (destynacja->czy_zajety() == false))
            {
                ruszono_o_2_pola = true;
                return true;
            }
            if(x_k == x_p+1 &&  (destynacja->czy_zajety() == false))
            {
                ruszono_o_2_pola = false;
                return true;
            }
        }
        if((abs(y_p-y_k) == 1) && (x_k == x_p+1) && (destynacja->czy_zajety() == true))
        {
            ruszono_o_2_pola = false;
            return true;
        }
        return false;

    } else {
        if(y_p == y_k)
        {
            if((x_k == x_p-2) && czy_ruszono == false&& (destynacja->czy_zajety() == false))
            {
                ruszono_o_2_pola = true;
                return true;
            }
            if(x_k == x_p-1 && (destynacja->czy_zajety() == false))
            {
                ruszono_o_2_pola = false;
                return true;
            }

        }
        if((abs(y_p-y_k) == 1) && (x_k == x_p-1) && (destynacja->czy_zajety() == true))
        {
            ruszono_o_2_pola = false;
            return true;
        }
        return false;
    }

}

Pionek::~Pionek()
{

}
