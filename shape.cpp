#include "shape.h"
#include <QPixmap>
#include <QColor>
Shape::Shape()
{
    moveLen = 5;

}
//图形的移动
void Shape::up(){

    int y = lastPos.y();
    y -= moveLen;//y轴向下为正方向
    lastPos.setY(y);

    int y2 = endPos.y();
    y2 -= moveLen;
    endPos.setY(y2);
}
void Shape::down(){
    int y = lastPos.y();
    y += moveLen;
    lastPos.setY(y);

    int y2 = endPos.y();
    y2 += moveLen;
    endPos.setY(y2);
}
void Shape::right(){
    int x = lastPos.x();
    x += moveLen;
    lastPos.setX(x);

    int x2 = endPos.x();
    x2 += moveLen;
    endPos.setX(x2);
}
void Shape::left(){
    int x = lastPos.x();
    x -= moveLen;
    lastPos.setX(x);

    int x2 = endPos.x();
    x2 -= moveLen;
    endPos.setX(x2);
}

//图形的缩放
void Shape::larger(){
    int x = lastPos.x();
    int y = lastPos.y();
    x -= moveLen;
    y -= moveLen;
    lastPos.setX(x);
    lastPos.setY(y);
    int x2 = endPos.x();
    int y2 = endPos.y();
    x2 += moveLen;
    y2 += moveLen;
    endPos.setX(x2);
    endPos.setY(y2);
}
void Shape::smaller(){
    int x = lastPos.x();
    int y = lastPos.y();
    int x2 = endPos.x();
    int y2 = endPos.y();
    x += moveLen;
    y += moveLen;
    x2 -= moveLen;
    y2 -= moveLen;
    if(x2>=x && y2>=y){
    lastPos.setX(x);
    lastPos.setY(y);
    endPos.setX(x2);
    endPos.setY(y2);
    }

}

//颜色设定
void Shape::setbrushcolor(QColor color)
{
    brushColor1 = color;
}
void Shape::setpencolor(QColor color)
{
    penColor1 = color;
}
void Shape::setbackcolor(QColor color)
{
    backColor1 = color;
}

//线条宽度
void Shape::setpenwidth(int width)
{
    penWidth1 = width;
}

