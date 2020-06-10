#include "wczytanie_fen.h"
#include "ui_wczytanie_fen.h"

Wczytanie_fen::Wczytanie_fen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wczytanie_fen)
{
    ui->setupUi(this);
    kod_FEN = "";
}

Wczytanie_fen::~Wczytanie_fen()
{
    delete ui;
}

void Wczytanie_fen::on_buttonBox_accepted()
{
    emit wpisano_fen(kod_FEN);
    this->close();
}

void Wczytanie_fen::on_buttonBox_rejected()
{
    this->close();
}

void Wczytanie_fen::on_kod_FEN_in_textChanged()
{
    kod_FEN = ui->kod_FEN_in->toPlainText().toStdString();
}
