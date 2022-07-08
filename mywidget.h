#ifndef MYWIDGET_H
#define MYWIDGET_H


#include"line.h"
#include"rect.h"
#include"ellipse.h"
#include"shape.h"
#include<QPainter>//绘画事件
#include<QMouseEvent>//鼠标事件
#include<QDebug>
#include<iterator>
#include <QMessageBox>
#include <QWidget>
#include<QPoint>
#include<QColor>
#include<QPixmap>

#include<vector>

class MyWidget : public QWidget//定义新的类继承QWidget父类
{
    Q_OBJECT
public:
    int singlePainter;//绘画用的标识
    int singleRefresh;//更改用的标识
    int flag;//更改与画图的切换
    int count;//图形总数
    int num;//选中的图形序数
    int width;
    int first;
    int scale;//用于判断放大

    QPoint lastPoint;//起点坐标
    QPoint endPoint;//终点坐标

    QColor penColor = Qt::black;//画笔的初始颜色
    QColor brushColor = Qt::white;//画刷的初始颜色
    QColor backColor = Qt::white;//画板颜色的初始化
    int penWidth;//画笔的宽度

    QPixmap pix;//画布
    QPixmap tempPix; //辅助画布
    bool isDrawing;   //标志是否正在绘图
    Shape *pShape;//指针
    std::vector<Shape *> shape;//存放的是Shape型的指针
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);//绘画事件
    void mousePressEvent(QMouseEvent *);//按压
    void mouseMoveEvent(QMouseEvent *) ;//移动
    void mouseReleaseEvent(QMouseEvent *);//释放

signals:

public slots:
};

#endif // MYWIDGET_H
