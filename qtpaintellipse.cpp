#include "qtpaintellipse.h"
#include"qtpaintobject.h"
#include<QJsonObject>
QtPaintEllipse::QtPaintEllipse(int x,int y,int width,int height)
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    name=QString("ellipse");
//    QtPaintEllipse::paintThisObject=new QAction(QIcon("./image/ellipse.jpg"),QString("draw ellipse"),this);

}

void QtPaintEllipse::draw(QPainter &pic){
    pic.drawEllipse(x,y,width,height);
}

int QtPaintEllipse::getMiniX(){
    if(width>0)
        return x;
    else {
        return (x+width);
    }
}
int QtPaintEllipse::getMiniY(){
    if(height>0)
        return y;
    else {
        return (y+height);
    }
}

int QtPaintEllipse::getMaxX(){
    if(width>0)
        return (x+width);
    else {
        return x;
    }
}

int QtPaintEllipse::getMaxY(){
    if(height>0)
        return (y+height);
    else {
        return y;
    }
}

void QtPaintEllipse::drag(QPoint &firstPoint, QPoint &lastPoint){
    x=x+lastPoint.x()-firstPoint.x();
    y=y+lastPoint.y()-firstPoint.y();
    firstPoint=lastPoint;
}

void QtPaintEllipse::onClickPaintThisObject(){
    QtPaintObject::pen=Ellipse;
}


void QtPaintEllipse::beginDraw(QPainter &pic, QPoint &firstPoint, bool isDrag){

    if(isDrag){
        drag(firstPoint,firstPoint);
    }else {
        draw(pic);
    }

}

void QtPaintEllipse::drawing(QPainter &pic, QPoint &firstPoint, QPoint &lastPoint, bool isDrag){
    if(isDrag){
        drag(firstPoint,lastPoint);
    }
    else {
        width=lastPoint.x()-x;
        height=lastPoint.y()-y;
        draw(pic);
    }
}

void QtPaintEllipse::endDraw(QPainter &pic, QPoint &firstPoint, QPoint &lastPoint, bool isDrag){
    if(isDrag){
        drag(firstPoint,lastPoint);
    }
    else {
        width=lastPoint.x()-x;
        height=lastPoint.y()-y;
        draw(pic);
    }
}


void QtPaintEllipse::save(int i,QJsonArray &jsonArray){
    QJsonObject jsonObject;
    jsonObject.insert("name","ellipse");
    jsonObject.insert("X",x);
    jsonObject.insert("Y",y);
    jsonObject.insert("Width",width);
    jsonObject.insert("Height",height);
    jsonArray.insert(i,jsonObject);
}

void QtPaintEllipse::open(QJsonObject &jsonObject){
    x=jsonObject.take("X").toInt();
    y=jsonObject.take("Y").toInt();
    width=jsonObject.take("Width").toInt();
    height=jsonObject.take("Height").toInt();
}
