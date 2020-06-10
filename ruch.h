#ifndef RUCH_H
#define RUCH_H

#include "plansza.h"
#include <iostream>
using namespace std;

//! Klasa będacą implementacją ruchu wykonanego w grze.
class Ruch
{
public:
    Ruch() = delete;
//! Pierwszy konstruktor klasy.
    /*!
     * \brief Konstruktor tworzący obiekt przy podaniu wskaźnika do planszy oraz współrzędnych pól: startowego i końcowego.
     * \param skad_rzad     zmienna przekazująca numer rzędu pola startowego.
     * \param skad_kolumna  zmienna przekazująca numer kolumny pola startowego.
     * \param dokad_rzad    zmienna przekazująca numer rzędu pola końcowego.
     * \param dokad_kolumna zmienna przekazująca numer kolumny pola końcowego.
     * \param plansza       wskaźnik do planszy.
     */
    Ruch(int skad_rzad, int skad_kolumna, int dokad_rzad, int dokad_kolumna, Plansza* plansza);

//! Drugi konstruktor klasy/
    /*!
     * \brief Tworzy obiekt przy podaniu wskaźników do pól planszy: startowego i końcowego.
     * \param skad  wskaźnik do pola startowego.
     * \param dokad wskaźnik do pola końcowego.
     */
    Ruch(Pole* skad, Pole* dokad);

//! Metoda zwracająca wskaźnik do pola startowego.
    Pole* podaj_start();

//! Metoda zwracająca wskaźnik do pola końcowego.
    Pole* podaj_koniec();

//! Metoda zwracająca numer rzędu pola startowego.
    int podaj_rzad_start();

//! Metoda zwracająca numer kolumny pola startowego.
    int podaj_kolumne_start();

//! Metoda zwracająca numer rzędu pola końcowego.
    int podaj_rzad_koniec();

//! Metoda zwracająca numer kolumny pola końcowego.
    int podaj_kolumne_koniec();

//! Metoda sprawdzająca czy dany ruch jest roszadą.
    bool czy_roszada();

//! Metoda zwracająca w postaci zmiennej tekstowej ruch zapisany w notacji szachowej.
    string podaj_etykiete();

//! Metoda ustawiająca etykietę.
    void ustaw_etykiete(string etykieta_podana);

private:

//! Zmienna przechowująca wskaźnik do pola startowego.
    Pole* start;

//! Zmienna przechowująca wskaźnik do pola końcowego.
    Pole* koniec;

//! Zmienna przechowująca numer rzędu pola startowego.
    int rzad_s;

 //! Zmienna przechowująca numer kolumny pola startowego.
    int kolumna_s;

//! Zmienna przechowująca numer rzędu pola końcowego.
    int rzad_k;

//! Zmienna przechowująca numer kolumny pola końcowego.
    int kolumna_k;

//! Zmienna tekstowa przechowująca ruch zapisany w notacji szachowej.
    string etykieta;

};

#endif // RUCH_H
