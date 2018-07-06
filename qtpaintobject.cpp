#include "qtpaintobject.h"
#include"qtpaintrect.h"
#include"qtpaintellipse.h"
#include"qtpaintpolygon.h"
#include"widget.h"
#include<QDebug>
QtPaintObject::QtPaintObject()
{

}
QtPaintObject::drawPic QtPaintObject::pen=QtPaintObject::Rect;
void QtPaintObject::paint(std::vector<QtPaintObject*> &paintVector,QPainter &pic,QPoint &firstPoint, bool isDrag)
{

    switch (pen) {
        case Rect:
        {

            QtPaintRect *p;
            p=new QtPaintRect(firstPoint.x(),firstPoint.y(),0,0);
            paintVector.push_back(p);
            break;
        }
        case Ellipse:
        {
            QtPaintEllipse *p=new QtPaintEllipse(firstPoint.x(),firstPoint.y(),0,0);
            paintVector.push_back(p);
            p->beginDraw(pic,firstPoint,isDrag);
            break;
        }
        case Polygon:
        {
        if((paintVector.size()>0)&&(paintVector[paintVector.size()-1]->name.compare("Polygon")==0))
        {
            if(paintVector[paintVector.size()-1]->isPaint)
            {
                QtPaintPolygon *p=new QtPaintPolygon;
                paintVector.push_back(p);
            }else {
            }
        }else {
            QtPaintPolygon *p=new QtPaintPolygon;
            paintVector.push_back(p);

        }
            break;
        }
        default:
            break;
    }
}
