#ifndef BULLET_H
#define BULLET_H

#include"object.h"




class Bullet : public Object
{


public:
    Bullet(int xx,int yy,int fun);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    QRectF boundingRect() const;
    void Attack();
    void Move();
    void CheckAndRemove();//检查是不是死了，死了就清除自己
private:
    int func;
    int ice;
    QPixmap* img;
};

#endif // BULLET_H
