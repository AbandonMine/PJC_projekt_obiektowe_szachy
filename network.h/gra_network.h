#ifndef GRA_NETWORK_H
#define GRA_NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <iostream>
using namespace std;

//! Klasa Gra_network
/*!
 * \brief Klasa odpowiadająca za obsługę funkcji sieciowych gry. Klasa pochodna klasy QObject.
 */
class Gra_network : public QObject
{
    Q_OBJECT

public:
//! Konstruktor klasy.
    /*!
     * \brief Konstruktor przekazuje parametry do konstruktora klasy bazowej.
     * \param parent wskaźnik do obiektu tworzącego daną instancję klasy.
     */
    explicit Gra_network(QObject *parent = nullptr);

//! Metoda pozwalająca na przesłanie ruchu drugiemu graczowi
    /*!
     * \brief Polecenie przesyłane jest za pomocą funkcji write klasy QTcpSocket
     * \param polecenie w formie zmiennej tekstowej, przekazywane dalej modelowi gry.
     */
    void przeslij_polecenie(string polecenie);

//! Metoda sprawdzająca czy instancja klasy została zainicjowania poprawnie.
    /*!
     * \return prawda jeżeli obiekt został zaincjowany poprawnie, fałsz w przeciwnym razie.
     */
    bool czy_stworzono();

signals:
//! Sygnał emitowany w momencie udanego połączenia.
    void polaczenie_udane();
//! Sygnał emitowany po odczytaniu przez QTcpSocket polecenia wysłanego przez drugiego gracza i przekazujący go do controlera.
    void wykonano_ruch(string);

public slots:
//! Slot obsługujący sygnał emitowany w momencie wykrycia możliwości odczytania polecenia z QTcpSocketu.
     void gdy_wykonano_ruch();

protected:
//! Zmienna przechowująca wskaźnik do socketa używanego do komunikacji przez sieć.
    QTcpSocket * socket;

//! Zmienna klasy QMessageBox pozwalająca na wyświetlenie infromacji o stanie połączenia.
    QMessageBox loading;

//! Zmienna przechowująca ostatnie odebrane polecenie.
    string polecenie;

//! Zmienna przechowująca informację o prawidłowości zainicjowania obiektu klasy.
    bool stworzono;
};


#endif // GRA_NETWORK_H

