#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QGraphicsObject *parent) :
 QGraphicsObject(parent)
{
    // Set the starting coordinate for drawing the figure
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));

    /* Connect the coordinate change signal to the trigger slot for updating the object’s contents
    * Signal and slot are present in base class
    * */
    connect(this, &Figure::pointChanged, this, &Figure::updateRectangle);
}

QRectF Figure::boundingRect() const
{
    /* Return the area in which the figure lies.
    * The updated area depends on the starting point of the rendering and the end point
    * */
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
    (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
    qAbs(endPoint().x() - startPoint().x()) + 10,
    qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::updateRectangle()
{
    // Cause an update of the area in which the figure lies
    this->update((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
    (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
    qAbs(endPoint().x() - startPoint().x()) + 10,
    qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = mapFromScene(point);
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = mapFromScene(point);
    emit pointChanged();
}

QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}
