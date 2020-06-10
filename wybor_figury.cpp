#include "wybor_figury.h"
#include "ui_wybor_figury.h"

Wybor_figury::Wybor_figury(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Wybor_figury)
{
    ui->setupUi(this);
    symbol_figury = 'q';
}

void Wybor_figury::on_ktora_figura_currentIndexChanged(int index)
{
    if(index == 0)
        symbol_figury = 'q';
    if(index == 1)
        symbol_figury = 'b';
    if(index == 2)
        symbol_figury = 'n';
    if(index == 3)
        symbol_figury = 'r';
}

void Wybor_figury::on_zatwierdzono_clicked()
{
    emit wybrano_figury(symbol_figury);
    this->close();
}

Wybor_figury::~Wybor_figury()
{
    delete ui;
}
