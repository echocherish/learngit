#ifndef QTPAINTELLIPSE_H
#define QTPAINTELLIPSE_H

#include"qtpaintobject.h"
class QtPaintEllipse : public QtPaintObject
{
public:
    QtPaintEllipse(int x,int y,int width,int height);
    int x;
    int y;
    int width;
    int height;
    void draw(QPainter &pic);
    void drag(QPoint &firstPoint,QPoint &lastPoint);
    int getMiniX();
    int getMiniY();
    int getMaxX();
    int getMaxY();
    void beginDraw(QPainter &pic,QPoint &firstPoint,bool isDrag);
    void drawing(QPainter &pic,QPoint &firstPoint,QPoint &lastPoint,bool isDrag);
    void endDraw(QPainter &pic,QPoint &firstPoint,QPoint &lastPoint,bool isDrag);
   QAction *paintThisObject;
   void save(int i,QJsonArray &jsonArray);
   void open(QJsonObject &jsonObject);
public slots:
    virtual  void onClickPaintThisObject();
};

#endif // QTPAINTELLIPSE_H
