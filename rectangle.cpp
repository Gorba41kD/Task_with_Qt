#include "rectangle.h"
#include <QPainter>

Rectangle::Rectangle(QPointF point, QGraphicsObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}
Rectangle::~Rectangle()
{

}
// Implement the draw method
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
