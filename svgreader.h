#ifndef SVGREADER_H
#define SVGREADER_H

#include <QVector>
#include "paintscene.h"
#include "figure.h"
class SvgReader
{
public:
    SvgReader();
    static void setElements(const QString fileName,PaintScene *scene);
    static QRectF getSizes(const QString filename);
    static QVector<int> getNumbersFromText(const QString& text);
};

#endif // SVGREADER_H
