#ifndef RECT_H
#define RECT_H

#include "shape.h"
#include "mywidget.h"
#include <QColor>
#include <QPainter>

class Rect : public Shape
{
public:
    Rect(const QColor &pen);
    void drawPix(QPainter *,QPixmap *, QPixmap *, QPoint, QPoint, int , int);

};

#endif // RECT_H
