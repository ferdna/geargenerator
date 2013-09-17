#include "gearobj.h"

#include <QtGui>

gearObj::gearObj(QGraphicsItem *parent) : QGraphicsItem(parent)
{
    setTransformOriginPoint(15,15);
}

QRectF gearObj::boundingRect() const
{
    return QRectF(0,0,30,30);

    //Note: For shapes that paint an outline / stroke, it is important to include half the pen width in the bounding rect. It is not necessary to compensate for antialiasing, though.
    //http://qt-project.org/doc/qt-5.0/qtwidgets/qgraphicsitem.html#boundingRect
    //
    //qreal penWidth = 1;
    //return QRectF(-radius - penWidth / 2, -radius - penWidth / 2,
    //              diameter + penWidth, diameter + penWidth);
}

void gearObj::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    //painter->setBrush(Qt::black);
    painter->drawRect(0,0,30,30);
    //painter->drawEllipse(QPointF(10,10),20.0,20.0);

    /*QPointF center, startPoint;
    QPainterPath path;
    path.addRect(20, 20, 60, 60);

    path.moveTo(0, 0);
    path.cubicTo(99, 0,  50, 50,  99, 99);
    path.cubicTo(0, 99,  50, 50,  0, 0);

    /*QPainter painter(this);
    painter.fillRect(0, 0, 100, 100, Qt::white);
    painter.setPen(QPen(QColor(79, 106, 25), 1, Qt::SolidLine,
                        Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QColor(122, 163, 39));

    painter.drawPath(path);*/

}
