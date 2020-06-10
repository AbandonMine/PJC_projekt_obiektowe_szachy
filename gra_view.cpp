#include "gra_view.h"

Gra_view::Gra_view()
{
    // Zaladowanie do pamieci obrazow figur w postaci plikow png

    obrazy_figur_bialych[0].load("figury/wieza.png");
    obrazy_figur_bialych[1].load("figury/skoczek.png");
    obrazy_figur_bialych[2].load("figury/goniec.png");
    obrazy_figur_bialych[3].load("figury/krolowa.png");
    obrazy_figur_bialych[4].load("figury/krol.png");
    obrazy_figur_bialych[5].load("figury/pionek.png");

    obrazy_figur_czarnych[0].load("figury/wieza_cz.png");
    obrazy_figur_czarnych[1].load("figury/skoczek_cz.png");
    obrazy_figur_czarnych[2].load("figury/goniec_cz.png");
    obrazy_figur_czarnych[3].load("figury/krolowa_cz.png");
    obrazy_figur_czarnych[4].load("figury/krol_cz.png");
    obrazy_figur_czarnych[5].load("figury/pionek_cz.png");
}

void Gra_view::wyswietl_figury(Plansza * plansza, MyLabel * plansza_widok, QLabel * zbite_biale, QLabel * zbite_czarne)
{
    // Przypisanie obiektow klasy QPainter odpowiedzialnej za rysowanie figur do odpowiednich obrazow

    QPainter malarz(&obraz_planszy), malarz_zbite_b(&obraz_zbite_biale), malarz_zbite_cz(&obraz_zbite_czarne);

    QImage miniatura;
    QPoint punkt;
    int marginesb = 0, marginescz = 0;

    // Przeszukanie planszy i wyswietlenie figur w zaleznosci od ich polozenia i typu.

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if(plansza->zlap_pole(i, j)->czy_zajety() == false)
                continue;

            punkt.setX(j*80);
            punkt.setY(obraz_planszy.height()-(i+1)*80);

            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'R')
                malarz.drawImage(punkt, obrazy_figur_bialych[0]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'N')
                malarz.drawImage(punkt, obrazy_figur_bialych[1]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'B')
                malarz.drawImage(punkt, obrazy_figur_bialych[2]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'Q')
                malarz.drawImage(punkt, obrazy_figur_bialych[3]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'K')
                malarz.drawImage(punkt, obrazy_figur_bialych[4]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'P')
                malarz.drawImage(punkt, obrazy_figur_bialych[5]);

            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'r')
                malarz.drawImage(punkt, obrazy_figur_czarnych[0]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'n')
                malarz.drawImage(punkt, obrazy_figur_czarnych[1]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'b')
                malarz.drawImage(punkt, obrazy_figur_czarnych[2]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'q')
                malarz.drawImage(punkt, obrazy_figur_czarnych[3]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'k')
                malarz.drawImage(punkt, obrazy_figur_czarnych[4]);
            if(plansza->zlap_pole(i, j)->kto_zajmuje()->podaj_symbol() == 'p')
                malarz.drawImage(punkt, obrazy_figur_czarnych[5]);

        }

    //Jeżeli lista zbitych figur nie jest pusta, to obrazy zbitych figur sa przeskalowane i narysowane na odpowiednim pasku

    if(!plansza->podaj_zbite_figury().empty())
    {
        for(size_t i = 0; i < plansza->podaj_zbite_figury().size(); i++)
        {
            if(plansza->podaj_zbite_figury()[i]->podaj_kolor() == "bialy")
            {
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'R')
                {
                    miniatura = obrazy_figur_bialych[0].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_bialych[0].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'N')
                {
                    miniatura = obrazy_figur_bialych[1].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_bialych[1].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'B')
                {
                    miniatura = obrazy_figur_bialych[2].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_bialych[2].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'Q')
                {
                    miniatura = obrazy_figur_bialych[3].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_bialych[3].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'K')
                {
                    miniatura = obrazy_figur_bialych[4].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_bialych[4].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'P')
                {
                    miniatura = obrazy_figur_bialych[5].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_bialych[5].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                punkt.setX(marginesb*20);
                punkt.setY(0);
                malarz_zbite_b.drawImage(punkt, miniatura);
                marginesb++;
            } else {
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'r')
                {
                    miniatura = obrazy_figur_czarnych[0].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_czarnych[0].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'n')
                {
                    miniatura = obrazy_figur_czarnych[1].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_czarnych[1].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'b')
                {
                    miniatura = obrazy_figur_czarnych[2].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_czarnych[2].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'q')
                {
                    miniatura = obrazy_figur_czarnych[3].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_czarnych[3].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'k')
                {
                    miniatura = obrazy_figur_czarnych[4].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_czarnych[4].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                if(plansza->podaj_zbite_figury()[i]->podaj_symbol() == 'p')
                {
                    miniatura = obrazy_figur_czarnych[5].scaledToWidth(20,  Qt::TransformationMode::FastTransformation);
                    miniatura = obrazy_figur_czarnych[5].scaledToHeight(20, Qt::TransformationMode::FastTransformation);
                }
                punkt.setX(marginescz*20);
                punkt.setY(0);
                malarz_zbite_cz.drawImage(punkt, miniatura);
                marginescz++;
            }

        }
    }

    //Ustawienie zmodyfikowanych obrazow w GUI

    plansza_widok->setPixmap(obraz_planszy);
    zbite_biale->setPixmap(obraz_zbite_biale);
    zbite_czarne->setPixmap(obraz_zbite_czarne);
}



void Gra_view::wyswietl_liste(QListWidget *lista, vector<Ruch *> lista_ruchow)
{
    // Wyczyszczenie i jezeli lista ruchow nie jest pusta, dodanie elementow do listy - widgetu w ui.

    lista->clear();
    if(lista_ruchow.empty())
        return;
    for(size_t i = 0; i < lista_ruchow.size(); i++)
    {
        lista->addItem("Ruch nr. " + QString::number(i+1) + ": " + QString::fromStdString(lista_ruchow[i]->podaj_etykiete()));
    }
}


void Gra_view::wyswietl_plansze(MyLabel *plansza)
{
    // Ponieważ po wykonaniu ruchu figury są rysowane na planszy, to aby móc poprawnie wyświetlić planszę jej pusta wersja musi zostać
    // ponownie załadowana do pamięci programu na początku tego procesu.

    obraz_planszy.detach();
    obraz_planszy.load("plansza.png");
    obraz_zbite_biale.load("pasek_cz.png");
    obraz_zbite_czarne.load("pasek.png");
    plansza->setPixmap(obraz_planszy);
}

Gra_view::~Gra_view()
{
}
