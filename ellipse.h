#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

/* Inherit from the Figure class,
 * which implements functionality common to all figures
 * */
class Ellipse : public Figure
{
    Q_OBJECT

   public:
    explicit Ellipse(QPointF point, QGraphicsObject *parent = 0);
    ~Ellipse();

   private:
    // For the Ellipse, we implement only the drawing itself
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ELLIPSE_H
