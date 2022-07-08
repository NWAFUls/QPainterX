#include "ellipse.h"

#include <QPoint>
#include<QPainter>
#include<QPixmap>
#include<QColor>
Ellipse::Ellipse(const QColor &pen)
{
      moveLen = 5;
}

void Ellipse::drawPix(QPainter * pMyWidget, QPixmap *pix,QPixmap *tempPix ,QPoint last, QPoint end,  int isDrawing, int flag){
    int w = end.x()-last.x();
    int h = end.y()-last.y();

    if(flag == 0){
        if(isDrawing) //如果正在绘图，就在辅助画布上绘制
        {
             //将以前pix中的内容复制到tempPix中，保证以前的内容不消失
            *tempPix = *pix;

            QPainter pp(tempPix);
            QPen pen(penColor1,penWidth1);
            pp.setPen(pen);
            pp.setBrush(brushColor1);

            pp.setRenderHints(QPainter::SmoothPixmapTransform);//抗锯齿
            pp.drawEllipse(last.x(),last.y(),w,h);
            pMyWidget->drawPixmap(0, 0, *tempPix);
        }
        else {
            QPainter pp(pix);

            QPen pen(penColor1,penWidth1);
            pp.setPen(pen);
            pp.setBrush(brushColor1);

            pp.setRenderHints(QPainter::SmoothPixmapTransform);
            pp.drawEllipse(last.x(),last.y(),w,h);
            pMyWidget->drawPixmap(0,0, *pix);
        }
    }
    else {
            QPainter pp(pix);
            QPen pen(penColor1,penWidth1);
            pp.setPen(pen);
            pp.setBrush(brushColor1);
            pp.setRenderHints(QPainter::SmoothPixmapTransform);
            pp.drawEllipse(last.x(),last.y(),w,h);
            pMyWidget->drawPixmap(0, 0, *pix);
    }

}
