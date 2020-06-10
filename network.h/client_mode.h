#ifndef CLIENT_MODE_H
#define CLIENT_MODE_H
#include "gra_network.h"

//! Klasa Client_mode
/*!
 * \brief Klasa odpowiedzialna za komunikację sieciową jako klient. Klasa pochodna klasy Gra_network.
 */
class Client_mode : public Gra_network
{
    Q_OBJECT

public:
//! Konstruktor klasy.
    /*!
    * \brief Konstruktor tworzący zmienną klasy QTcpSocket i próbuje dołączyć do sewrera z podanym adresem ip i numeru portu.
    * \param parent wskaźnik do obiektu-rodzica przekazywany do konstruktora klasy bazowej.
    * \param ip   numer ip serwera do którego będzie próbował dołączyć klient.
    * \param port numer portu serwera do którego będzie próbował dołączyć klient.
    */
    explicit Client_mode(QObject *parent = nullptr, string ip = "127.0.0.1", string port = "80");

//! Destruktor klasy.
    ~Client_mode();

private:

};
#endif // CLIENT_MODE_H
