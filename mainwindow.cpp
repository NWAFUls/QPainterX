#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("画板");//设置窗口标题
    tnum = 1000;
    _openflag = 0;
//信号和槽
    connect(ui->LineButton, &QToolButton::clicked, [&](){ui->myWidget->flag = 0;ui->myWidget->singlePainter = 0;ui->myWidget->first = 1;ui->myWidget->lastPoint = QPoint(-10000, -10000);ui->myWidget->endPoint = QPoint(-10000 , -10000);});
    connect(ui->RectButton,&QToolButton::clicked,[&](){
        ui->myWidget->flag = 0;
        ui->myWidget->singlePainter = 1;
        ui->myWidget->first = 1;
        ui->myWidget->lastPoint = QPoint(-10000, -10000);
        ui->myWidget->endPoint = QPoint(-10000 , -10000);
    });//画线的信号槽
    connect(ui->EllipseButton, &QToolButton::clicked, [&](){//YYB
        ui->myWidget->flag= 0;
        ui->myWidget->singlePainter = 2;
        ui->myWidget->first = 1;
        ui->myWidget->lastPoint = QPoint(-10000, -10000);
        ui->myWidget->endPoint = QPoint(-10000 , -10000);

    });
    connect(ui->up, &QToolButton::clicked ,[&](){
        ui->myWidget->flag = 1;
        ui->myWidget->singleRefresh = 0;
        ui->myWidget->update();
        });//移动的信号槽
    connect(ui->down, &QToolButton::clicked ,[&](){
        ui->myWidget->flag = 1;
        ui->myWidget->singleRefresh = 1;
        ui->myWidget->update();
        });
    connect(ui->left, &QToolButton::clicked ,[&](){
        ui->myWidget->flag = 1;
        ui->myWidget->singleRefresh = 2;
        ui->myWidget->update();
        });
    connect(ui->right, &QToolButton::clicked ,[&](){
        ui->myWidget->flag = 1;
        ui->myWidget->singleRefresh = 3;
        ui->myWidget->update();
        });

    //颜色
    //YYB
    connect(ui->colorButton, &QToolButton::clicked, [&](){ui->myWidget->brushColor = QColorDialog::getColor();});
    connect(ui->FramecolorButton, &QToolButton::clicked, [&](){ui->myWidget->penColor = QColorDialog::getColor();});
    connect(ui->BackcolorButton,&QToolButton::clicked,[&](){ui->myWidget->backColor = QColorDialog::getColor();});

    //线条宽度
    connect(ui->FrameWidth,&QLineEdit::textEdited,[&](){
        ui->myWidget->penWidth = ui->FrameWidth->text().toInt();
    });

    connect(ui->lineOk, &QPushButton::clicked, [&](){
        int i = ui->lineNum->text().toInt();
        if(!(i >= 0 && i <= ui->myWidget->count))return;
        ui->myWidget->num = i;
        qDebug()<< i;
    });

    connect(ui->countButton, &QPushButton::clicked, [&](){

        int count = ui->myWidget->count;

        QString str = QString::number(count);
        ui->shapeCount->setText(str);
    });

    //放大和缩小
    connect(ui->LargerButton, &QToolButton::clicked, [&](){
    ui->myWidget->flag = 1;
    ui->myWidget->scale = 0;
    ui->myWidget->num = 1000;
    ui->myWidget->update();
    });
    connect(ui->SmallerButton, &QToolButton::clicked,[&](){
    ui->myWidget->flag = 1;
    ui->myWidget->scale = 1;
    ui->myWidget->num = 1000;
    ui->myWidget->update();
    });

    //清屏操作
    connect(ui->DelButton, &QToolButton::clicked, [&](){ui->myWidget->flag = 2;ui->myWidget->update();ui->myWidget->count = 0;});

}


 MainWindow::~MainWindow()//析构函数
 {
     delete ui;
 }

//文件保存
void MainWindow::on_actionSave_triggered()
{
    QPainter p(&ui->myWidget->pix );
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存"),"new.jpg");
    ui->myWidget->pix.save(fileName);
}

//文件打开
void MainWindow::on_action_Open_triggered()
{
    QString picPath = QFileDialog::getOpenFileName(this,tr("打开"),"","Image Files(*.jpg *.png)");
    QPixmap pix2;
    pix2.load(picPath);
     QPainter p(&ui->myWidget->pix);
    p.drawPixmap(0,0,pix2);
    update();
}


void MainWindow::on_actionHelp_text_triggered()
{
    Help *p = new Help;
    p->show();
}


void MainWindow::on_actionOpen_O_triggered()
{
    QString picPath = QFileDialog::getOpenFileName(this,tr("打开"),"","Image Files(*.jpg *.png)");
    if(!picPath.isEmpty())
    {
        QPixmap pix;
        pix.load(picPath);
        QPainter p(&_pixmap);
        p.drawPixmap(0,30,pix);
        _openflag = 1;
        update();
    }
}

void MainWindow::on_actionSave_S_triggered()
{
    QPixmap pixmap = ui->myWidget->grab();

    QString reSave_path = QFileDialog::getSaveFileName(this,tr("保存"),"new.png","普通图像(*.jpg *.png *.bmp);;图像(*.tif)"); //选择路径
    ui->actionSave_S->setText(reSave_path);
     if(reSave_path!=""){
         qDebug()<<reSave_path;    
         bool ret = pixmap.save(reSave_path);
         if(ret){
         QMessageBox::about(this,"成功！","保存成功！");
         }
     }
     else{
         QMessageBox::critical(this,"错误！","未打开任何文件！",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);

    }
}
