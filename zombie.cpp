#include<QList>


#include "zombie.h"
#include"Config.h"



Zombie::Zombie(int xx,int yy,int hpmax,int ttype)
    :Object(xx,yy,hpmax,ttype)
{
    //qDebug()<<"僵尸构造函数";
    isatking=false;
    burned=false;
    iced=false;
    speed=2;
    setZValue(10);
}



void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //qDebug()<<"enter Paint ps";

    if(walkmovie!=nullptr){
        //qDebug()<<"Paint ps";
        painter->drawImage(boundingRect(),walkmovie->currentImage());
    }
    if(deadmovie!=nullptr){
        painter->drawImage(boundingRect(),deadmovie->currentImage());
    }
}
bool Zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    return other->y()==y()&&abs(x()-other->x())<20;
}
QRectF Zombie::boundingRect() const{
    return QRectF(-50,-50,100,100);
}


void Zombie::Move(){
    if(!IsLive())return;
    qDebug()<<"移动，速度"<<speed;
    if(t%100==0){
        if(!isatking)
            SetX(GetX() - speed);
    }
}




//普通僵尸构造函数*******************************
NormalZombie::NormalZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_NormalZombie,NormalZombie_t)
{
    atk=NormalZombie_ATK;
}

void NormalZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void NormalZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            flag=1;
            break;
        }
    }
    if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }
}

void NormalZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/Burn.gif");
        }
        else{
            SetWalkMovie(":/resource/ZombieDie.gif");
            SetDeadMovie(":/resource/ZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            qDebug()<<"死掉了";
            ClearSelf();
        }
    }
    else{
        if(!isatking)SetWalkMovie(":/resource/ZombieWalk1.gif");
        else SetWalkMovie(":resource/ZombieAttack.gif");
    }
}


BarricadesZombie::BarricadesZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_NormalZombie,NormalZombie_t)
{
    atk=NormalZombie_ATK;
}

void BarricadesZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void BarricadesZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            flag=1;
            break;
        }
    }
    if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }
}

void BarricadesZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/Burn.gif");
        }
        else{
            SetWalkMovie(":/resource/ZombieDie.gif");
            SetDeadMovie(":/resource/ZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            ClearSelf();
        }
    }
    else{
        if(myhp>myhpmax/2){
            if(!isatking)SetWalkMovie(":/resource/ScreenZombieWalk.gif");
            else SetWalkMovie(":resource/ScreenZombieAttack.gif");
        }
        else{
            if(!isatking)SetWalkMovie(":/resource/ZombieWalk1.gif");
            else SetWalkMovie(":resource/ZombieAttack.gif");
        }
    }
}



