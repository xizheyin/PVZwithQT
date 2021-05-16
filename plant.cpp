#include "plant.h"
#include"bullet.h"

Plant::Plant(int xx,int yy,int hpmax,int ttype)
    :Object(xx,yy,hpmax,ttype)
{

}




void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(walkmovie!=nullptr){
        painter->drawImage(boundingRect(),walkmovie->currentImage());
    }
    if(deadmovie!=nullptr){
        painter->drawImage(boundingRect(),deadmovie->currentImage());
    }
}
bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    return other->y()== y()&&other->x()>x();
}
QRectF Plant::boundingRect() const{
    return QRectF(-35,-35,70,70);
}


PeaShooter::PeaShooter(int xx,int yy)
    :Plant(xx,yy,Hp_PeaShooter,PeaShooter_t)
{
    //qDebug()<<"豌豆射手构造函数";
}

void PeaShooter::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/Peashooter.gif");
        Attack(t);
    }
    else{
        this->QGraphicsItem::update();
    }
}

void PeaShooter::Attack(int t){
    if(t%PeaShooter_Atkgap==0){
        QList<QGraphicsItem*> list=collidingItems();
        for(int i=0;i<list.size();i++){
            if(qgraphicsitem_cast<Object*>(list[i])->IsZombie()){
                Bullet* blt=new Bullet(this->XX+22,this->YY-15,normal_t);
                scene()->addItem(blt);
            }
        }

    }
}


DoubleShooter::DoubleShooter(int xx,int yy)
    :Plant(xx,yy,Hp_PeaShooter,PeaShooter_t)
{
}

void DoubleShooter::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/Repeater.gif");
        Attack(t);
    }
    else{
        this->QGraphicsItem::update();
    }
}

void DoubleShooter::Attack(int t){
    if(t%PeaShooter_Atkgap==0){
        QList<QGraphicsItem*> list=collidingItems();
        for(int i=0;i<list.size();i++){
            if(qgraphicsitem_cast<Object*>(list[i])->IsZombie()){
                Bullet* blt=new Bullet(this->XX+22,this->YY-15,normal_t);
                Bullet* blt2=new Bullet(this->XX+40,this->YY-15,normal_t);
                scene()->addItem(blt);
                scene()->addItem(blt2);
            }
        }
    }
}
