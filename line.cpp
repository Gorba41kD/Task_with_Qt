#include "line.h"
#include <QPainter>

Line::Line(QPointF point, QGraphicsObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}
Line::~Line()
{

}
// Implement the draw method
void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    painter->drawLine(startPoint().x(),startPoint().y(),endPoint().x(),endPoint().y());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
