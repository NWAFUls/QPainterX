#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"mywidget.h"
#include"line.h"
#include"rect.h"
#include"ellipse.h"
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include<QColorDialog>
#include <QFileDialog>
#include<QColor>
#include<QDebug>
#include<cstdlib>
#include<QString>
#include<help.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    void paintEvent(QPaintEvent *);
    int tnum;
    int _openflag;
    QPixmap _pixmap;

//private slots:

private slots:
    void on_actionHelp_text_triggered();

    void on_actionOpen_O_triggered();

    void on_actionSave_S_triggered();

private:
    Ui::MainWindow *ui;

    void on_actionSave_triggered();//文件保存槽函数
    void on_action_Open_triggered();//文件打开槽函数

};

#endif // MAINWINDOW_H
