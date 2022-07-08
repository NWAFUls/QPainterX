#ifndef ELLIPSE_H
#define ELLIPSE_H

#include"shape.h"
#include "mywidget.h"
class Ellipse : public Shape
{
public:
    Ellipse(const QColor &pen);
    void drawPix(QPainter *,QPixmap *, QPixmap *, QPoint, QPoint, int , int);
};

#endif // LINE_H
