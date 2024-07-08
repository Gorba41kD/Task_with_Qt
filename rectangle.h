#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT

public:
    explicit Rectangle(QPointF point, QGraphicsObject *parent = 0);
    ~Rectangle();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // RECTANGLE_H
