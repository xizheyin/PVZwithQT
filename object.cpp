#include "object.h"

#include"Config.h"
#include"timectrl.h"
#include<QPainter>

Object::Object(int xx,int yy){
    walkmovie=nullptr;
    deadmovie=nullptr;
    myhp=myhpmax=-1;
    mytype=0;
    mystate=1;
    SetLoc(Location(xx,yy));
}

Object::Object(int xx,int yy,int hpmax,int ttype)
{
    walkmovie=nullptr;
    deadmovie=nullptr;
    myhp=myhpmax=hpmax;
    mytype=ttype;
    mystate=1;
    SetLoc(Location(xx,yy));
}


Object::~Object()
{
    if(walkmovie!=nullptr)delete walkmovie;
    if(deadmovie!=nullptr)delete deadmovie;
}



bool Object::IsPlant(){
    if(mytype>0&&mytype<=10)return true;
    else return false;
}

bool Object::IsZombie(){
    if(mytype>10&&mytype<=16)return true;
    else return false;
}


void Object::SetWalkMovie(QString mvpth){
    if(pth1==mvpth)return;
    if(walkmovie!=nullptr)delete  walkmovie;
    walkmovie=new QMovie(mvpth);
    pth1=mvpth;
    walkmovie->start();
}
void Object::SetDeadMovie(QString mvpth){
    if(pth2==mvpth)return;
    if(deadmovie!=nullptr)delete deadmovie;
    deadmovie=new QMovie(mvpth);
    pth2=mvpth;
    deadmovie->start();
}

bool Object::IsLive() const{
    return mystate;
}

//清除自己
void Object::ClearSelf(){
    scene()->removeItem(this);
}

void Object::CheckAndRemove(){
    if(!IsLive())ClearSelf();
}

Test::Test(int xx,int yy,int hpmax,int ttype)
    :Object(xx,yy,hpmax,ttype)
{
    qDebug()<<"植物构造函数";
}




void Test::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    qDebug()<<"enter Paint ps";

    if(walkmovie!=nullptr){
        qDebug()<<"Paint ps";
        painter->drawImage(boundingRect(),walkmovie->currentImage());
    }
    if(deadmovie!=nullptr){
        painter->drawImage(boundingRect(),deadmovie->currentImage());
    }
}
bool Test::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    return qFuzzyCompare(other->y(), y());
}
QRectF Test::boundingRect() const{
    return QRectF(-35,-35,70,70);
}
void Test::advance(int phase){


    qDebug()<<"Test advance";
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/Peashooter.gif");
        if(walkmovie!=nullptr)qDebug()<<x()<<" "<<y();
        //Attack(t);
    }


    this->QGraphicsItem::update();
}

