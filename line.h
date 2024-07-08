#ifndef LINE_H
#define LINE_H

#include "figure.h"

/* Inherit from the Figure class,
 * which implements functionality common to all figures
 * */
class Line : public Figure
{
 Q_OBJECT

public:
 explicit Line(QPointF point, QGraphicsObject *parent = 0);
 ~Line();

private:
 // For line, we implement only the drawing itself
 void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // LINE_H
