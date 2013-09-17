#ifndef GEAROBJ_H
#define GEAROBJ_H

#include <QGraphicsItem>

class gearObj : public QGraphicsItem
{
public:
    gearObj(QGraphicsItem *parent = NULL);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // GEAROBJ_H
