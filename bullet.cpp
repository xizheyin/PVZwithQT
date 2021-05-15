#include<QPainter>
#include "bullet.h"
#include"object.h"
#include"timectrl.h"

Bullet::Bullet(int xx,int yy,int fun):Object(xx,yy)
{
    func=fun;
    img = new QPixmap(":/resource/Pea.png");
    switch (fun) {
    case normal_t:atk=10;
    case ice_t:atk=10;
    case car_t:atk=10000;
    }
}


void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRect rect=QRect(-10,-10,20,20);
    if (img)painter->drawPixmap(rect, *img);
}


bool Bullet::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    if(abs(x()-other->x())<30&&abs(y()-other->y())){
        return true;
    }
    else return false;
}

QRectF Bullet::boundingRect() const{
    return QRectF(-30,-30,60,60);
}

void Bullet::advance(int phase){
    if(phase==0){

        Attack();
        CheckAndRemove();
        Move();
    }
    else{
        update();
    }
}


void Bullet::Attack(){
    QList<QGraphicsItem*> list = collidingItems();
    for(int i=0;i<list.size();i++) {
        Object* tmp =qgraphicsitem_cast<Object*> (list[i]);
        if (tmp->IsZombie()) {
            tmp->IsAttacked(atk);
            tmp->IsAttacked(10000);
            qDebug()<< "bullet hit enemy!";
            return;
        }
    }
}

void Bullet::Move(){
    if(t%20==0)
        SetX(GetX()+1);
}
