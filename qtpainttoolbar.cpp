#include "qtpainttoolbar.h"
#include"qtpaintobject.h"
#include<QToolBar>
#include<QAction>
#include<QColorDialog>
#include<QLabel>
#include"widget.h"
QtPaintToolBar::QtPaintToolBar(QWidget *parent)
    :QWidget(parent)
{

//    paintLine=new QAction(QIcon("./image/line.jpg"),tr("draw line"),(this));
//    paintRect=new QAction(QIcon("./image/rectangle.png"),tr("draw rect"),this);
//    paintEllipse=new QAction(QIcon("./image/elipse.png"),tr("draw ellipse"),this);
//    paintPencil=new QAction(QIcon("./image/pencil.png"),tr("draw pencil"),this);
//    paintPolygon=new QAction(QIcon("./image/line.jpg"),tr("draw line"),this);
//    clear=new QAction(QIcon("./image/eraser.png"),tr("clear"),this);
//    chooseColor=new QAction(QIcon("./image/line.jpg"),tr("choose color"),this);

//    lineToolBar= new QToolBar(this);
//    rectToolBar=new QToolBar(this);
//    ellipseToolBar=new QToolBar(this);
//    pencilToolBar=new QToolBar(this);
//    erazerToolBar=new QToolBar(this);
//    polygonToolBar=new QToolBar(this);
//    chooseColorToolbar=new QToolBar(this);

//    lineToolBar->addAction(paintLine);
//    rectToolBar->addAction(paintRect);
//    ellipseToolBar->addAction(paintEllipse);
//    pencilToolBar->addAction(paintPencil);
//    erazerToolBar->addAction(clear);
//    polygonToolBar->addAction(paintPolygon);
//    chooseColorToolbar->addAction(chooseColor);


//    QObject::connect(paintLine,SIGNAL(triggered(bool)),this,SLOT(onClickPaintLine()));
//    QObject::connect(paintRect,SIGNAL(triggered(bool)),this,SLOT(onClickPaintRect()));
//    QObject::connect(paintEllipse,SIGNAL(triggered(bool)),this,SLOT(onClickPaintEllipse()));
//    QObject::connect(paintPencil,SIGNAL(triggered(bool)),this,SLOT(onClickPaintPencil()));
//    QObject::connect(clear,SIGNAL(triggered(bool)),this,SLOT(onClickClear()));
//    QObject::connect(paintPolygon,SIGNAL(triggered(bool)),this,SLOT(onClickPaintPolygon()));
//    QObject::connect(chooseColor,SIGNAL(triggered(bool)),this,SLOT(onClickchooseColor()));

//    QLabel *myLabel=new QLabel(this);
//    QVBoxLayout *layout=new QVBoxLayout;
//    layout->addWidget(lineToolBar);
//    layout->addWidget(rectToolBar);
//    layout->addWidget(ellipseToolBar);
//    layout->addWidget(pencilToolBar);
//    layout->addWidget(erazerToolBar);
//    layout->addWidget(polygonToolBar);
//    layout->addWidget(chooseColorToolbar);

//    layout->setSizeConstraint(QLayout::SetFixedSize);
//    myLabel->setLayout(layout);
}


//void QtPaintToolBar::onClickPaintRect(){
//    QtPaintObject::pen=QtPaintObject::Rect;
//}

//void QtPaintToolBar::onClickPaintEllipse(){
//    QtPaintObject::pen=QtPaintObject::Ellipse;
//}

//void QtPaintToolBar::onClickPaintPolygon(){
//    QtPaintObject::pen=QtPaintObject::Polygon;
//}

//void QtPaintToolBar::onClickPaintPencil(){
//    QtPaintObject::pen=QtPaintObject::Pencil;
//}

//void QtPaintToolBar::onClickPaintLine(){
//    QtPaintObject::pen=QtPaintObject::Line;
//}

//void QtPaintToolBar::onClickClear(){
//    QtPaintObject::pen=QtPaintObject::Eraser;
//}

//void QtPaintToolBar::onClickchooseColor(){
////       QtPaintObject::pen=QtPaintObject::chooseColor;
//       Widget::penColor=QColorDialog::getColor(Qt::blue,this,tr("颜色"));
//}
