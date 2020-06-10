#include "gra_model.h"

Gra_model::Gra_model(bool czy_standard, bool czy_internet, bool czy_komputer, bool czy_host)
{
    plansza = new Plansza;
    standard = czy_standard;
    internet = czy_internet;
    komputer = czy_komputer;
    host = czy_host;
}

void Gra_model::inicializuj()
{
    // Przypisanie figur na planszy w zależności od wybranego typu rozgrywki.

    if(standard == true)
        plansza->przypisz_standard();
    else {
        plansza->przypisz_960();
    }

    // Jeżeli wybrana została gra z komputerem utworzenie gracza ludzkiego i gracz obslugiwanego przez komputer
    // i losowo przydzielenie im koloru bierek. Jeżeli wybrano grę z graczem ludzkim, stworzenie dwóch graczy
    // ludzkich.

    if(komputer == true)
    {
        srand(time(nullptr));

        if(rand()%2 == 0)
        {
            gracze[0] = new LudzkiGracz     ("bialy",  plansza);
            gracze[1] = new SilnikSzachowy  ("czarny", plansza);

        } else {
            gracze[0] = new SilnikSzachowy  ("bialy",  plansza);
            gracze[1] = new LudzkiGracz     ("czarny", plansza);
        }

    } else{

            gracze[0] = new LudzkiGracz  ("bialy",  plansza);
            gracze[1] = new LudzkiGracz  ("czarny", plansza);

    }

    //Ustawienie gracza z białym kolorem bierek jako aktualnego gracza i wyczyszczenie listy ruchów.

    aktualnygracz = gracze[0];
    lista_ruchow.clear();

}



void Gra_model::zakoncz_wygrana()
{
    komunikat_gry = "Wygral gracz: " + aktualnygracz->sprawdz_kolor();
    for(size_t i = 0; i < lista_ruchow.size(); i++)
        delete lista_ruchow[i];
    inicializuj();
}



bool Gra_model::obsluz_ruch(string polecenie)
{
    // Utworzenie ruchu przez gracza.

    Ruch* pobrany_ruch = aktualnygracz->pobierz_ruch(polecenie);


    // Sprawdzenie poprawnosci danego ruchu.

    if(plansza->sprawdz_poprawnosc_ruchu(pobrany_ruch, aktualnygracz->sprawdz_kolor()))
    {
        // Jeżeli nastąpiło trzykrotne powtórzenie ruchu gra kończy się remisem.

        if(czy_trzy_powtorzenia(pobrany_ruch))
        {
            zakoncz_remis();
            return true;
        }

        // Wykonanie ruchu na planszy i dodanie go do listy ruchów.

        plansza->wykonaj_ruch(pobrany_ruch);
        lista_ruchow.push_back(pobrany_ruch);

        // Sprawdzenie czy po wykonaniu ruchu, któraś z figur gracza szachuje króla przeciwnika. Jeżeli tak program sprawdza czy istnieje
        // ruch obronny po wykonaniu ktorego zadna z figur nie szachuje krola. Jezeli nie gra konczy sie przez szach mat.

        if(plansza->czy_szach(aktualnygracz->sprawdz_kolor()))
        {
            if(plansza->czy_mach(aktualnygracz->sprawdz_kolor()))
            {
                zakoncz_wygrana();
                return true;
            }
        }

        // Pobranie nastepnego gracza i wyswietlenie informacji o poprawnym wykonaniu ruchu.

        nastepny_gracz();
        komunikat_gry = "Ruch poprawny";
        return true;

    } else {

        // Sprawdzenie czy dany rucj był biciem w przelocie. Jeżeli tak to zostanie od razu wykonany i metoda
        // zwróci wartość true do kontrolera.

        if(czy_en_passant(pobrany_ruch))
        {
            komunikat_gry = "Ruch poprawny";
            return true;
        }

        // Ustawienie odpowiedniego komunikatu bledu i przekazanie wartosci falsz do kontrolera - ruch ktory gracz probuje wykonac
        // nie jest poprawny i nie zostanie wykonany.

        komunikat_gry = plansza->podaj_komunikat();
        return false;
    }
}


Plansza *Gra_model::podaj_plansze()
{
    return plansza;
}



void Gra_model::nastepny_gracz()
{
    if(aktualnygracz->sprawdz_kolor() == "bialy")
        aktualnygracz = gracze[1];
    else {
        aktualnygracz = gracze[0];
    }
}

Gra_model::~Gra_model()
{
    for(size_t i = 0; i < lista_ruchow.size(); i++)
        delete lista_ruchow[i];
    delete plansza;
    delete gracze[0];
    delete gracze[1];
}

// Metoda sprawdzająca czy wystąpiło bicie w przelocie.

bool Gra_model::czy_en_passant(Ruch* do_sprawdzenia)
{
    // Jezeli lista ruchow jest pusta to bicie en passant jest niemozliwem a próba pobrania ruchu z pustej listy zakończyłaby się błędem.

    if(lista_ruchow.empty())
        return false;

    // Pobranie wskaznika do ostatniego ruchu z listy ruchow.

    Ruch* ostatni_ruch =  lista_ruchow.back();

    // Jezeli pole do którego próbuje się ruszyć pionek jest zajęte to bicie w przelocie nie jest mozliwe.
    if(do_sprawdzenia->podaj_koniec()->czy_zajety() == true)
        return false;

    // Sprawdzenie czy pole do ktorego probuje sie ruszyc gracz znajduje sie w odpowiednim polozeniu wzgledem pola koncowego
    // ostatniego ruchu przeciwnika w zaleznosci od koloru bierki: bialego jednego pola nad, czarnego jedenego pola pod.

    if(do_sprawdzenia->podaj_start()->kto_zajmuje()->podaj_kolor() == "bialy")
    {
        if(!((do_sprawdzenia->podaj_koniec()->podaj_rzad() == ostatni_ruch->podaj_koniec()->podaj_rzad()) &&
             (do_sprawdzenia->podaj_koniec()->podaj_kolumne()-1 == ostatni_ruch->podaj_koniec()->podaj_kolumne())) )
        {
            return false;
        }

    }
    else {
        if(!((do_sprawdzenia->podaj_koniec()->podaj_rzad() == ostatni_ruch->podaj_koniec()->podaj_rzad()) &&
             (do_sprawdzenia->podaj_koniec()->podaj_kolumne()+1 == ostatni_ruch->podaj_koniec()->podaj_kolumne())) )
        {
            return false;
        }

    }

    // Sprawdzenie czy pole z ktorego probuje sie ruszyc gracz znajduje sie w odpowiednim polozeniu wzgledem pola koncowego
    // ostatniego ruchu przeciwnika.

    if(!(((do_sprawdzenia->podaj_start()->podaj_rzad() == ostatni_ruch->podaj_koniec()->podaj_rzad()-1) ||
          (do_sprawdzenia->podaj_start()->podaj_rzad() == ostatni_ruch->podaj_koniec()->podaj_rzad()+1)) &&
          (do_sprawdzenia->podaj_start()->podaj_kolumne() == ostatni_ruch->podaj_koniec()->podaj_kolumne())) )
        return false;

    // Sprawdzenie przy pomocy dynamicznego rzutowania czy w poprzednim ruchu przeciwnik ruszył się pionkiem i czy był to ruch
    // o 2 pola.
    Pionek *wsk_bity_pionek;
    wsk_bity_pionek = dynamic_cast<Pionek*>(ostatni_ruch->podaj_koniec()->kto_zajmuje());
    if(wsk_bity_pionek == nullptr)
        return false;
    if(wsk_bity_pionek->czy_ruszono_o_2_pola() == false)
    {
        return false;
    }

    // Jeżeli funkcja dotarła do tego miejsca to bicie w przelocie jest poprawnie - nastepuje zbicie pionka przeciwnika
    // i przestawienie pionka aktualnego gracza w okreslone miejsce i pobranie nastepnego gracza.

    wsk_bity_pionek->zajmij_polozenie(nullptr);
    ostatni_ruch->podaj_koniec()->zwolnij();
    do_sprawdzenia->podaj_start()->kto_zajmuje()->zajmij_polozenie(do_sprawdzenia->podaj_koniec());
    do_sprawdzenia->podaj_koniec()->zajmij(do_sprawdzenia->podaj_start()->kto_zajmuje());
    do_sprawdzenia->podaj_start()->zwolnij();
    nastepny_gracz();

    return true;

}

bool Gra_model::czy_trzy_powtorzenia(Ruch *do_sprawdzenia)
{
    // Jeżeli lista jest pusta lub ma mniej niż 7 elementów to remis przez trzykrotne powtórzenie jest niemożliwy.
    if(lista_ruchow.empty())
        return false;
    if(lista_ruchow.size() < 7)
        return false;


    Pole* teraz= do_sprawdzenia->podaj_start();
    Pole* teraz_przeciwnik, *wczesniej_obecny_gracz,* wczesniej_przeciwnik;

    // Jeżeli trzykrotnie współrzędne pól początkowych ruchów każdego z graczy pokrywają się z polami końcowymi ich poprzednich ruchów to znaczy, że ruszają się tymi samymi
    // figurami i nastąpił remis przez trzykrotne powtórzenie.

    for(size_t i = 0; i < 2; i++)
    {
        if(i != 0)
            teraz = plansza->zlap_pole(lista_ruchow[lista_ruchow.size()-2*i]->podaj_kolumne_start(), lista_ruchow[lista_ruchow.size()-2*i]->podaj_rzad_start());
        teraz_przeciwnik = plansza->zlap_pole(lista_ruchow[lista_ruchow.size()-(2*i+1)]->podaj_kolumne_start(), lista_ruchow[lista_ruchow.size()-(2*i+1)]->podaj_rzad_start());
        wczesniej_obecny_gracz = plansza->zlap_pole(lista_ruchow[lista_ruchow.size()-2*(i+1)]->podaj_kolumne_koniec(), lista_ruchow[lista_ruchow.size()-2*(i+1)]->podaj_rzad_koniec());
        wczesniej_przeciwnik = plansza->zlap_pole(lista_ruchow[lista_ruchow.size()-(2*(i+1)+1)]->podaj_kolumne_koniec(), lista_ruchow[lista_ruchow.size()-(2*(i+1)+1)]->podaj_rzad_koniec());
        if((teraz != wczesniej_obecny_gracz) || (teraz_przeciwnik != wczesniej_przeciwnik))
            return false;

    }
    return true;
}



bool Gra_model::czy_poromowanie()
{
    // Jeżeli lista ruchów jest pusta to wypromowanie figury jest niemożliwe, róba pobrania ruchu z pustej listy zakończyłaby się błędem.

    if(lista_ruchow.empty())
        return false;

    Ruch* ostatni_ruch =  lista_ruchow.back();

    // Sprawdzenie czy figurą wykonującą ostatni ruch był pionek.

    Pionek* wsk = dynamic_cast<Pionek*>(ostatni_ruch->podaj_koniec()->kto_zajmuje());
    if(wsk == nullptr)
        return false;

    // Sprawdzenie czy pionek osiągnał odpowiednie pole, żeby być wypromowany

    if(wsk->podaj_kolor() == "bialy"  && ostatni_ruch->podaj_kolumne_koniec() == 7)
        return true;
    if(wsk->podaj_kolor() == "czarny" && ostatni_ruch->podaj_kolumne_koniec() == 0)
        return true;

    return false;
}

void Gra_model::promuj(char symbol_figury)
{
    Ruch* ostatni_ruch =  lista_ruchow.back();
    nastepny_gracz();
    plansza->promuj(symbol_figury, aktualnygracz->sprawdz_kolor(), ostatni_ruch);
    nastepny_gracz();
}



string Gra_model::podaj_komunikat()
{
    return komunikat_gry;
}

string Gra_model::aktualny_kolor()
{
    return aktualnygracz->sprawdz_kolor();
}

string Gra_model::wygeneruj_FEN()
{
    string kod_FEN;
    kod_FEN.append(plansza->zapisz_do_FEN(standard, aktualnygracz->sprawdz_kolor()));
    return kod_FEN;


}

void Gra_model::zakoncz_remis()
{
    komunikat_gry = "Remis!";
    for(size_t i = 0; i < lista_ruchow.size(); i++)
        delete lista_ruchow[i];
    inicializuj();
}

void Gra_model::ustaw_z_FEN(string FEN)
{
    if(plansza->ustaw_z_FEN(FEN, aktualnygracz->sprawdz_kolor()) == true)
        nastepny_gracz();
    lista_ruchow.clear();
}

vector<Ruch *> Gra_model::podaj_liste_ruchow()
{
    return lista_ruchow;
}



