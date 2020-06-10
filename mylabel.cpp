#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) : QLabel (parent)
{
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    emit on_wcisniecie_myszy(event->x(), event->y());
}

void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    emit on_zwolnienie_myszy(event->x(), event->y());
}
