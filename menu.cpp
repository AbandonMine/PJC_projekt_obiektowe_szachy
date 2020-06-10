#include "menu.h"
#include "ui_menu.h"
#include "gra_control.h"
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    czy_standard = true;
    czy_internet = false;
    czy_komputer = true;
    czy_host = true;
}

Menu::~Menu()
{
    delete ui;
}
void Menu::on_tryb_960_in_clicked()
{
    czy_standard = false;
    ui->tryb_960_in->setChecked(true);
}

void Menu::on_tryb_klasyczny_in_clicked()
{
    czy_standard = true;
    ui->tryb_klasyczny_in->setChecked(true);
}

void Menu::on_wybor_rozgrywki_currentIndexChanged(int index)
{
    // W przypadku wybrania gry przez internet aktywowane są pola odpowiedzialne za pobranie od
    // uzytkownika adresu ip i numeru portu oraz wyboru czy chce hostowac czy dolaczyc do rozgrywki.
    // Dezaktywowane jest za to pole wyboru gry w trybie rozgrywki 96- gdyż nie został on przewidziany
    // dla trybu sieciowego. W przypadku wybrania innego trybu gry te pola są dezaktywowane, pole wyboru
    // trybu 96- jest aktywowane. Wyczszczone zostają również wpisane przez użytkownika infromację
    // w polach tekstowych.

    if(index == 0)
    {
        czy_internet = false;
        czy_komputer = true;
        ip_podane.clear();
        port_podane.clear();
        ui->ip_in->clear();
        ui->port_in->clear();
        ui->ip_in->setEnabled(false);
        ui->ip_text->setEnabled(false);
        ui->port_in->setEnabled(false);
        ui->port_text->setEnabled(false);
        ui->wybor_net->setEnabled(false);
        ui->tryb_960_in->setEnabled(true);
    }
    if(index == 1)
    {
        czy_internet = false;
        czy_komputer = false;
        ip_podane.clear();
        port_podane.clear();
        ui->ip_in->clear();
        ui->port_in->clear();
        ui->ip_in->setEnabled(false);
        ui->ip_text->setEnabled(false);
        ui->port_in->setEnabled(false);
        ui->port_text->setEnabled(false);
        ui->wybor_net->setEnabled(false);
        ui->tryb_960_in->setEnabled(true);

    }
    if(index == 2)
    {
        czy_internet = true;
        czy_komputer = false;
        ui->ip_in->setEnabled(true);
        ui->ip_text->setEnabled(true);
        ui->port_in->setEnabled(true);
        ui->port_text->setEnabled(true);
        ui->wybor_net->setEnabled(true);
        on_tryb_klasyczny_in_clicked();
        ui->tryb_960_in->setEnabled(false);
    }
}

void Menu::on_rozpocznij_gre_clicked()
{
    Gra_control* obsluga_gry;
    obsluga_gry = new Gra_control(nullptr, czy_standard, czy_komputer, czy_internet, czy_host, ip_podane, port_podane);
    obsluga_gry->show();
    this->close();
}

void Menu::on_ip_in_textChanged()
{
    ip_podane = ui->ip_in->toPlainText().toStdString();
}

void Menu::on_port_in_textChanged()
{
    port_podane = ui->port_in->toPlainText().toStdString();
}

void Menu::on_exit_button_clicked()
{
    this->close();
}


void Menu::on_wybor_net_currentIndexChanged(int index)
{
    if(index == 0)
        czy_host = true;
    else {
        czy_host = false;
    }
}

