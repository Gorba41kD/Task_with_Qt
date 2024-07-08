#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // Property of the current type of shape being used
    Q_PROPERTY(int typeFigure
    READ typeFigure WRITE setTypeFigure
    NOTIFY typeFigureChanged)

   public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene() noexcept = default;

    int typeFigure() const; // Return current type
    void setTypeFigure(const int type); // Set the current type

    // Listing the types of shapes used
    enum FigureTypes {
    RectangleType,
    TriangleType,
    EllipseType,
    LineType
    };

   signals:
    void typeFigureChanged(); // Signal about changing the type of the current figure

   private:
    /* Object for temporary storage of the drawn figure
    * Is the base class object for all 4 shape types in the example
    * */
    Figure* tempFigure;
    int m_typeFigure; // current figure type

   private:
    // Use mouse events for drawing
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
