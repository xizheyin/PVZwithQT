#include "object.h"

#include"Config.h"
#include"timectrl.h"
#include<QPainter>
#include<QDebug>

Object::Object(int xx,int yy){
    walkmovie=nullptr;
    deadmovie=nullptr;
    myhp=myhpmax=1;
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
    if(mvpth==pth1)return;
    if(walkmovie!=nullptr){
        delete walkmovie;
    }
    walkmovie=new QMovie(mvpth);
    pth1=mvpth;
    //if(walkmovie!=nullptr)qDebug()<<"新的动画！";
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


