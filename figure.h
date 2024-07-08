#ifndef FIGURE_H
#define FIGURE_H

#include <QGraphicsObject>
#include <QDebug>

class Figure : public QGraphicsObject
{
    Q_OBJECT

    // Property of the starting point, relative to which we draw the figure
    Q_PROPERTY(QPointF startPoint
    READ startPoint WRITE setStartPoint
    NOTIFY pointChanged)

    // Property of the end point to where we draw the figure
    Q_PROPERTY(QPointF endPoint
    READ endPoint WRITE setEndPoint
    NOTIFY pointChanged)

   public:
    explicit Figure(QPointF point, QGraphicsObject *parent = 0);
    ~Figure() noexcept = default;

    QPointF startPoint() const; // Starе point
    QPointF endPoint() const; // End point

    void setStartPoint(const QPointF point); // Set the start point
    void setEndPoint(const QPointF point); // Set the endpoint

   signals:
    void pointChanged(); // Signal about point change

   private:
    QPointF m_startPoint; // Start point
    QPointF m_endPoint; // End point
    QRectF boundingRect() const; // The area that contains the shape

   public slots:
    void updateRectangle(); // Update slot for the area containing the shape
};

#endif // FIGURE_H
