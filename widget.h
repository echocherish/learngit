#ifndef WIDGET_H
#define WIDGET_H


#include"qtpaintobject.h"
#include<QMainWindow>
#include <QWidget>
#include<QFile>
#include<QMouseEvent>
#include<QPoint>
#include<QPaintEvent>
#include<QToolBar>
#include<QLabel>
#include<QAction>
#include<vector>
#include<iostream>
namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent=0);
    ~Widget();


//    drawPic pen;
    void paint(QImage &thisImage);
    void paintBottom(QImage &thisImage);
    static QColor penColor;

    QAction *newFile,*openFile,*saveFile;
    QLabel *toolBarLabel;
    QImage image,bottomImage;
    void saveFilesFunction(bool ifNew);
    std::vector<QtPaintObject*> paintVector;
    QToolBar *lineToolBar,*rectToolBar,*ellipseToolBar,*pencilToolBar,*erazerToolBar,*polygonToolBar,*chooseColorToolBar;
    QAction *paintLine,*paintRect,*paintEllipse,*paintPencil,*clear,*paintPolygon,*chooseColor;
protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
//    void closeEvent(QCloseEvent *event);
private:


    QFile load;
    QPoint firstPoint,lastPoint;
    QPoint moveFirstPoint,moveLastPoint;
    bool isMove;
    bool isDrag;
    bool isDraw;
    bool changed;
    QImage temp;
    int penWidth;
    Qt::PenStyle penStyle;
    int paintObjectID;
    bool isBegin;
public slots:
    void onClickPaintLine();
    void onClickPaintRect();
    void onClickPaintEllipse();
    void onClickPaintPencil();
    void onClickClear();
    void onClickPaintPolygon();
    void onClickchooseColor();

//    void newFileFunction();
//    void openFileFunction();
//    void saveFileFuction();
    void beginMove();
    void stopMove();

};

#endif // WIDGET_H
