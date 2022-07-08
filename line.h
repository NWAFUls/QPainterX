#ifndef LINE_H
#define LINE_H

#include"shape.h"
class Line : public Shape
{
public:
    Line(const QColor &pen);
    void drawPix(QPainter *,QPixmap *, QPixmap *, QPoint, QPoint, int , int);
};

#endif // LINE_H
