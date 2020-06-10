#include "network.h/server_mode.h"

Server_mode::Server_mode(QObject *parent, string ip, string port) : Gra_network(parent)
{
    // Utworzenia serwera i polaczenie sygnalu emitowanego przy probie dolaczenia do serwera
    // przez klienta ze slotem obslugujacym te sytuacje.

    serwer = new QTcpServer(this);
    connect(serwer, SIGNAL(newConnection()), this, SLOT(ustanowienie_polaczenia()));

    // Próba zahostowania gry pod określonym adresem ip i numerem portu. W przypadku powodzenia
    // wyswietlany jest komunikat o oczekiwaniu na dolaczenie drugiego gracza.

    QHostAddress adres;
    adres.setAddress(QString::fromStdString(ip));
    int numer_portu = stoi(port);
    if(!serwer->listen(adres, quint16(numer_portu)))
    {
        stworzono = false;
        return;
    } else{
        loading.setText("Lobby utworzone, oczekuje na dolaczenie przeciwnika" );
        loading.show();
        stworzono = true;
    }
}

Server_mode::~Server_mode()
{
    socket->close();
    delete serwer;
}

// Slot obslugujacy probe dolaczenia do serwera.

void Server_mode::ustanowienie_polaczenia()
{
    // Dolaczenie przychodzacego polaczenia z serwera do socket, a następnie dołączenie sygnału
    // emitowanego przez ten socekt przy otrzymaniu danych do slotu odpowiedzalnego za ich
    // obsluge.

    socket = serwer->nextPendingConnection();
    connect(socket, &QTcpSocket::readyRead, this, &Gra_network::gdy_wykonano_ruch);
    loading.close();

    //Wymietowanie sygnalu do kontrolera o poprawnym dolaczeniu drugiego gracza.

    emit polaczenie_udane();
}
