#include "network.h/client_mode.h"

Client_mode::Client_mode(QObject *parent, string ip, string port) : Gra_network(parent)
{
    //Utworzenie socketu i próba dołączenia do danego adresu ip i numeru portu hosta.

    socket = new QTcpSocket(this);
    socket->connectToHost(QString::fromStdString(ip), quint16(stoi(port)));

    // Sprawdzenie czy się udało dołączyć. W przypadku pozytywnym dołączenie sygnału
    // emitowanego przez socekt przy otrzymaniu danych do slotu odpowiedzalnego za ich
    // obsluge.

    if(socket->waitForConnected(3000))
    {
        connect(socket, &QTcpSocket::readyRead, this, &Gra_network::gdy_wykonano_ruch);
        stworzono = true;
    } else {
        stworzono = false;
    }
}

Client_mode::~Client_mode()
{
    socket->close();
    delete socket;
}
