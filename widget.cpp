#include "widget.h"
#include "ui_widget.h"
#include"qtpaintobject.h"
#include"qtpaintpolygon.h"
#include"qtpaintellipse.h"
#include"qtpaintrect.h"
#include<QMenu>
#include<QMenuBar>
#include<QPushButton>
#include<QDebug>
#include"qtpaintrect.h"
#include<QPen>
#include<QPainter>
#include<QColorDialog>
#include<QMessageBox>
#include<QVBoxLayout>
#include<QFileDialog>
#include<QJsonDocument>
#include<QJsonObject>
Widget::Widget(QWidget *parent) :
    QMainWindow(parent)
//,    ui(new Ui::Widget)
{

    setFixedSize(600,500);
    //添加菜单栏
    QMenu *openFileMenu=new QMenu("new file");
    QMenu *newFileMenu=new QMenu("open file");
    QMenu *saveFileMenu=new QMenu("save file");
    newFile=new QAction(QIcon(),tr("&new file"),this);
    openFile=new QAction(QIcon(),tr("&open file"),this);
    saveFile=new QAction(QIcon(),tr("&save file"),this);
    QObject::connect(newFile,SIGNAL(triggered(bool)),this,SLOT(newFileFunction()));
    QObject::connect(openFile,SIGNAL(triggered(bool)),this,SLOT(openFileFunction()));
    QObject::connect(saveFile,SIGNAL(triggered(bool)),this,SLOT(saveFileFuction()));
    QMenuBar *fileMenu=new QMenuBar(this);
    openFileMenu->addAction(newFile);
    newFileMenu->addAction(openFile);
    saveFileMenu->addAction(saveFile);
    fileMenu->addMenu(openFileMenu);
    openFileMenu->addMenu(newFileMenu);
    openFileMenu->addMenu(saveFileMenu);


    //添加按钮以完成拖拽动作
    QPushButton *beginButton=new QPushButton("begin drag",this);
    beginButton->setGeometry(QRect(QPoint(500,100),QSize(100,25)));
    QPushButton *stopButton=new QPushButton("stop drag",this);
    stopButton->setGeometry(QRect(QPoint(500,200),QSize(100,25)));
    QObject::connect(beginButton,SIGNAL(clicked(bool)),this,SLOT(beginMove()));
    QObject::connect(stopButton,SIGNAL(clicked(bool)),this,SLOT(stopMove()));




    image=QImage(500,500,QImage::Format_RGB32);
    bottomImage=QImage(500,500,QImage::Format_RGB32);
    image.fill(qRgb(255,255,255));
    bottomImage.fill(qRgb(255,255,255));
    temp=image;
    changed=false;




    qDebug()<<QDir::currentPath();
    paintLine=new QAction(QIcon("://line.png"),tr("draw line"),(this));
    paintRect=new QAction(QIcon(":rect.png"),tr("draw rect"),this);
    paintEllipse=new QAction(QIcon(":/prefix/image/ellipse.png"),tr("draw ellipse"),this);
    paintPencil=new QAction(QIcon(":/myImage/image/pencil.jpg"),tr("draw pencil"),this);
    paintPolygon=new QAction(QIcon(":/myImage/image/line.jpg"),tr("draw line"),this);
    clear=new QAction(QIcon(":/myImage/image/eraser.png"),tr("clear"),this);
    chooseColor=new QAction(QIcon("./image/line.jpg"),tr("choose color"),this);


    lineToolBar= new QToolBar(this);
    rectToolBar=new QToolBar(this);
    ellipseToolBar=new QToolBar(this);
    pencilToolBar=new QToolBar(this);
    erazerToolBar=new QToolBar(this);
    polygonToolBar=new QToolBar(this);
    chooseColorToolBar=new QToolBar(this);


    lineToolBar->addAction(paintLine);
    rectToolBar->addAction(paintRect);
    ellipseToolBar->addAction(paintEllipse);
    pencilToolBar->addAction(paintPencil);
    erazerToolBar->addAction(clear);
    polygonToolBar->addAction(paintPolygon);
    chooseColorToolBar->addAction(chooseColor);

    QObject::connect(paintLine,SIGNAL(triggered(bool)),this,SLOT(onClickPaintLine()));
    QObject::connect(paintRect,SIGNAL(triggered(bool)),this,SLOT(onClickPaintRect()));
    QObject::connect(paintEllipse,SIGNAL(triggered(bool)),this,SLOT(onClickPaintEllipse()));
    QObject::connect(paintPencil,SIGNAL(triggered(bool)),this,SLOT(onClickPaintPencil()));
    QObject::connect(clear,SIGNAL(triggered(bool)),this,SLOT(onClickClear()));
    QObject::connect(paintPolygon,SIGNAL(triggered(bool)),this,SLOT(onClickPaintPolygon()));
    QObject::connect(chooseColor,SIGNAL(triggered(bool)),this,SLOT(onClickchooseColor()));

    QLabel *myLabel=new QLabel(this);
    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(lineToolBar);
    layout->addWidget(rectToolBar);
    layout->addWidget(ellipseToolBar);
    layout->addWidget(pencilToolBar);
    layout->addWidget(erazerToolBar);
    layout->addWidget(polygonToolBar);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->addWidget(chooseColorToolBar);
    myLabel->setLayout(layout);

    penWidth=5;
    penStyle=Qt::SolidLine;
    isDraw=false;
    isMove=false;
    isDrag=false;
    isBegin=false;
    paintObjectID=-1;
}

QColor Widget::penColor=Qt::black;


Widget::~Widget()
{

}
void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.scale(1,1);


    if(isDraw)
    {
        painter.drawImage(0,0,temp);
    }
    else{
        if((QtPaintObject::pen==QtPaintObject::Pencil)||(QtPaintObject::pen==QtPaintObject::Eraser)||(QtPaintObject::pen==QtPaintObject::Line)){
            painter.drawImage(0,0,bottomImage);
            painter.drawImage(0,0,image);


        }else {
            painter.drawImage(0,0,image);
        }

    }
}

void Widget::mousePressEvent(QMouseEvent *event){
    if(event->type() == QEvent::MouseButtonPress){
        if(isMove){
            for (int i=0;i<paintVector.size();i++)
            {
                if(event->pos().x()>paintVector[i]->getMiniX()&&event->pos().y()>paintVector[i]->getMiniY()&&event->pos().x()<paintVector[i]->getMaxX()&&event->pos().y()<paintVector[i]->getMaxY())
                {
                    isDrag=true;
                    paintObjectID=i;
                    moveFirstPoint=event->pos();
                    break;
                }
            }
        }else {
           firstPoint=event->pos();
           isBegin=true;
           paint(image);
            isDraw=true;
        }
    }

}

void Widget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons()&Qt::LeftButton){
        if(isMove){
            if(isDrag)
            {
                moveLastPoint=event->pos();
                image=bottomImage;
                paint(image);
            }

        }else {
           lastPoint=event->pos();
           isBegin=false;
           if((QtPaintObject::pen==QtPaintObject::Pencil)||(QtPaintObject::pen==QtPaintObject::Eraser)){
               isDraw=false;
               paintBottom(bottomImage);
               paint(image);
           }
           else if(QtPaintObject::pen==QtPaintObject::Line){
               temp=image;
               paint(temp);
           }
           else {
               temp=image;
               paint(temp);
           }
        }
    }

}


void Widget::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        if(isMove){
            if(isDrag)
            {
                moveLastPoint=event->pos();
                image=bottomImage;
                paint(image);
                isDrag=false;
                paintObjectID=-1;
            }

        }
        else {
            lastPoint=event->pos();
            isDraw=false;
            isBegin=false;
            if((QtPaintObject::pen==QtPaintObject::Pencil)||(QtPaintObject::pen==QtPaintObject::Eraser)||(QtPaintObject::pen==QtPaintObject::Line)){

                paintBottom(bottomImage);
                paint(image);
            }else {
                paint(image);
            }
        }
    }
}


void Widget::paintBottom(QImage &thisImage){
    QPainter pic(&thisImage);
    QPen pen=QPen();
    pen.setColor(penColor);
    pen.setStyle(penStyle);
    pen.setWidth(penWidth);
    pic.setPen(pen);

    QPoint a=firstPoint;
    QPoint b=lastPoint;

    switch (QtPaintObject::pen) {
    case QtPaintObject::Pencil:
    {
        pic.drawLine(a,b);
        break;
    }
    case QtPaintObject::Eraser:
    {
        QRect rect1=QRect(firstPoint,QPoint(firstPoint.x()+10,firstPoint.y()+10));
        pic.eraseRect(rect1);
        break;
    }
    case QtPaintObject::Line:
    {
        pic.drawLine(a,b);
        break;
    }
    default:
        break;
    }
}



void Widget::paint(QImage &thisImage){
    QPainter pic(&thisImage);
    QPen Pen=QPen();
    Pen.setColor(penColor);
    Pen.setStyle(penStyle);
    Pen.setWidth(penWidth);

    pic.setPen(Pen);
    if(isMove){
        if(isDrag){
            if(paintObjectID>=0)
            {
                paintVector[paintObjectID]->drag(moveFirstPoint,moveLastPoint);
            }
        }
            if(paintVector.size()>0)
            {
                for(int i=0;i<paintVector.size();i++)
                {
                    paintVector[i]->draw(pic);
                }
            }

    }else {
        switch (QtPaintObject::pen) {
        case QtPaintObject::Pencil:
        {
            if(!isBegin){
                pic.drawLine(firstPoint,lastPoint);
                firstPoint=lastPoint;
                break;
            }

        }
        case QtPaintObject::Line:
        {
            if(!isBegin){
                pic.drawLine(firstPoint,lastPoint);
                break;
            }

        }
        case QtPaintObject::Eraser:
        {
            if(!isBegin){
                QRect rect1=QRect(firstPoint,QPoint(firstPoint.x()+10,firstPoint.y()+10));
                pic.eraseRect(rect1);
                firstPoint=lastPoint;
                break;
            }

        }


        default:
        {
            if(isDraw){
                paintVector[paintVector.size()-1]->drawing(pic,firstPoint,lastPoint,isDrag);
            }else if (isBegin) {
                QtPaintObject::paint(paintVector,pic,firstPoint,isDrag);

            }else {
                paintVector[paintVector.size()-1]->endDraw(pic,firstPoint,lastPoint,isDrag);
            }

            break;
        }
        }
    }

    update();
    changed=true;
}




void Widget::onClickPaintRect(){
    QtPaintObject::pen=QtPaintObject::Rect;
}

void Widget::onClickPaintEllipse(){
    QtPaintObject::pen=QtPaintObject::Ellipse;
}

void Widget::onClickPaintPolygon(){
    QtPaintObject::pen=QtPaintObject::Polygon;

}

void Widget::onClickPaintPencil(){
    QtPaintObject::pen=QtPaintObject::Pencil;
}

void Widget::onClickPaintLine(){
    QtPaintObject::pen=QtPaintObject::Line;
}

void Widget::onClickClear(){
    QtPaintObject::pen=QtPaintObject::Eraser;
}

void Widget::onClickchooseColor(){
//       QtPaintObject::pen=QtPaintObject::chooseColor;
       Widget::penColor=QColorDialog::getColor(Qt::blue,this,tr("颜色"));
}




void Widget::beginMove(){

    isMove=true;
}

void Widget::stopMove(){

    isMove=false;
    temp=image;
}
