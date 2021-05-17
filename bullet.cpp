#include<QPainter>
#include "bullet.h"
#include"object.h"
#include"zombie.h"
#include"timectrl.h"
#include"Config.h"

Bullet::Bullet(int xx,int yy,int fun):Object(xx,yy)
{
    setZValue(15);
    func=fun;
    img = new QPixmap(":/resource/Pea.png");
    ice=false;
    switch (fun) {
    case normal_t:atk=1;break;
    case ice_t:atk=1;ice=true;delete img;img=new QPixmap(":/resource/PeaSnow.png");break;
    case car_t:atk=10000;break;
    }
}


void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRect rect=QRect(-10,-10,20,20);
    if (img)painter->drawPixmap(rect, *img);
}


bool Bullet::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    if(abs(x()-other->x())<30&&abs(y()-other->y())<30){
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
            this->IsAttacked(atk);
            //tmp->IsAttacked(10000);
            if(func==ice_t){
                qDebug()<< "冻住!";
                static_cast<Zombie*>(tmp)->Ice();
            }
            qDebug()<< "子弹攻击敌人!";
            return;
        }
    }
}

void Bullet::Move(){
    if(t%NormalBullet_Mvgap==0)
        SetX(GetX()+NormalBullet_Speed);
}

void Bullet::CheckAndRemove(){
    Object::CheckAndRemove();
    if(y()>800)scene()->removeItem(this);
}
