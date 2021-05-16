#include "plant.h"
#include"bullet.h"
#include"sun.h"


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

SunFlower::SunFlower(int xx,int yy)
    :Plant(xx,yy,Hp_SunFlower,SunFlower_t)
{
}

void SunFlower::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/SunFlower.gif");
        Attack(t);
    }
    else{
        this->QGraphicsItem::update();
    }
}

//太阳花产生阳光
void SunFlower::Attack(int t){
    if(t%SunFlower_Sungap==0){
        Sun* s=new Sun(x()+10,y()+20);
        scene()->addItem(s);
    }
}


NutWall::NutWall(int xx,int yy)
    :Plant(xx,yy,Hp_NutWall,NutWall_t)
{
}

void NutWall::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
    }
    else{
        this->QGraphicsItem::update();
    }
}

void NutWall::CheckAndRemove(){
    if(!IsLive()){
        ClearSelf();
    }
    else{
        //分别以2/3和1/3为分界，更换动画
        qDebug()<<myhp<<" "<<myhpmax;
        if(myhp>=(2*myhpmax/3)){
            SetWalkMovie(":/resource/WallNut.gif");
        }
        else if(myhp<(2*myhpmax/3)&&myhp>=(myhpmax/3)){
            SetWalkMovie(":/resource/WallNut1.gif");
        }
        else{
            SetWalkMovie(":/resource/WallNut2.gif");
        }
    }

}




