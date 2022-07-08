#include "line.h"

#include <QPoint>
#include<QPainter>
#include<QPixmap>
#include<QColor>
Line::Line(const QColor &pen)
{
    moveLen = 5;
}

void Line::drawPix(QPainter * pMyWidget, QPixmap *pix,QPixmap *tempPix ,QPoint last, QPoint end,  int isDrawing, int flag){
    if(flag == 0){
        if(isDrawing) //如果正在绘图，就在辅助画布上绘制
        {
            //将以前pix中的内容复制到tempPix中，保证以前的内容不消失
            *tempPix = *pix;
            QPainter pp(tempPix);
            QPen pen(penColor1,penWidth1);
            pp.setPen(pen);
            pp.setRenderHints(QPainter::SmoothPixmapTransform);
            pp.drawLine(last, end);
            pMyWidget->drawPixmap(0, 0, *tempPix);
        }
        else {
            QPainter pp(pix);
            QPen pen(penColor1,penWidth1);
            pp.setPen(pen);
            pp.setRenderHints(QPainter::SmoothPixmapTransform);
            pp.drawLine(last, end);
            pMyWidget->drawPixmap(0,0, *pix);
        }
    }
    else {
            QPainter pp(pix);
            QPen pen(penColor1,penWidth1);
            pp.setPen(pen);
            pp.setRenderHints(QPainter::SmoothPixmapTransform);
            pp.drawLine(last, end);
            pMyWidget->drawPixmap(0, 0, *pix);
    }

}

