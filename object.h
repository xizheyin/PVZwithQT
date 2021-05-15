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

    int SetType();
    int GetType();
    bool IsPlant();
    bool IsZombie();

    void SetWalkMovie(QString mvpth);//gif动画
    void SetDeadMovie(QString);//gif动画
    bool IsLive()const;//判断是不是还活着
    void ClearSelf();//把自己从scene里清除
    void CheckAndRemove();//检查是不是死了，死了就清除自己

    void IsAttacked(int atk){myhp-=atk;if(myhp<=0)mystate=0;}
protected:
    enum { Tyype = UserType + 1 };
    int type() const override
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return Tyype;
    }
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


class Test : public Object
{
    Q_OBJECT
public:
    Test(int xx,int yy,int hpmax,int ttype);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    QRectF boundingRect() const override;
    void advance(int phrase) override;
protected:

private:
};








#endif // OBJECT_H

