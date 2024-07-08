#include "svgreader.h"
#include <QFile>
#include <QMessageBox>
#include <QDomDocument>
#include <QStringList>
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include "triangle.h"
SvgReader::SvgReader()
{

}
void SvgReader::setElements(const QString fileName,PaintScene* scene)
{


 QDomDocument doc; // document object
 QFile file(fileName); // Open our SVG file
 // If it didn't open or failed to transfer content to QDocDocument
 if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
 return; // then return a list, but empty

 // Search the document for all objects with the g tag
 QDomNodeList gList = doc.elementsByTagName("g");
 // iterating through the objects
 for(int i = 0;i < gList.size();i++)
 {
     Figure* figure;
     QDomNode gNode = gList.item(i);
     QDomElement typeFigure = gNode.firstChildElement("rect");

     QDomElement gElement;
     QPointF startPoint;
     QPointF endPoint;

  if(!typeFigure.isNull())
  {
     // Take the dimensions from the rect tag
     gElement = gNode.toElement();

     startPoint.setX(typeFigure.attribute("x").toInt());
     startPoint.setY(typeFigure.attribute("y").toInt());

     // Create a rectangle
     figure = new Rectangle(startPoint);

     endPoint.setX(startPoint.x() + typeFigure.attribute("width").toInt());
     endPoint.setY(startPoint.y() + typeFigure.attribute("height").toInt());

     figure->setEndPoint(endPoint);

     scene->update(QRectF(0,0,scene->width(), scene->height()));
     scene->addItem(figure);
  }
  else
  {
  typeFigure = gNode.firstChildElement("ellipse");
  if(!typeFigure.isNull())
  {
  // Take dimensions from the ellipse tag
  gElement = gNode.toElement();


  auto rx = typeFigure.attribute("rx").toInt();
  auto ry = typeFigure.attribute("ry").toInt();

  auto cx = typeFigure.attribute("cx").toInt();
  auto cy = typeFigure.attribute("cy").toInt();

  startPoint.setX(rx);
  startPoint.setY(ry);

  // Create an ellipse
  figure = new Ellipse(startPoint);

  endPoint.setX((cx - rx));
  endPoint.setY((cy - ry));

  figure->setEndPoint(endPoint);

  scene->update(QRectF(0,0,scene->width(), scene->height()));
  scene->addItem(figure);
  }
  else
  {

  typeFigure = gNode.firstChildElement("polyline");

  if(!typeFigure.isNull())
  {
  // Take dimensions from the polyline tag
  gElement = gNode.toElement();



  auto points = typeFigure.attribute("points");
  auto numbers = getNumbersFromText(points);

  startPoint.setX(numbers[0]);
  startPoint.setY(numbers[1]);

  // Create a line
  figure = new Line(startPoint);

  QPointF endPoint;
  endPoint.setX(numbers[2]);
  endPoint.setY(numbers[3]);

  figure->setEndPoint(endPoint);

  scene->update(QRectF(0,0,scene->width(), scene->height()));
  scene->addItem(figure);
  }
  else
  {
      typeFigure = gNode.firstChildElement("path");
      if(!typeFigure.isNull())
      {
      // Take the dimensions from the path tag
      gElement = gNode.toElement();

      auto text = typeFigure.attribute("d");
      auto numbers = getNumbersFromText(text);

      startPoint.setX(numbers[0]);
      startPoint.setY(numbers[1]);

      endPoint.setX(numbers[4]);
      endPoint.setY(numbers[5]);

      // Create a triangle
      figure = new Triangle(startPoint);
      figure->setEndPoint(endPoint);

      scene->update(QRectF(0,0,scene->width(), scene->height()));
      scene->addItem(figure);
      }
   }

   }
   }
   }
 file.close();
}
QVector<int> SvgReader::getNumbersFromText(const QString& text)
{
    QString number;

    QVector<int> numbers;
    for(int i = 0;i < text.size();++i)
    {
        if(text[i].isDigit() || text[i] == '.')
        {
            number+= text[i];
        }
        else
        {
            numbers.push_back(number.toInt());
            number = "";
        }
    }
    numbers.push_back(number.toInt());
    return numbers;
}

QRectF SvgReader::getSizes(const QString filename)
{
 QDomDocument doc; // initialize the QDomDocument object
 QFile file(filename); // Open our SVG file

 // If it didn't open or failed to transfer content to QDocDocument
 if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
 {
    return QRectF(0,0,200,200); // then return the default values ​​for the scene
 }

 /* Next, we take the list of elements with the svg tag.
 * If the list of elements is not empty,
 * then we take the dimensions of the graphic scene.
 * */
 QDomNodeList list = doc.elementsByTagName("svg");
 if(list.length() > 0)
 {
     QDomElement svgElement = list.item(0).toElement();
     QStringList parameters = svgElement.attribute("viewBox").split(" ");
     return QRectF(parameters.at(0).toInt(),
     parameters.at(1).toInt(),
     parameters.at(2).toInt(),
     parameters.at(3).toInt());
 }
 return QRectF(0,0,200,200);
}
