#ifndef OBJECT_H
#define OBJECT_H

#include<QObject>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QMovie>
#include<QString>
#include<QPainter>

#include"Config.h"

class Object : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    Object(){}
    Object(int xx,int yy);
    Object(int xx,int yy,int hpmax,int ttype);
    ~Object();

    //位置信息
    void SetX(int xx){XX=xx;this->setPos(XX,YY);}
    void SetY(int yy){YY=yy;this->setPos(XX,YY);}
    void SetLoc(const Location& loc){XX=loc.x;YY=loc.y;this->setPos(XX,YY);}
    int GetX()const{return XX;}
    int GetY()const{return YY;}
    Location GetLoc()const{return Location(XX,YY);}

    void SetType(int tt){mytype=tt;}
    int GetType(){return mytype;}
    bool IsPlant();
    bool IsZombie();
    bool IsShop(){return mytype==Shop_t;}

    void SetWalkMovie(QString mvpth);//gif动画
    void SetDeadMovie(QString);//gif动画
    bool IsLive()const;//判断是不是还活着
    void ClearSelf();//把自己从scene里清除
    virtual void CheckAndRemove();//检查是不是死了，死了就清除自己


    bool PlayMovieEnd1(){return walkmovie->frameCount() - 1 == walkmovie->currentFrameNumber();}
    bool PlayMovieEnd2(){return deadmovie->frameCount() - 1 == deadmovie->currentFrameNumber();}

    virtual void IsAttacked(int atk){myhp-=atk;qDebug()<<"剩余"<<myhp;if(myhp<=0)mystate=0;}
protected:
    QMovie *walkmovie,*deadmovie;
    QString pth1,pth2;
    //我的生命值
    int myhp;
    int myhpmax;
    //类型，在config里面有枚举
    int mytype;
    //状态，0是死，1是活
    bool mystate;
    //位置
    int XX,YY;
    int atk;
};










#endif // OBJECT_H

