#include "qtpaintrect.h"
#include"qtpaintobject.h"
#include<QDebug>
#include<QJsonObject>
QtPaintRect::QtPaintRect(int x,int y,int width,int height)
    :QtPaintObject()
{
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    name=QString("Rect");
    paintThisObject=new QAction(QIcon("./image/rect.jpg"),QString("draw ellipse"),this);

}

void QtPaintRect::draw(QPainter &pic){
    pic.drawRect(x,y,width,height);
}


int QtPaintRect::getMiniX(){
    if(width>0)
        return x;
    else {
        return (x+width);
    }
}
int QtPaintRect::getMiniY(){
    if(height>0)
        return y;
    else {
        return (y+height);
    }
}

int QtPaintRect::getMaxX(){
    if(width>0)
        return (x+width);
    else {
        return x;
    }
}

int QtPaintRect::getMaxY(){
    if(height>0)
        return (y+height);
    else {
        return y;
    }
}

void QtPaintRect::drag(QPoint &firstPoint, QPoint &lastPoint){
    x=x+lastPoint.x()-firstPoint.x();
    y=y+lastPoint.y()-firstPoint.y();
    firstPoint=lastPoint;
}

void QtPaintRect::onClickPaintThisObject(){
    QtPaintObject::pen=Rect;
}


void QtPaintRect::beginDraw(QPainter &pic, QPoint &firstPoint, bool isDrag){

    if(isDrag){
        drag(firstPoint,firstPoint);
    }else {
        draw(pic);
    }

}

void QtPaintRect::drawing(QPainter &pic, QPoint &firstPoint, QPoint &lastPoint, bool isDrag){
    if(isDrag){
        drag(firstPoint,lastPoint);
    }
    else {
        x=firstPoint.x();
        y=firstPoint.y();
        width=lastPoint.x()-x;
        height=lastPoint.y()-y;
        draw(pic);
    }
}

void QtPaintRect::endDraw(QPainter &pic, QPoint &firstPoint, QPoint &lastPoint, bool isDrag){
    if(isDrag){
        drag(firstPoint,lastPoint);
    }
    else {
        width=lastPoint.x()-x;
        height=lastPoint.y()-y;
        draw(pic);
    }
}

void QtPaintRect::save(int i,QJsonArray &jsonArray){
    QJsonObject jsonObject;
    jsonObject.insert("name","rect");
    jsonObject.insert("X",x);
    jsonObject.insert("Y",y);
    jsonObject.insert("Width",width);
    jsonObject.insert("Height",height);
    jsonArray.insert(i,jsonObject);
}

void QtPaintRect::open(QJsonObject &jsonObject){
    x=jsonObject.take("X").toInt();
    y=jsonObject.take("Y").toInt();
    width=jsonObject.take("Width").toInt();
    height=jsonObject.take("Height").toInt();
}
