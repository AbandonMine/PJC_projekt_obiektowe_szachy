#ifndef GRA_MODEL_H
#define GRA_MODEL_H

#include "plansza.h"
#include "pole.h"
#include "ludzkigracz.h"
#include "silnikszachowy.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//! Klasa Gra_model
/*!
 * \brief Klasa odpowiadająca za implementacje modelu we wzorcu MVC.
 */
class Gra_model
{
public:

//! Konstruktor klasy.
    /*!
     * \brief W konstruktorze odbywa się utworzenie obiektu klasy Plansza.
     * \param czy_standard infromacja czy gra będzie rozgrywała się z pozycji standardowej czy 960.
     * \param czy_internet informacja czy gra rozgrywa się lokalnie czy przez internet.
     * \param czy_komputer informacja czy gra rozgrywa się między graczami czy z silnikiem szachowym.
     * \param czy_host     informacja czy gracz jest hostem rozgrywki w wypadku gry przez internet.
     */
    Gra_model(bool czy_standard, bool czy_internet, bool czy_komputer, bool czy_host);

//! Metoda inicjalzująca grę - przypisująca figury do planszy i tworząca graczy według przekazanych parametrów czy_komputer i czy_standard.
    void inicializuj();



//! Metoda obslugująca ruch zawarty w poleceniu.
    /*!
     * \brief  Metoda sprawdza poprawność ruchu zawartego w poleceniu oraz wykonująca go jeżeli jest poprawny.
     * \param  polecenie opis zawierający pole startowe i końcowe w standardowej notacji szachowej.
     * \return zwraca prawdę jeżeli ruch został uznany za poprawny i wykonany, w przeciwnym razie zwraca fałsz.
     */
    bool obsluz_ruch(string polecenie);

//! Metoda ustawiająca wskaźnik zmiennej aktualnygracz na następnego gracza.
    void nastepny_gracz();



//! Metoda sprawdzająca czy wykonany ruch spowodował promowanie figury
    /*!
     * \brief Metoda konieczna w celu wywołania menu wyboru figury w momencie jej poromowania.
     * \return zwraca prawdę jeżeli wystapi promowanie, w przeciwnym razie fałsz.
     */
    bool czy_poromowanie();

//! Metoda dokonująca wypromowania figury po wybraniu typu bierki (jej symbolu) w menu wyboru figury.
    /*!
     * \param symbol_figury symbol wybranej w menu wyboru figury.
     */
    void promuj(char symbol_figury);



//! Metoda zwracająca kolor aktualnego gracza w postaci zmiennej tekstowej.
    string aktualny_kolor();

//! Metoda zwracająca komunikat o poprawności wykonywanego ruchu w postaci zmiennej tektowej.
    string podaj_komunikat();

//! Metoda zwracająca wektor wskaźników na wykonane ruchy.
    /*!
     * \brief Wykorzystywany przy wyświeltaniu listy ruchów w postaci widgetu.
     */
    vector<Ruch*> podaj_liste_ruchow();

//! Metoda zwracająca wskaźnik na planszę.
    /*!
     * \brief Wykorzystywana jedynie przy wyświetlaniu planszy.
     */
    Plansza* podaj_plansze();



//! Metoda ustawiająca pozycję w grze na podstawie kodu FEN.
    /*!
     * \param FEN kod FEN z którego odczytywana jest pozycja w postaci zmiennej tekstowej.
     */
    void ustaw_z_FEN(string FEN);

//! Metoda generująca i zwracająca kod FEN w postaci zmiennej tekstowej.
    string wygeneruj_FEN();



//! Metoda kończąca grę w przypadku gdy gracze zremisowali.
    /*!
    * \brief Następuje wyświeltenie odpowiedniego komunikatu i ponowne zainicjowanie gry.
    */
    void zakoncz_remis();

//! Metoda kończąca grę w przypadku gdy któryś z graczy wygrał rozgrywkę.
    /*!
     * \brief Następuje wyświeltenie odpowiedniego komunikatu i ponowne zainicjowanie gry.
     */
    void zakoncz_wygrana();

//! Destrukor klasy.
    ~Gra_model();

private:

//! Metoda spradzająca czy po wykonaniu ruchu wystąpi remis przez trzykrotne powtórzenie ruchu.
    /*!
     * \param do_sprawdzenia sprawdzany ruch po wykonaniu którego może wystąpić trzykrotne powtórzenie.
     * \return prawda jeżeli wystąpiły trzy powtórzenia, w przeciwnym wypadku fałsz.
     */
    bool czy_trzy_powtorzenia(Ruch* do_sprawdzenia);

//! Metoda sprawdzająca czy wykonany ruch jest biciem en passant - biciem w przelocie.
    /*!
     * \brief W przypadku poprawnego bicia, metoda je wykonuje.
     * \param do_sprawdzenia sprawdzany ruch.
     * \return zwracana jest prawda jeżeli poprawnie wykonano bicie w przelociem, fałsz jeżeli bicie jest niepoprawne lub ruch nie jest biciem w przelocie.
     */
    bool czy_en_passant(Ruch* do_sprawdzenia);

//! Stała wartość określająca dopuszczalną liczbę graczy.
    static const int liczba_graczy = 2;

//! Zmienna przechowująca tablicę wskaźników do graczy biorących udział w rozgrywce.
    Gracz *gracze[liczba_graczy];

//! Zmienna przechowująca wskaźnik do aktualnego gracza.
    Gracz * aktualnygracz;

//! Zmienna przechowująca wskaźnik do planszy.
    Plansza *plansza;

//! Zmienna przechowująca listę wskaźników do wykonanych do tej pory ruchów w postaci wektora.
    vector<Ruch*> lista_ruchow;

//! Zmienna przechowująca ostatni komunikat.
    string komunikat_gry;

//! Zmienna przechowująca infromację czy gra będzie rozgrywała się z pozycji standardowej czy 960.
    bool standard;

//! Zmienna przechowująca informację czy gra rozgrywa się lokalnie czy przez internet.
    bool internet;

//! Zmienna przechowująca informację czy gra rozgrywa się lokalnie czy przez internet.
    bool komputer;

//! Zmienna przechowująca informację  gracz jest hostem rozgrywki w wypadku gry przez internet.
    bool host;

};

#endif // GRA_MODEL_H
