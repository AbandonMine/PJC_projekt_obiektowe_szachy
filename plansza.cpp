#include "plansza.h"
#include "ruch.h"
#include <cstdlib>
#include <time.h>
Plansza::Plansza()
{
       // Zalokowanie pamieci na pola planszy i figury.

       for(int i = 0; i< wymiar; i++)
           for(int j = 0; j< wymiar; j++)
               pola[i][j] = new Pole(i, j);


       figury_biale[0] = new Wieza   ("bialy", 'R');
       figury_biale[1] = new Skoczek ("bialy", 'N');
       figury_biale[2] = new Goniec  ("bialy", 'B');
       figury_biale[3] = new Krolowa ("bialy", 'Q');
       figury_biale[4] = new Krol    ("bialy", 'K');
       figury_biale[5] = new Goniec  ("bialy", 'B');
       figury_biale[6] = new Skoczek ("bialy", 'N');
       figury_biale[7] = new Wieza   ("bialy", 'R');

       for(int i = wymiar; i < startowa_liczba_figur; i++)
           figury_biale[i] = new Pionek("bialy", 'P');

       figury_czarne[0] = new Wieza   ("czarny", 'r');
       figury_czarne[1] = new Skoczek ("czarny", 'n');
       figury_czarne[2] = new Goniec  ("czarny", 'b');
       figury_czarne[3] = new Krolowa ("czarny", 'q');
       figury_czarne[4] = new Krol    ("czarny", 'k');
       figury_czarne[5] = new Goniec  ("czarny", 'b');
       figury_czarne[6] = new Skoczek ("czarny", 'n');
       figury_czarne[7] = new Wieza   ("czarny", 'r');

       for(int i = wymiar; i < startowa_liczba_figur; i++)
           figury_czarne[i] = new Pionek("czarny", 'p');
}


void Plansza::przypisz_standard()
{
    for(int i = 0; i< wymiar; i++)
        for(int j = 0; j< wymiar; j++)
            pola[j][i]->zwolnij();

    for(int i = 0; i< wymiar; i++)
    {
        pola[0][i]->zajmij(figury_biale[i]);
        figury_biale[i]->zajmij_polozenie(pola[0][i]);
        pola[1][i]->zajmij(figury_biale[wymiar+i]);
        figury_biale[wymiar+i]->zajmij_polozenie(pola[1][i]);
        pola[wymiar-1][i]->zajmij(figury_czarne[i]);
        figury_czarne[i]->zajmij_polozenie(pola[wymiar-1][i]);
        pola[wymiar-2][i]->zajmij(figury_czarne[wymiar+i]);
        figury_czarne[wymiar+i]->zajmij_polozenie(pola[wymiar-2][i]);
    }

}

void Plansza::przypisz_960()
{
    srand(time(nullptr));

    // Wylosowanie pozycji 1 gońca na jednym z pól nieparzystych licząc od lewej.

    int los1 = rand()%4;
    pola[0][2*los1]->zajmij(figury_biale[2]);
    figury_biale[2]->zajmij_polozenie(pola[0][2*los1]);
    pola[7][2*los1]->zajmij(figury_czarne[2]);
    figury_czarne[2]->zajmij_polozenie(pola[7][2*los1]);

    // Wylosowanie pozycji 2 gońca na jednym z pól parzystych licząc od lewej.

    int los2 = rand()%4;
    pola[0][2*los2+1]->zajmij(figury_biale[5]);
    figury_biale[5]->zajmij_polozenie(pola[0][2*los2+1]);
    pola[7][2*los2+1]->zajmij(figury_czarne[5]);
    figury_czarne[5]->zajmij_polozenie(pola[7][2*los2+1]);

    // Wylosowanie pozycji królowej z pozostałych pól.

    int los3 = rand()%6;
    for(int i = 0; i < wymiar; i++)
    {
        if(pola[0][i]->czy_zajety() )
            los3++;
        if(los3 == i && pola[0][i]->czy_zajety() == false)
        {
            pola[0][los3]->zajmij(figury_biale[3]);
            figury_biale[3]->zajmij_polozenie(pola[0][los3]);
            pola[7][los3]->zajmij(figury_czarne[3]);
            figury_czarne[3]->zajmij_polozenie(pola[7][los3]);
        }
    }

    // Wylosowanie pozycji 1 skoka z pozostałych pól.

    int los4 = rand()%5;
    for(int i = 0; i < wymiar; i++)
    {
        if(pola[0][i]->czy_zajety() == true)
            los4++;
        if(los4 == i && pola[0][i]->czy_zajety() == false)
        {
            pola[0][los4]->zajmij(figury_biale[1]);
            figury_biale[1]->zajmij_polozenie(pola[0][los4]);
            pola[7][los4]->zajmij(figury_czarne[1]);
            figury_czarne[1]->zajmij_polozenie(pola[7][los4]);
        }
    }

    // Wylosowanie pozycji 2 skoka z pozostałych pól.

    int los5 = rand()%4;
    for(int i = 0; i < wymiar; i++)
    {
        if(pola[0][i]->czy_zajety() == true)
            los5++;
        if(los5 == i && pola[0][i]->czy_zajety() == false)
        {
            pola[0][los5]->zajmij(figury_biale[6]);
            figury_biale[6]->zajmij_polozenie(pola[0][los5]);
            pola[7][los5]->zajmij(figury_czarne[6]);
            figury_czarne[6]->zajmij_polozenie(pola[7][los5]);
        }
    }

    // Umiejscowienie 1 wiezy na 1 wolnym polu.

    for(int i = 0; i < wymiar; i++)
        if(pola[0][i]->czy_zajety() == false)
        {
            pola[0][i]->zajmij(figury_biale[0]);
            figury_biale[0]->zajmij_polozenie(pola[0][i]);
            pola[7][i]->zajmij(figury_czarne[0]);
            figury_czarne[0]->zajmij_polozenie(pola[7][i]);
            break;
        }

    // Umiejscowienie krola na 1 wolnym polu.

    for(int i = 0; i < wymiar; i++)
        if(pola[0][i]->czy_zajety() == false)
        {
            pola[0][i]->zajmij(figury_biale[4]);
            figury_biale[4]->zajmij_polozenie(pola[0][i]);
            pola[7][i]->zajmij(figury_czarne[4]);
            figury_czarne[4]->zajmij_polozenie(pola[7][i]);
            break;
        }

    // Umiejscowienie 2 wiezy na ostatnim wolnym polu w rzedzie figur.

    for(int i = 0; i < wymiar; i++)
        if(pola[0][i]->czy_zajety() == false)
        {
            pola[0][i]->zajmij(figury_biale[7]);
            figury_biale[7]->zajmij_polozenie(pola[0][i]);
            pola[7][i]->zajmij(figury_czarne[7]);
            figury_czarne[7]->zajmij_polozenie(pola[7][i]);
            break;
        }

    // Przypisanie pionów.
    for(int i = 0; i < wymiar; i++)
    {
         pola[1][i]->zajmij(figury_biale[wymiar+i]);
         figury_biale[wymiar+i]->zajmij_polozenie(pola[1][i]);
         pola[wymiar-2][i]->zajmij(figury_czarne[wymiar+i]);
         figury_czarne[wymiar+i]->zajmij_polozenie(pola[wymiar-2][i]);
    }

}

bool Plansza::czy_rzad_wolny(Pole* odkad, Pole* dokad)
{
    //Sprawdzenie czy wszystkie znajdujące się w rzędzie pola pomiędzy odkąd i dokąd są wolne.

    int y_p  = odkad->podaj_rzad();
    int x_p = odkad->podaj_kolumne();
    int y_k = dokad->podaj_rzad();
    int x_k  = dokad->podaj_kolumne();
    if(x_p != x_k )
        return false;
    if(y_k>y_p)
    {
        for(int i = 1; i < (y_k-y_p); i++)
            if(pola[x_p][y_p+i]->czy_zajety() == true)
                return false;
        return true;
    } else {
        for(int i = 1; i < (y_p-y_k); i++)
            if(pola[x_p][y_p-i]->czy_zajety() == true)
                return false;
        return true;
    }
}

bool Plansza::czy_kolumna_wolna(Pole* odkad, Pole* dokad)
{

    //Sprawdzenie czy wszystkie znajdujące się w kolumnie pola pomiędzy odkąd i dokąd są wolne.

    int y_p  = odkad->podaj_rzad();
    int x_p = odkad->podaj_kolumne();
    int y_k = dokad->podaj_rzad();
    int x_k  = dokad->podaj_kolumne();
    if(y_p != y_k )
        return false;
    if(x_k>x_p)
    {
        for(int i = 1; i < (x_k-x_p); i++)
            if(pola[x_p+i][y_p]->czy_zajety() == true)
                return false;
        return true;
    } else {
        for(int i = 1; i < (x_p-x_k); i++)
            if(pola[x_p-i][y_p]->czy_zajety() == true)
                return false;
        return true;
    }
}




bool Plansza::czy_przekatna_wolna(Pole* odkad, Pole* dokad)
{
    //Sprawdzenie czy wszystkie znajdujące się po przekątnej pola pomiędzy odkąd i dokąd są wolne.

    int y_p  = odkad->podaj_rzad();
    int x_p = odkad->podaj_kolumne();
    int y_k = dokad->podaj_rzad();
    int x_k  = dokad->podaj_kolumne();

    if(x_k>x_p)
    {
        if(y_p < y_k )
        {
            for(int i = 1; i < (x_k-x_p); i++)
                for(int j = 1; j < (y_k-y_p); j++)
                    if((i == j) && (pola[x_p+i ][y_p+j]->czy_zajety() == true))
                        return false;
            return true;
        } else {
            for(int i = 1; i < (x_k-x_p); i++)
                for(int j = 1; j < (y_p-y_k); j++)
                    if((abs(i) == abs(j)) && (pola[x_p+i][y_p-j]->czy_zajety() == true))
                        return false;
            return true;
        }
    } else {

        if(y_p < y_k )
        {
            for(int i = 1; i < (x_p-x_k); i++)
                for(int j = 1; j < (y_k-y_p); j++)
                    if((abs(i) == abs(j)) && (pola[x_p-i][y_p+j]->czy_zajety() == true))
                        return false;
            return true;
        } else {
            for(int i = 1; i < (x_p-x_k); i++)
                for(int j = 1; j < (y_p-y_k); j++)
                    if((abs(i) == abs(j)) && (pola[x_p-i][y_p-j]->czy_zajety() == true))
                        return false;
            return true;
        }
    }
}


bool Plansza::sprawdz_poprawnosc_ruchu(Ruch *do_sprawdzenia, string kolor)
{

    Figura_z_ogranieczniami* wsk_krol = dynamic_cast<Figura_z_ogranieczniami*>(do_sprawdzenia->podaj_start()->kto_zajmuje());
    if(wsk_krol != nullptr)
    {
        if(do_sprawdzenia->czy_roszada())
        {

            Figura_z_ogranieczniami* wsk_wieza = dynamic_cast<Figura_z_ogranieczniami*>(do_sprawdzenia->podaj_koniec()->kto_zajmuje());
            if(wsk_krol == nullptr && wsk_wieza == nullptr)
            {
                komunikat = "Niepoprawna roszada!";
                return false;
            }
            if(czy_szach_po_ruchu(do_sprawdzenia, kolor))
            {
                komunikat = "SZACH!";
                return false;
            }
            if(!(wsk_krol->sprawdz_czy_ruszono() || wsk_wieza->sprawdz_czy_ruszono()) && czy_rzad_wolny(do_sprawdzenia->podaj_start(), do_sprawdzenia->podaj_koniec()))
            {
                komunikat = "Poprawna roszada!";
                return true;
            } else {
                komunikat = "Niepoprawna roszada!";
                return false;
            }
        }
    }
    if(do_sprawdzenia->podaj_start()->czy_zajety() == false)
    {
        komunikat = "Pole jest puste!";
        return false;
    }
    if((do_sprawdzenia->podaj_start()->podaj_rzad() == do_sprawdzenia->podaj_koniec()->podaj_rzad()) && (do_sprawdzenia->podaj_start()->podaj_kolumne() == do_sprawdzenia->podaj_koniec()->podaj_kolumne()))
    {
        komunikat = "Figura juz znajduje się na tym polu!";
        return false;
    }
    if(do_sprawdzenia->podaj_start()->kto_zajmuje()->podaj_kolor() != kolor)
    {
        komunikat = " Proba ruchu figura nie nalezaca do gracza!";
        return false;
    }
    if((do_sprawdzenia->podaj_koniec()->czy_zajety()) && (do_sprawdzenia->podaj_koniec()->kto_zajmuje()->podaj_kolor() == kolor))
    {
        komunikat = "Dwie figury gracza nie moga stac na tym samym polu!";
        return false;
    }
    if((do_sprawdzenia->podaj_start()->podaj_rzad() == do_sprawdzenia->podaj_koniec()->podaj_rzad()) && !(czy_kolumna_wolna(do_sprawdzenia->podaj_start(), do_sprawdzenia->podaj_koniec())))
    {
        komunikat = "Proba ruchu po zajetej kolumnie!";
        return false;
    }
    if((do_sprawdzenia->podaj_start()->podaj_kolumne() == do_sprawdzenia->podaj_koniec()->podaj_kolumne()) && !(czy_rzad_wolny(do_sprawdzenia->podaj_start(), do_sprawdzenia->podaj_koniec())))
    {
        komunikat = "Proba ruchu po zajetym rzedzie!";
        return false;
    }
    if((abs(do_sprawdzenia->podaj_start()->podaj_rzad() - do_sprawdzenia->podaj_koniec()->podaj_rzad()) == abs(do_sprawdzenia->podaj_start()->podaj_kolumne() - do_sprawdzenia->podaj_koniec()->podaj_kolumne())) &&
            !(czy_przekatna_wolna(do_sprawdzenia->podaj_start(), do_sprawdzenia->podaj_koniec())) )
    {
        komunikat = "Proba ruchu po zajetej przekatnej!";
        return false;
    }
    if(!(do_sprawdzenia->podaj_start()->kto_zajmuje()->moze_sie_ruszyc_do(do_sprawdzenia->podaj_koniec())))
    {
        komunikat = "Dana figura nie moze sie tak ruszyc!";
        return false;
    }
    if(czy_szach_po_ruchu(do_sprawdzenia, kolor))
    {
        komunikat = "SZACH!";
        return false;
    }
    komunikat = "Ruch poprawny!";

    return true;
}

bool Plansza::sprawdz_poprawnosc_obrony(Ruch *do_sprawdzenia)
{
    // Analogicznie jak przy spradzaniu poprawności ruchu z tą różnicą, że nie wyświetlany jest komunikat i nie sprawdzanę jest czy figura należy do danego gracza.
    // Użyto tej metody jedynie przy spradzaniu obronnych ruchów przy macie gdzie wiadomo, przy tworzeniu ruchu przez program, że figury obu graczy należą do nich.

    if( do_sprawdzenia->podaj_koniec()->czy_zajety() )
    {
        if((do_sprawdzenia->podaj_start()->podaj_rzad() == do_sprawdzenia->podaj_koniec()->podaj_rzad()) && (do_sprawdzenia->podaj_start()->podaj_kolumne() == do_sprawdzenia->podaj_koniec()->podaj_kolumne()))
            return false;

        if(do_sprawdzenia->podaj_start()->kto_zajmuje()->podaj_kolor() == do_sprawdzenia->podaj_koniec()->kto_zajmuje()->podaj_kolor())
            return false;
    }

    if((do_sprawdzenia->podaj_start()->podaj_rzad() == do_sprawdzenia->podaj_koniec()->podaj_rzad()) && !(czy_kolumna_wolna(do_sprawdzenia->podaj_start(), do_sprawdzenia->podaj_koniec())))
        return false;

    if((do_sprawdzenia->podaj_start()->podaj_kolumne() == do_sprawdzenia->podaj_koniec()->podaj_kolumne()) && !(czy_rzad_wolny(do_sprawdzenia->podaj_start(), do_sprawdzenia->podaj_koniec())))
        return false;

    if((abs(do_sprawdzenia->podaj_start()->podaj_rzad() - do_sprawdzenia->podaj_koniec()->podaj_rzad()) == abs(do_sprawdzenia->podaj_start()->podaj_kolumne() - do_sprawdzenia->podaj_koniec()->podaj_kolumne())) &&
        !(czy_przekatna_wolna(do_sprawdzenia->podaj_start(), do_sprawdzenia->podaj_koniec())))
        return false;

    if(!(do_sprawdzenia->podaj_start()->kto_zajmuje()->moze_sie_ruszyc_do(do_sprawdzenia->podaj_koniec())))
        return false;

    return true;
}

void Plansza::wykonaj_ruch(Ruch *do_wykonania)
{
    // Kod odpowiedzialny za spradzenie czy dany ruch jest roszadą i jej ewentualne wykonanie.

    if(do_wykonania->czy_roszada())
        {   
                if(do_wykonania->podaj_koniec()->podaj_rzad() == 7)
                {
                    // Krótka roszada.

                    if(do_wykonania->podaj_start()->kto_zajmuje()->podaj_kolor() == "bialy")
                    {
                        zlap_pole(0, 6)->zajmij(do_wykonania->podaj_start()->kto_zajmuje());
                        do_wykonania->podaj_start()->kto_zajmuje()->zajmij_polozenie(zlap_pole(0, 6));
                        zlap_pole(0, 5)->zajmij(do_wykonania->podaj_koniec()->kto_zajmuje());
                        do_wykonania->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(zlap_pole(0, 5));


                    } else {
                        zlap_pole(7, 6)->zajmij(do_wykonania->podaj_start()->kto_zajmuje());
                        do_wykonania->podaj_start()->kto_zajmuje()->zajmij_polozenie(zlap_pole(7, 6));
                        zlap_pole(7, 5)->zajmij(do_wykonania->podaj_koniec()->kto_zajmuje());
                        do_wykonania->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(zlap_pole(7, 5));

                    }
                    do_wykonania->ustaw_etykiete("O-O");

                } else {

                    // Długa roszada.

                    if(do_wykonania->podaj_start()->kto_zajmuje()->podaj_kolor() == "bialy")
                    {
                        zlap_pole(0, 2)->zajmij(do_wykonania->podaj_start()->kto_zajmuje());
                        do_wykonania->podaj_start()->kto_zajmuje()->zajmij_polozenie(zlap_pole(0, 2));
                        zlap_pole(0, 3)->zajmij(do_wykonania->podaj_koniec()->kto_zajmuje());
                        do_wykonania->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(zlap_pole(0, 3));
                    } else {
                        zlap_pole(7, 2)->zajmij(do_wykonania->podaj_start()->kto_zajmuje());
                        do_wykonania->podaj_start()->kto_zajmuje()->zajmij_polozenie(zlap_pole(7, 2));
                        zlap_pole(7, 3)->zajmij(do_wykonania->podaj_koniec()->kto_zajmuje());
                        do_wykonania->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(zlap_pole(7, 3));
                    }
                    do_wykonania->ustaw_etykiete("O-O-O");

                }
                do_wykonania->podaj_start()->zwolnij();
                do_wykonania->podaj_koniec()->zwolnij();
                return;
        }

    // Jeżeli ruch następuje do zajętego pola, następuje zbicie figury która je zajmuje i dodanie jej do listy zbitych figur.

    if(do_wykonania->podaj_koniec()->czy_zajety() == true)
    {
        do_wykonania->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(nullptr);
        zbite_figury.push_back(do_wykonania->podaj_koniec()->kto_zajmuje());
    }

    // Przesuniecie figury na planszy.

    do_wykonania->podaj_koniec()->zajmij(do_wykonania->podaj_start()->kto_zajmuje());
    do_wykonania->podaj_start()->kto_zajmuje()->zajmij_polozenie(do_wykonania->podaj_koniec());
    do_wykonania->podaj_start()->zwolnij();

    // Sprawdzenie przy pomocy rzutowania dynamicznego czy dana figura jest figurą z ograniczeniami. Jeżeli tak to przy użyciu
    // odpowiedniej metody oznacza się, że została ruszona.

    Figura_z_ogranieczniami* wsk = dynamic_cast<Figura_z_ogranieczniami*>(do_wykonania->podaj_koniec()->kto_zajmuje());
    if( wsk != nullptr)
        wsk->ruszono();
}

vector<Figura *> Plansza::podaj_zbite_figury()
{
    return zbite_figury;
}

bool Plansza::czy_szach(string kolor)
{
    // Sprawdzenie czy po wykonaniu ruchu nastąpi szach odbywa się poprzez przejście przez listę figur aktualnego gracza
    // i utworzonie ruchu figury do pola zajmowanego przez przeciwnego króla. Jeżeli któryś z tak utworzonych ruchów jest
    //poprawny to przeciwny gracz znajduje się w szachu.

    Ruch * atak_na_krola;
    if(kolor == "bialy")
    {

        for(int i = 0; i < startowa_liczba_figur; i++)
        {
            if(figury_biale[i]->znajdz_polozenie() != nullptr)
            {

                atak_na_krola = new Ruch(figury_biale[i]->znajdz_polozenie(), figury_czarne[4]->znajdz_polozenie());
                if(sprawdz_poprawnosc_ruchu(atak_na_krola, kolor))
                {
                    delete atak_na_krola;
                    return true;
                }
                delete  atak_na_krola;
            }
        }
    } else {
        for(int i = 0; i < startowa_liczba_figur; i++)
        {
            if(figury_czarne[i]->znajdz_polozenie() != nullptr)
            {

                atak_na_krola = new Ruch(figury_czarne[i]->znajdz_polozenie(), figury_biale[4]->znajdz_polozenie());
                if(sprawdz_poprawnosc_ruchu(atak_na_krola, kolor))
                {
                    delete atak_na_krola;
                    return true;
                }
                delete  atak_na_krola;
            }
        }

    }
    return false;
}


bool Plansza::czy_mach(string kolor)
{
    // Sprawdzenie czy dany gracz został zamatowany odbywa się poprzez próbę wykonania przez wszystkie figury tego gracza ruchu do wszyskich
    // możliwych pol na planszy. W pierwszej kolejności sprawdzana jest poprawność tak utworzonego ruchu. Jeżeli jest on niepoprawny
    // jest od razu odrzucany, w przeciwnym razie sprawdzane jest czy po wykonaniu takiego ruchu gracz atakujący dalej szachuje króla
    // przeciwnika. Jeżeli tak ruch jest odrzucany i przeglądane są kolejne ruchy. Jeżeli nie zostanie znaleziony żaden ruch który broni
    // gracza to zwracana jest prawda - został on zamatowany. W przeciwnym razie, przy znalezieniu ruchu obronnego zwracany jest fałsz.
    // Jeżeli ruch obronny jest związany z zbiciem figury przeciwnika to jest ona przetrzymana we wskazniku pomocniczym tmp na czas
    // rozwazania pozycji.

    Ruch* ruch_obronny;
    Figura * tmp = nullptr;
    for (int k = 0; k < startowa_liczba_figur; k++)
        for (int i = 0; i < wymiar; i++)
            for(int j = 0; j < wymiar; j++)
                {
                    if(kolor == "bialy")
                    {
                        if(figury_czarne[k]->znajdz_polozenie() != nullptr)
                        {

                            ruch_obronny = new Ruch(figury_czarne[k]->znajdz_polozenie(), zlap_pole(i, j));
                            if(sprawdz_poprawnosc_obrony(ruch_obronny))
                            {

                                tmp = nullptr;
                                if(ruch_obronny->podaj_koniec()->czy_zajety() == true)
                                {
                                    tmp = ruch_obronny->podaj_koniec()->kto_zajmuje();
                                    ruch_obronny->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(nullptr);
                                }

                                ruch_obronny->podaj_koniec()->zajmij(ruch_obronny->podaj_start()->kto_zajmuje());
                                ruch_obronny->podaj_start()->kto_zajmuje()->zajmij_polozenie(ruch_obronny->podaj_koniec());
                                ruch_obronny->podaj_start()->zwolnij();

                                if( !czy_szach(kolor) )
                                {
                                    ruch_obronny->podaj_start()->zajmij(ruch_obronny->podaj_koniec()->kto_zajmuje());
                                    ruch_obronny->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(ruch_obronny->podaj_start());
                                    ruch_obronny->podaj_koniec()->zwolnij();

                                    if( tmp != nullptr)
                                    {
                                        ruch_obronny->podaj_koniec()->zajmij(tmp);
                                        tmp->zajmij_polozenie(ruch_obronny->podaj_koniec());
                                    }

                                    delete ruch_obronny;
                                    return false;

                                }


                                ruch_obronny->podaj_start()->zajmij(ruch_obronny->podaj_koniec()->kto_zajmuje());
                                ruch_obronny->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(ruch_obronny->podaj_start());
                                ruch_obronny->podaj_koniec()->zwolnij();

                                if( tmp != nullptr)
                                {

                                    ruch_obronny->podaj_koniec()->zajmij(tmp);
                                    tmp->zajmij_polozenie(ruch_obronny->podaj_koniec());
                                }
                            }

                            delete ruch_obronny;


                        }
                    } else {
                        if(figury_biale[k]->znajdz_polozenie() != nullptr)
                        {
                            ruch_obronny = new Ruch(figury_biale[k]->znajdz_polozenie(), zlap_pole(i, j) );
                            if(sprawdz_poprawnosc_obrony(ruch_obronny))
                            {
                                if(ruch_obronny->podaj_koniec()->czy_zajety() == true)
                                {
                                    tmp = ruch_obronny->podaj_koniec()->kto_zajmuje();
                                    ruch_obronny->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(nullptr);
                                }

                                ruch_obronny->podaj_koniec()->zajmij(ruch_obronny->podaj_start()->kto_zajmuje());
                                ruch_obronny->podaj_start()->kto_zajmuje()->zajmij_polozenie(ruch_obronny->podaj_koniec());
                                ruch_obronny->podaj_start()->zwolnij();

                                if(!czy_szach(kolor))
                                {
                                    ruch_obronny->podaj_start()->zajmij(ruch_obronny->podaj_koniec()->kto_zajmuje());
                                    ruch_obronny->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(ruch_obronny->podaj_start());
                                    ruch_obronny->podaj_koniec()->zwolnij();

                                    if( tmp != nullptr)
                                    {
                                        ruch_obronny->podaj_koniec()->zajmij(tmp);
                                        tmp->zajmij_polozenie(ruch_obronny->podaj_koniec());
                                    }

                                    delete ruch_obronny;
                                    return false;

                                }

                                ruch_obronny->podaj_start()->zajmij(ruch_obronny->podaj_koniec()->kto_zajmuje());
                                ruch_obronny->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(ruch_obronny->podaj_start());
                                ruch_obronny->podaj_koniec()->zwolnij();

                                if( tmp != nullptr)
                                {
                                    ruch_obronny->podaj_koniec()->zajmij(tmp);
                                    tmp->zajmij_polozenie(ruch_obronny->podaj_koniec());
                                }

                            }
                            delete ruch_obronny;
                            tmp = nullptr;

                        }
                    }
                }



        return true;





}

// Metoda sprawdzająca czy po wykonaniu danego ruchu, krol danego graczu będzie znajdował się w szachu.

bool Plansza::czy_szach_po_ruchu(Ruch *do_sprawdzenia, string kolor)
{
    Figura * tmp = nullptr;

    if(do_sprawdzenia->podaj_koniec()->czy_zajety() == true)
    {
        tmp = do_sprawdzenia->podaj_koniec()->kto_zajmuje();
        do_sprawdzenia->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(nullptr);
    }
    do_sprawdzenia->podaj_koniec()->zajmij(do_sprawdzenia->podaj_start()->kto_zajmuje());
    do_sprawdzenia->podaj_start()->kto_zajmuje()->zajmij_polozenie(do_sprawdzenia->podaj_koniec());
    do_sprawdzenia->podaj_start()->zwolnij();

    if(kolor == "bialy")
        kolor = "czarny";
    else {
        kolor = "bialy";
    }
    if(!czy_szach(kolor))
    {
        do_sprawdzenia->podaj_start()->zajmij(do_sprawdzenia->podaj_koniec()->kto_zajmuje());
        do_sprawdzenia->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(do_sprawdzenia->podaj_start());
        do_sprawdzenia->podaj_koniec()->zwolnij();
        if( tmp != nullptr)
        {
            do_sprawdzenia->podaj_koniec()->zajmij(tmp);
            tmp->zajmij_polozenie(do_sprawdzenia->podaj_koniec());
        }
        return false;
    }
    do_sprawdzenia->podaj_start()->zajmij(do_sprawdzenia->podaj_koniec()->kto_zajmuje());
    do_sprawdzenia->podaj_koniec()->kto_zajmuje()->zajmij_polozenie(do_sprawdzenia->podaj_start());
    do_sprawdzenia->podaj_koniec()->zwolnij();
    if( tmp != nullptr)
    {
        do_sprawdzenia->podaj_koniec()->zajmij(tmp);
        tmp->zajmij_polozenie(do_sprawdzenia->podaj_koniec());
    }
    return true;
}

Pole *Plansza::zlap_pole(int kolumna, int rzad)
{
    return pola[kolumna][rzad];
}

// Metoda obslogująca promowanie pionka.

void Plansza::promuj(char symbol_figury, string kolor, Ruch* ostatni_ruch)
{
    Figura * tmp;
    if(kolor== "bialy")
    {
        if(symbol_figury == 'q')
        {
            tmp = new Krolowa("bialy", 'Q');
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
        if(symbol_figury == 'b')
        {
            tmp = new Goniec("bialy", 'B');
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
        if(symbol_figury == 'n')
        {
            tmp = new Skoczek("bialy", 'N');
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
        if(symbol_figury == 'r')
        {
            tmp = new Krolowa("bialy", 'R');
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
    } else {
        if(symbol_figury == 'q')
        {
            tmp = new Krolowa("czarny", symbol_figury);
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
        if(symbol_figury == 'b')
        {
            tmp = new Goniec("czarny", symbol_figury);
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
        if(symbol_figury == 'n')
        {
            tmp = new Skoczek("czarny", symbol_figury);
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
        if(symbol_figury == 'r')
        {
            tmp = new Krolowa("czarny", symbol_figury);
            zamien_figury(ostatni_ruch->podaj_koniec()->kto_zajmuje(), tmp, kolor);
            tmp->zajmij_polozenie(ostatni_ruch->podaj_koniec());
            ostatni_ruch->podaj_koniec()->zajmij(tmp);
        }
    }
}

// Metoda zamieniająca na liście figur pionek na inną figurę przy promowaniu.

void Plansza::zamien_figury(Figura *zamieniana, Figura *zamiennik, string kolor)
{

    if(kolor == "bialy")
    {
        for(int i = 0; i < startowa_liczba_figur; i++)
        {
            if(figury_biale[i]->znajdz_polozenie() == zamieniana->znajdz_polozenie())
            {
                delete figury_biale[i];
                figury_biale[i] = zamiennik;
                break;
            }
        }
    } else {
        for(int i = 0; i < startowa_liczba_figur; i++)
            if(figury_czarne[i]->znajdz_polozenie() == zamieniana->znajdz_polozenie())
            {
                delete figury_czarne[i];
                figury_czarne[i] = zamiennik;
                break;
            }
    }

}


string Plansza::zapisz_do_FEN(bool standard, string kolor)
{
    // Zapisanie pozycji z planszy do kodu.

    string kod_FEN;
    int liczba_zer = 0;
    Figura* tmp;
    for(int i = wymiar-1; i>= 0; i--)
    {
        string linijka;
        for(int j = 0; j < wymiar ; j++)
        {
            tmp = pola[i][j]->kto_zajmuje();
            if(tmp == nullptr)
                liczba_zer++;
            else {
                if(liczba_zer != 0)
                {
                    linijka.append(to_string(liczba_zer));
                    liczba_zer = 0;
                }
                linijka += tmp->podaj_symbol();
            }
        }
        if(liczba_zer != 0)
        {
            linijka.append(to_string(liczba_zer));
            liczba_zer = 0;
        }
        kod_FEN.append(linijka);
        kod_FEN += "/";
    }
    kod_FEN.erase(kod_FEN.size()-1);

    // Zapisanie do kodu gracza obecnie wykonującego ruch.

    if(kolor == "bialy")
        kod_FEN.append(" w ");
    else {
        kod_FEN.append(" b ");
    }

    if(standard == true)
    {
        Wieza* wieza_1 = dynamic_cast<Wieza*>(figury_biale[0]);
        Wieza* wieza_2 = dynamic_cast<Wieza*>(figury_biale[7]);
        Krol* krol = dynamic_cast<Krol*>(figury_biale[4]);
        if((krol->sprawdz_czy_ruszono()== false) && (wieza_1->sprawdz_czy_ruszono()== false))
            kod_FEN.append("K");
        else {
            kod_FEN.append("-");
        }
        if((krol->sprawdz_czy_ruszono()== false) && (wieza_2->sprawdz_czy_ruszono()== false))
            kod_FEN.append("Q");
        else {
            kod_FEN.append("-");
        }
        wieza_1 = dynamic_cast<Wieza*>(figury_czarne[0]);
        wieza_2 = dynamic_cast<Wieza*>(figury_czarne[7]);
        krol = dynamic_cast<Krol*>(figury_czarne[4]);
        if((krol->sprawdz_czy_ruszono() == false) && (wieza_1->sprawdz_czy_ruszono() == false))
            kod_FEN.append("k");
        else {
            kod_FEN.append("-");
        }
        if((krol->sprawdz_czy_ruszono() == false) && (wieza_2->sprawdz_czy_ruszono() == false))
            kod_FEN.append("q ");
        else {
            kod_FEN.append("- ");
        }

    }
    for(int i = wymiar; i < startowa_liczba_figur; i++)
    {
        Pionek * tmp = dynamic_cast<Pionek*>(figury_biale[i]);
        if(tmp->czy_ruszono_o_2_pola() == true)
        {
            char k, r;
            r = char(tmp->znajdz_polozenie()->podaj_rzad() + 97);
            k = char(tmp->znajdz_polozenie()->podaj_kolumne()-1 + 49);
            kod_FEN += r;
            kod_FEN += k;
            return kod_FEN;
        }
        tmp = dynamic_cast<Pionek*>(figury_czarne[i]);
        if(tmp->czy_ruszono_o_2_pola() == true)
        {
            char k, r;
            r = char(tmp->znajdz_polozenie()->podaj_rzad() + 97);
            k = char(tmp->znajdz_polozenie()->podaj_kolumne()+1 + 49);
            kod_FEN += r;
            kod_FEN += k;
            return kod_FEN;
        }
    }
    kod_FEN.append("-");
    return kod_FEN;
}

bool Plansza::ustaw_z_FEN(string FEN, string kolor)
{
    for(int i = 0; i < wymiar*2; i++)
    {
        figury_biale[i]->zajmij_polozenie(nullptr);
        figury_czarne[i]->zajmij_polozenie(nullptr);
    }
    for (int i = 0; i < wymiar; i++)
        for (int j = 0; j < wymiar; j++)
            zlap_pole(i, j)->zwolnij();
    int liczba_pionkow_bialych = 0;
    int liczba_pionkow_czarnych = 0;
    size_t index = 0;
    int rzad = 7;
    int kolumna = 0;
    for(size_t i = 0; i < FEN.size(); i++)
        {
            if(FEN[i] == '/')
            {
                rzad--;
                kolumna = 0;
                index++;
                continue;
            }
            if(isdigit(FEN[i]))
            {
                kolumna += atoi(&FEN[i]);
                index++;
                continue;
            }
            if(FEN[i] == 'R')
            {
                if(figury_biale[0]->znajdz_polozenie() == nullptr)
                {
                    figury_biale[0]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_biale[0]);

                } else {
                    figury_biale[7]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_biale[7]);

                }
            }
            if(FEN[i] == 'N')
            {
                if(figury_biale[1]->znajdz_polozenie() == nullptr)
                {
                    figury_biale[1]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_biale[1]);

                } else {
                    figury_biale[6]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_biale[6]);

                }
            }
            if(FEN[i] == 'B')
            {
                if(figury_biale[2]->znajdz_polozenie() == nullptr)
                {
                    figury_biale[2]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_biale[2]);

                } else {
                    figury_biale[5]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_biale[5]);

                }
            }
            if(FEN[i] == 'Q')
            {
                figury_biale[3]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                zlap_pole(rzad, kolumna)->zajmij(figury_biale[3]);

            }
            if(FEN[i] == 'K')
            {
                figury_biale[4]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                zlap_pole(rzad, kolumna)->zajmij(figury_biale[4]);

            }
            if(FEN[i] == 'P')
            {
                figury_biale[liczba_pionkow_bialych+wymiar]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                zlap_pole(rzad, kolumna)->zajmij(figury_biale[liczba_pionkow_bialych+wymiar]);
                liczba_pionkow_bialych++;

            }


            if(FEN[i] == 'r')
            {
                if(figury_czarne[0]->znajdz_polozenie() == nullptr)
                {
                    figury_czarne[0]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                   zlap_pole(rzad, kolumna)->zajmij(figury_czarne[0]);

                } else {
                    figury_czarne[7]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_czarne[7]);

                }
            }
            if(FEN[i] == 'n')
            {
                if(figury_czarne[1]->znajdz_polozenie() == nullptr)
                {
                    figury_czarne[1]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_czarne[1]);

                } else {
                    figury_czarne[6]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_czarne[6]);

                }
            }
            if(FEN[i] == 'b')
            {
                if(figury_czarne[2]->znajdz_polozenie() == nullptr)
                {
                    figury_czarne[2]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_czarne[2]);

                } else {
                    figury_czarne[5]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                    zlap_pole(rzad, kolumna)->zajmij(figury_czarne[5]);

                }
            }
            if(FEN[i] == 'q')
            {
                figury_czarne[3]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                zlap_pole(rzad, kolumna)->zajmij(figury_czarne[3]);

            }
            if(FEN[i] == 'k')
            {
                figury_czarne[4]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                zlap_pole(rzad, kolumna)->zajmij(figury_czarne[4]);
            }
            if(FEN[i] == 'p')
            {
                figury_czarne[liczba_pionkow_czarnych+wymiar]->zajmij_polozenie(zlap_pole(rzad, kolumna));
                zlap_pole(rzad, kolumna)->zajmij(figury_czarne[liczba_pionkow_czarnych+wymiar]);
                liczba_pionkow_czarnych++;
            }

            kolumna++;
            index++;
            if(FEN[i] == ' ')
                break;

        }


    size_t index_pom = index + 2;
    string roszady = FEN.substr(index_pom, 4);
    if(roszady[0] == '-')
    {
        Wieza* wieza = dynamic_cast<Wieza*>(figury_biale[0]);
        wieza->ruszono();
    }
    if(roszady[1] == '-')
    {
        Wieza* wieza = dynamic_cast<Wieza*>(figury_biale[7]);
        wieza->ruszono();
    }
    if(roszady[2] == '-')
    {
        Wieza* wieza = dynamic_cast<Wieza*>(figury_czarne[0]);
        wieza->ruszono();
    }
    if(roszady[3] == '-')
    {
        Wieza* wieza = dynamic_cast<Wieza*>(figury_czarne[7]);
        wieza->ruszono();
    }

    if(FEN[index] == 'b' && kolor == "bialy")
        return true;
    if(FEN[index] == 'w' && kolor == "czarny")
        return true;
    return false;
}

string Plansza::podaj_komunikat()
{
    return komunikat;
}

Plansza::~Plansza()
{
    for(int i = 0; i < startowa_liczba_figur; i++)
    {
        delete figury_biale[i];
        delete figury_czarne[i];
    }

    for(int i = 0; i< wymiar; i++)
        for(int j = 0; j< wymiar; j++)
            delete pola[i][j];
}
