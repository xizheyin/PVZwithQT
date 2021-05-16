#ifndef CARD_H
#define CARD_H

#include"object.h"
#include<QGraphicsSceneMouseEvent>
#include<QDrag>
#include<QMimeData>

class Card:public Object
{
public:
    Card(int xx,int yy,QString pth,int tt);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override{}
    void Cold(){coldtime=5000;}
private:
    QString imgpth;
    int coldtime;
    int ttype;
    bool canbuy;
};

#endif // CARD_H
