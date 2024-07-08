#include "paintscene.h"
#include "rectangle.h"
#include "triangle.h"
#include "ellipse.h"
#include "line.h"
PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Set the end coordinate of the mouse position
    * to the currently drawn figure
    * */
    tempFigure->setEndPoint(event->scenePos());

    /* Update the contents of the scene,
    * necessary to eliminate artifacts when drawing figures
    * */
    this->update(QRectF(0,0,this->width(), this->height()));
}

/* As soon as the mouse button is pressed, we create a shape of one of 4 types
 * and place it on the stage, storing a pointer to it in a variable
 * tempFigure
 * */
void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Figure* item;

    switch (m_typeFigure)
    {
    case RectangleType:
    {
    item = new Rectangle(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
    }
    case EllipseType:
    {
    item = new Ellipse(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
    }
    case TriangleType:
    {
    item = new Triangle(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
    }
    case LineType:
    {
    item =new Line(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
    }
    default:
    { // A rectangle will be drawn by default
    //
    item = new Rectangle(event->scenePos());
    item->setPos(event->pos());
    tempFigure = item;
    break;
    }
    }

    this->addItem(tempFigure);
}
