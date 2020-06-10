#ifndef PLANSZA_H
#define PLANSZA_H

#include "figury.h/krol.h"
#include "figury.h/krolowa.h"
#include "figury.h/goniec.h"
#include "figury.h/skoczek.h"
#include "figury.h/wieza.h"
#include "figury.h/pionek.h"
#include "pole.h"

#include <vector>

class Ruch;

//! Klasa Plansza
/*!
 * \brief Klasa implementująca szachownicę.
 */
class Plansza
{
public:
//! Konstruktor klasy.
    /*!
     * \brief Następuje w nim zalokowanie pamięci na wszystkie pola i figury wchodzące w skład planszy.
     */
    Plansza();

//! Metoda przypisująca figurom pola według standardowej pozycji startowej w szachach klasycznych.
    void przypisz_standard();

//! Metoda przypisująca figurom pola startowe według zasady algorytmu 960.
    void przypisz_960();



//! Metoda pozwalająca uzyskać dostęp do danego pola po podaniu jego rzędu oraz kolumny.
    Pole* zlap_pole(int kolumna, int rzad);

//! Metoda pozwalająca na wypromowanie figury.
    /*!
     * \param symbol_figury symbol figury na którą wypromowono pionek.
     * \param kolor zmienna przekazująca kolor gracza który dokonał promocji.
     * \param ostatni_ruch wskaźnik na ostatni wykonany ruch (pozwalający określić położenie wypromowanej figury)
     */
    void promuj(char symbol_figury, string kolor, Ruch* ostatni_ruch);

//! Metoda sprawdzająca poprawność wykonanego ruchu.
    /*!
     * \param do_sprawdzenia wskaźnik na ruch, który ma zostać sprawdzony.
     * \param kolor zmienna przekazująca kolor aktualnego gracza.
     * \return zwracana jest prawda jeżeli ruchu jest poprawny, fałsz w przeciwnym razie.
     */
    bool sprawdz_poprawnosc_ruchu(Ruch *do_sprawdzenia, string kolor);

//! Metoda sprawdzająca czy po ruchu gracza nastąpił szach.
    /*!
     * \brief Sprawdzane jest czy dowolna figura aktualnego gracza może legalnie ruszyć się do pozycji zajmowanej przez przeciwnego króla.
     * \param kolor zmienna przekazująca kolor aktualnego gracza.
     * \return zwracana jest prawda jeżeli wystąpił szach, w przeciwnym wypadku fałsz.
     */
    bool czy_szach(string kolor);

//! Metoda sprawdzająca czy po ruchu gracza nastąpił szach mat.
    /*!
     * \brief Sprawdzane jest czy istnieje ruch bierki gracza przeciwnego koloru, po którym nie wystąpi szach.
     * \param kolor zmienna przekazująca kolor aktualnego gracza.
     * \return zwracana jest prawda jeżeli wystąpił szach mat, w przeciwnym wypadku fałsz.
     */
    bool czy_mach(string kolor);

//! Metoda wykonująca ruch.
    /*!
     * W metodzie nie jest sprawdzana poprawność wykonanego ruchu.
     * \param do_wykonania wskaźnik do wykonywanego ruchu.
     */
    void wykonaj_ruch(Ruch* do_wykonania);


//! Metoda zwracająca komunikat o poprawności wykonanego ruchu w postaci zmiennej tekstowej.
    string podaj_komunikat();

//! Metoda zwracająca wektor wskaźników do zbitych figur
    /*!
     * \brief Używana jedynie przy tworzeniu pasków zbitych figur w GUI.
     */
    vector<Figura*> podaj_zbite_figury();

//! Metoda zapisująca pozycję znajdującą się na planszy do kodu FEN.
    /*!
     * \param standard infromacja czy gra rozgrywała się z pozycji standardowej czy 960.
     * \param kolor zmienna przekazująca kolor aktualnego gracza.
     * \return zwracany jest kod FEN w postaci zmiennej tekstowej.
     */
    string zapisz_do_FEN(bool standard, string kolor);

//! metoda wczytująca pozycję na planszy z kodu FEN.
    /*!
     * \param FEN kod FEN z którego wczytywana jest pozycja w postaci zmiennej tekstowej.
     * \param kolor zmienna przekazująca kolor aktualnego gracza.
     * \return zwracana jest prawda jeżeli konieczna jest zmiana aktualnego gracza, fałsz w przeciwym przypadku.
     */
    bool ustaw_z_FEN(string FEN, string kolor);

//! Destruktor klasy.
    ~Plansza();

private:

//! Metoda sprawdzająca czy pola znajdujące się w kolumnie między polem startowym i końcowym są wolne.
    /*!
     * \param odkad wskaźnik na pole startowe.
     * \param dokad wskaźnik na pole końcowe.
     * \return zwracana jest prawda jeżeli kolumna pomiędzy polami jest wolna, fałsz w przeciwnym razie.
     */
    bool czy_kolumna_wolna(Pole* odkad, Pole* dokad);

//! Metoda sprawdzająca czy pola znajdujące się w rzędzie między polem startowym i końcowym są wolne.
    /*!
    * \param odkad wskaźnik na pole startowe.
    * \param dokad wskaźnik na pole końcowe.
    * \return zwracana jest prawda jeżeli rząd pomiędzy polami jest wolny, fałsz w przeciwnym razie.
    */
    bool czy_rzad_wolny(Pole* odkad, Pole* dokad);

//! Metoda sprawdzająca czy pola znajdujące się na przękatnej między polem startowym i końcowym są wolne.
     /*!
    * \param odkad wskaźnik na pole startowe.
    * \param dokad wskaźnik na pole końcowe.
    * \return zwracana jest prawda jeżeli przekątna pomiędzy polami jest wolna, fałsz w przeciwnym razie.
    */
    bool czy_przekatna_wolna(Pole* odkad, Pole* dokad);

//! Metoda sprawdzająca czy po wykonaniu danego ruchu, któraś z figur przeciwnika będzie szachować króla gracza.
    /*!
     * \param do_sprawdzenia wskaźnik do sprawdzanego ruchu.
     * \param kolor zmienna przekazująca kolor aktualnego gracza.
     * \return zwracana jest prawda jeżeli po ruchu wystąpi szach, w przeciwnym razie fałsz.
     */
    bool czy_szach_po_ruchu(Ruch *do_sprawdzenia, string kolor);

//! Metoda sprawdzająca poprawność ruchu obronnego.
    /*!
     * \brief Metoda wykorzystywana przy sprawdzaniu mata.
     * \param do_sprawdzenia wskaźnik do sprawdzanego ruchu obronnego.
     * \return zwracana jest prawda jeżeli ruch obronny jest poprawny, fałsz w przeciwnym przypadku.
     */
    bool sprawdz_poprawnosc_obrony(Ruch *do_sprawdzenia);

//! Metoda używana do zamiany figury w liście figur
    /*!
     * \brief Metoda wykorzystywana przy modyfikacji listy figur w przypadku promocji.
     * \param zamieniana wskaźnik do zamienianej figury.
     * \param zamiennik  wskaźnik do figury będącej zamiennikiem.
     * \param kolor zmienna przekazująca kolor aktualnego gracza.
     */
    void zamien_figury(Figura *zamieniana, Figura* zamiennik, string kolor);

//! Stała zmienna przechowująca wymiar tablicy.
    static const int wymiar = 8;
//! stała zmienna przechowująca startową liczbę figur.
    static const int startowa_liczba_figur = wymiar*2;

//! Dwuwymiarowa tablica wskaźników na pola szachownicy.
    Pole * pola[wymiar][wymiar];

//! Tablicy wskaźników na figury białe.
    Figura * figury_biale [startowa_liczba_figur];

//! Tablicy wskaźników na figury czarne.
    Figura * figury_czarne[startowa_liczba_figur];

//! Wektor wskaźników na figury, które zostały zbite w trakcie trwania partii.
    vector<Figura*> zbite_figury;

//! Zmienna tekstowa przechowująca komunikat o poprawności wykonywanego ruchu.
    string komunikat;

};


#endif // PLANSZA_H
