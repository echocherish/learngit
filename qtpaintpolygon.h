#ifndef QTPAINTPOLYGON_H
#define QTPAINTPOLYGON_H
#include"qtpaintobject.h"
#include<vector>
#include<QPoint>
#include<iostream>
class QtPaintPolygon : public QtPaintObject
{
public:
    QtPaintPolygon();
    std::vector<QPoint> points;

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
    virtual void onClickPaintThisObject();
};

#endif // QTPAINTPOLYGON_H
