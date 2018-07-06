#ifndef QTPAINTTOOLBAR_H
#define QTPAINTTOOLBAR_H
#include<iostream>
#include<vector>
#include<QVBoxLayout>
#include<QToolBar>
#include<QAction>
#include<QWidget>
#include"widget.h"

class QtPaintToolBar:public QWidget
{
    Q_OBJECT
public:
    QtPaintToolBar(QWidget *parent=0);
//    QToolBar *lineToolBar,*rectToolBar,*ellipseToolBar,*pencilToolBar,*erazerToolBar,*polygonToolBar,*chooseColorToolbar;
//    QAction *paintLine,*paintRect,*paintEllipse,*paintPencil,*clear,*paintPolygon,*chooseColor;
//public slots:
//    void onClickPaintLine();
//    void onClickPaintRect();
//    void onClickPaintEllipse();
//    void onClickPaintPencil();
//    void onClickClear();
//    void onClickPaintPolygon();
//    void onClickchooseColor();
};

#endif // QTPAINTTOOLBAR_H
