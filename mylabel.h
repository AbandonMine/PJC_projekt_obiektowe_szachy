#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>

//! Klasa MyLabel
/*!
 * \brief Klasa odpowiedzialana za wyświetlanie w gui planszy oraz śledzenie akcji myszki w jej obrębie. Klasa pochodna klasy QLabel.
 */
class MyLabel : public QLabel
{
    Q_OBJECT
public:

//! Konstruktor klasy.
    /*!
     * \param parent wskaźnik na obiekt-rodzica przekazywany do konstruktora klasy bazowej.
     */
    explicit MyLabel(QWidget *parent);

//! Implementacja metody wirtualnej obsługująca wciśnięcie przycisku myszy w obrębie planszy.
void mousePressEvent(QMouseEvent *event) override;

//! Implementacja metody wirtualnej obsługująca zwolnienie przycisku myszy w obrębie planszy.
void mouseReleaseEvent(QMouseEvent *event) override;

signals:

//! sygnał wysyłający infromację o położeniu myszy w momencie wciśnięcia jej przycisku.
    void on_wcisniecie_myszy(double, double);
//! sygnał wysyłający informację o położeniu myszy w momencie zwolnienia jej przycisku.
    void on_zwolnienie_myszy(double, double);

};

#endif // MYLABEL_H
