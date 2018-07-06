#include "qtpaintpolygon.h"
#include"qtpaintobject.h"
#include<QDebug>
#include<QJsonObject>
#include<QJsonValue>
QtPaintPolygon::QtPaintPolygon()
{
    name=QString("Polygon");
    isPaint=false;
    QtPaintPolygon::paintThisObject=new QAction(QIcon("./image/polygon.jpg"),QString("draw ellipse"),this);

}

void QtPaintPolygon::onClickPaintThisObject(){
    QtPaintObject::pen=QtPaintObject::Polygon;
}

void QtPaintPolygon::draw(QPainter &pic){
    QPoint point[10];
    for(int i=0;i<points.size();i++){
        point[i]=points[i];
    }
    pic.drawPolygon(point,points.size());
}

void QtPaintPolygon::drag(QPoint &firstPoint, QPoint &lastPoint){
    for(int i=0;i<points.size();i++){
        points[i]=QPoint(points[i].x()+lastPoint.x()-firstPoint.x(),points[i].y()+lastPoint.y()-firstPoint.y());
    }
    firstPoint=lastPoint;
}

int QtPaintPolygon::getMiniX(){
    if(points.size()>0)
    {
        int x=points[0].x();
        for(int i=0;i<points.size();i++){
            if(x>points[i].x()){
                x=points[i].x();
            }
        }
        return x;
    }else {
        return 0;
    }

}

int QtPaintPolygon::getMiniY(){
    if(points.size()>0)
    {
        int y=points[0].y();
        for(int i=0;i<points.size();i++){
            if(y>points[i].y()){
                y=points[i].y();
            }
        }
        return y;
    }else {
        return 0;
    }
}

int QtPaintPolygon::getMaxX(){
    if(points.size()>0)
    {
        int x=points[0].x();
        for(int i=0;i<points.size();i++){
            if(x<points[i].x()){
                x=points[i].x();
            }
        }
        return x;
    }else {
        return 0;
    }

}

int QtPaintPolygon::getMaxY(){
    if(points.size()>0)
    {
        int y=points[0].y();
        for(int i=0;i<points.size();i++){
            if(y<points[i].y()){
                y=points[i].y();
            }
        }
        return y;
    }else {
        return 0;
    }
}

void QtPaintPolygon::beginDraw(QPainter &pic, QPoint &firstPoint, bool isDrag){
    if(isDrag){
        drag(firstPoint,firstPoint);
    }else {

    }
}

void QtPaintPolygon::drawing(QPainter &pic, QPoint &firstPoint, QPoint &lastPoint, bool isDrag){
    if(isDrag){
        drag(firstPoint,lastPoint);
    }
}

void QtPaintPolygon::endDraw(QPainter &pic, QPoint &firstPoint, QPoint &lastPoint, bool isDrag){
    if(isDrag){
        drag(firstPoint,lastPoint);
    }else {
        if((points.size()>0)&&(((points[0].x()+5)>firstPoint.x())&&((points[0].x()-5)<firstPoint.x())&&((points[0].y()+5)>firstPoint.y())&&((points[0].y()-5)<firstPoint.y())))
        {
                draw(pic);
                isPaint=true;
        }else {
            pic.drawPoint(firstPoint);
            points.push_back(firstPoint);
        }
    }
}


void QtPaintPolygon::save(int i,QJsonArray &jsonArray){
    QJsonObject jsonObject;
    jsonObject.insert("name","polygon");
    QJsonArray jsonPolygonArray;
    QJsonObject jsonPolygonObject;
    for(int i=0;i<points.size();i++)
    {
        jsonPolygonObject.insert("X",points[i].x());
        jsonPolygonObject.insert("Y",points[i].y());
        jsonPolygonArray.insert(i,jsonPolygonObject);
    }
    jsonObject.insert("points",jsonPolygonArray);
    jsonArray.insert(i,jsonObject);
}

void QtPaintPolygon::open(QJsonObject &jsonObject){
    QJsonArray jsonArray=jsonObject.take("points").toArray();
    for(int i=0;i<jsonArray.size();i++)
    {
            QJsonValue jsonValue=jsonArray.at(i);
            QJsonObject jsonPolygonObject=jsonValue.toObject();
            QPoint p(jsonPolygonObject.take("X").toInt(),jsonPolygonObject.take("Y").toInt());
            points.push_back(p);
    }
}
