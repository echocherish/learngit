#ifndef QTPAINTOBJECT_H
#define QTPAINTOBJECT_H
#include<QImage>
#include<QPoint>
#include<QAction>
#include<QPainter>
#include<QToolBar>
#include<vector>
#include<iostream>
#include<QJsonArray>
#include<QJsonObject>
namespace Ui {
class Widget;
}
class QtPaintObject: public QWidget
{
    Q_OBJECT
    QToolBar *thisToolBar;
public:
    QtPaintObject();
    virtual void draw(QPainter &pic)=0;
    virtual void drag(QPoint &firstPoint,QPoint &lastPoint)=0;
    virtual int getMiniX()=0;
    virtual int getMiniY()=0;
    virtual int getMaxX()=0;
    virtual int getMaxY()=0;
    enum  drawPic{
        Pencil,
        Eraser,
        Line,
        Rect,
        Ellipse,
        Polygon,
        chooseColor,
    };
    QString name;
    bool isPaint;
    static drawPic pen;
    virtual void beginDraw(QPainter &pic,QPoint &firstPoint,bool isDrag)=0;
    virtual void drawing(QPainter &pic,QPoint &firstPoint,QPoint &lastPoint,bool isDrag)=0;
    virtual void endDraw(QPainter &pic,QPoint &firstPoint,QPoint &lastPoint,bool isDrag)=0;
    QAction *paintThisObject;
    virtual void save(int i,QJsonArray &jsonArray)=0;
    virtual void open(QJsonObject &jsonObject)=0;
    static void paint(std::vector<QtPaintObject*> &paintVector,QPainter &pic,QPoint &firstPoint,bool isDrag);
public slots:
    virtual void onClickPaintThisObject()=0;
};

#endif // QTPAINTOBJECT_H
