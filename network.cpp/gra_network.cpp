#include "network.h/gra_network.h"



Gra_network::Gra_network(QObject *parent) : QObject (parent)
{
    stworzono = false;
}

//metoda przesylajaca polecenie poprzez socket.

void Gra_network::przeslij_polecenie(string polecenie)
{
    socket->write(polecenie.c_str(), polecenie.size());
    socket->flush();
    socket->waitForBytesWritten(2000);
}

bool Gra_network::czy_stworzono()
{
    return stworzono;
}

//slot odczytujacy polecenie z socektu i przesylajacy je do kontrolera.

void Gra_network::gdy_wykonano_ruch()
{
    socket->waitForReadyRead(2000);
    QByteArray array = socket->readAll();
    string polecenie = array.toStdString();
    emit wykonano_ruch(polecenie);
}


