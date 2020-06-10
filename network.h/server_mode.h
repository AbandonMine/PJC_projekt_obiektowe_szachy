#ifndef SERVER_MODE_H
#define SERVER_MODE_H
#include "gra_network.h"

//! Klasa odpowiedzialna za komunikację sieciową jako serwer.
class Server_mode : public Gra_network
{
    Q_OBJECT

public:
//! Konstruktor klasy.
    /*!
     * \brief Konstruktor tworzący zmienną klasy QTcpServer i łączy ją z podanym adresem ip i numerem portu. Wyswietla wiadomosc o oczekiwaniu na dołączenie przeciwnika.
     * \param parent wskaźnik do obiektu-rodzica przekazywany do konstruktora klasy bazowej.
     * \param ip   numer ip dla którego zostanie postawiony serwer.
     * \param port numer portu dla którego zostanie postawiony serwer.
     */
    explicit Server_mode(QObject *parent = nullptr, string ip = "127.0.0.1", string port = "80");

//! Destruktor klasy.
    ~Server_mode();

public slots:
//! Slot odpowiadający za obsługę dołączenia klienta do serwera - podpięcie go do odpowiedniego socketu z funkcji bazowej.
    void ustanowienie_polaczenia();

private:
//! Zmienna przechowująca wskaźnik do utworzonego serwera.
    QTcpServer * serwer;

};

#endif // SERVER_MODE_H
