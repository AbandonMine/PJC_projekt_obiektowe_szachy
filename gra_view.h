#ifndef GRA_VIEW_H
#define GRA_VIEW_H

#include "gra_model.h"
#include "mylabel.h"
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPoint>
#include <QListWidget>


//! Klasa odpowiadająca za implementacje widoku we wzorcu MVC.

class Gra_view
{
public:
//! Konstruktor klasy.
    /*!
     * \brief Wgrywa do pamięci obrazy wszystkich figur z plików png.
     */
    Gra_view();

//! Metoda wyświetlający planszę.
    /*!
     * \brief Metoda załadowuje do pamięci programu obraz szachownicy w postaci pliku png, a następnie wyświetla go w GUI przy użyciu klasy MyLabel.
     * \param plansza_widok wskaźnik do obiektu klasy MyLabel odpowiedzialnego za wyświetlanie planszy w GUI.
     */
    void wyswietl_plansze(MyLabel * plansza_widok);

//! Metoda odpowiadająca za wyświetlenie figur na planszy.
    /*!
     * \brief Wyswietlenie figur na planszy i paskach następuje poprzez narysowanie ich przy pomocy klasy QPainter.
     * \param plansza wskaźnik do planszy na podstawie którego odcztywane są informację o położeniu figur.
     * \param plansza_widok wskaźnik do widgetu odpowiedzialnego za wyświetlanie planszy w GUI.
     * \param zbite_biale  wskaźnik do obiekty odpowiedzialnego za wyświeltanie paska ze zbitymi białymi figurami.
     * \param zbite_czarne wskaźnik do obiekty odpowiedzialnego za wyświeltanie paska ze zbitymi czarnymi figurami.
     */
    void wyswietl_figury(Plansza* plansza, MyLabel * plansza_widok, QLabel * zbite_biale, QLabel * zbite_czarne);

//! Metoda wyświetlająca listę ruchów w postaci widgetu QListWidget
    /*!
     * \param lista wskaźnik do obiektu wyświetlającego listę w GUI.
     * \param lista_ruchow wskaźnik do listy wykonanych ruchów na podstawie, których wypełniany jest widget.
     */
    void wyswietl_liste(QListWidget* lista, vector<Ruch*> lista_ruchow);

//! Destruktor klasy.
    ~Gra_view();

private:

//! Zmienna przechowująca załadowane do pamięci obrazy figur białych w postaci tablicy obiektów klasy QImage.
    QImage obrazy_figur_bialych[6];

//! Zmienna przechowująca załadowane do pamięci obrazy figur czarnych w postaci tablicy obiektów klasy QImage.
    QImage obrazy_figur_czarnych[6];

//! Zmienna przechowująca obecny obraz planszy w postaci obiektu klasy QPixmap.
    QPixmap obraz_planszy;

//! Zmienna przechowująca obraz paska zbitych figur koloru białego.
    QPixmap obraz_zbite_biale;

//! Zmienna przechowująca obraz paska zbitych figur koloru czarnego.
    QPixmap obraz_zbite_czarne;
};

#endif // GRA_VIEW_H
