#ifndef SHAPE_H
#define SHAPE_H

#include <QPixmap>
#include <QPen>
#include <QColorDialog>
#include <QDebug>

class Shape
{
public:
    Shape();
    virtual void drawPix(QPainter *,QPixmap *, QPixmap *, QPoint, QPoint, int, int) = 0;
    void up();
    void down();
    void right();
    void left();
    void larger();
    void smaller();

    void setbrushcolor(QColor color);
    void setpencolor(QColor color);
    void setbackcolor(QColor color);//设置画板颜色
    void setpenwidth(int width);
    QPoint lastPos;
    QPoint endPos;
protected:
    QColor penColor1;
    QColor brushColor1;
    QColor backColor1;
    int moveLen;//移动的距离
    int penWidth1;
};

#endif // SHAPE_H
