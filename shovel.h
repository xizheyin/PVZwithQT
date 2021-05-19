#ifndef SHOVEL_H
#define SHOVEL_H
#include"object.h"
#include<QString>
class shovel:public Object
{
public:
    shovel();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)override;
    void advance(int phase)override{if(phase==0)update();}
    QRectF boundingRect() const override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override{}
private:
    QPixmap* img;
    QString imgpth;
};

#endif // SHOVEL_H
