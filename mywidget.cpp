#include "mywidget.h"
#include <QPainter>
#include <QPixmap>
using namespace std;
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    penColor = Qt::black;//初始画笔颜色
    brushColor = Qt::white;//默认填充颜色
    backColor = Qt::white;
    singlePainter = 100;
    flag = 100;
    pix = QPixmap(1080,1080);//画板大小
    pix.fill(backColor);//设置画板背景

    count = 0;
    num = 1000000;

    first = 100;
    penWidth = 1;//初始线条宽度
    scale = 100;
}

void MyWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);

    if(flag == 0){

        switch (singlePainter)
        {
              case 0:case 1:case 2:

                      (*(shape.end()-1))->drawPix(&painter, &pix, &tempPix, lastPoint, endPoint, isDrawing, flag);
             break;

            break;
        }

    }else if (flag == 1) {
        //qDebug()  <<num;
        QPixmap clear = QPixmap(1080, 1080);
        clear.fill(backColor);
        int i = 0;
        for ( vector<Shape *>::iterator iter= shape.begin(); iter != shape.end(); iter++ ) {
            if(i == num-1){
                switch(singleRefresh){
                case 0:{(*iter)->up();qDebug() << num;}break;
                case 1:{(*iter)->down();}break;
                case 2:{(*iter)->left();}break;
                case 3:{(*iter)->right();}break;
                }
                (*iter)->drawPix(&painter, &clear, &tempPix, (*iter)->lastPos, (*iter)->endPos, isDrawing, flag);
            }
            else {
                if(scale == 0)(*iter)->larger();
                else if(scale == 1)(*iter)->smaller();
                qDebug() <<"scale"<<scale<<(*iter)->lastPos;
                (*iter)->drawPix(&painter, &clear, &tempPix, (*iter)->lastPos, (*iter)->endPos, isDrawing, flag);   
            }
            i++;
        }
        qDebug() <<"小 i" <<i;
        scale = 1000;
        pix = clear;
    }else if (flag == 2) {
                QPixmap clear = QPixmap(1080, 1080);
                clear.fill(backColor);
                pix = clear;
                painter.drawPixmap(0, 0, pix);
                shape.clear();
                flag = 100;
                qDebug() <<"scale";
            }
}

void MyWidget::mousePressEvent(QMouseEvent * event){

    if(event->button()==Qt::LeftButton){

        lastPoint =  event->pos();
        if(flag == 0){
                switch (singlePainter) {
                case 0:{
                    pShape = new Line(Qt::black);

                    pShape->setbrushcolor(brushColor);
                    pShape->setpencolor(penColor);
                    pShape->setbackcolor(backColor);
                    pShape->setpenwidth(penWidth);
                    shape.push_back(pShape);

                }break;
                case 1:{
                    pShape = new Rect(Qt::black);

                    pShape->setbrushcolor(brushColor);
                    pShape->setpencolor(penColor);
                    pShape->setpenwidth(penWidth);
                    shape.push_back(pShape);

                }break;
                case 2:{
                    pShape = new Ellipse(Qt::black);

                    pShape->setbrushcolor(brushColor);
                    pShape->setpencolor(penColor);
                    pShape->setpenwidth(penWidth);
                    shape.push_back(pShape);

                }break;
                }

            (*(shape.end()-1))->lastPos = lastPoint;
        }

    }
}
void MyWidget::mouseMoveEvent(QMouseEvent * event) {
    if(event->buttons()&Qt::LeftButton) //鼠标左键按下的同时移动鼠标
     {
         if(flag == 0){
               endPoint = event->pos();
               isDrawing = 1;
               update(); //进行绘制
            }
     }
 }
void MyWidget::mouseReleaseEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton) //鼠标左键释放
    {
        if(flag == 0){
            endPoint = event->pos();
            (*(shape.end()-1))->endPos = endPoint;

            isDrawing = 0;

            if(lastPoint != endPoint){count++;}
            else{shape.pop_back();}
            qDebug() << "总数" << count ;
            update();
        }
    }
}

