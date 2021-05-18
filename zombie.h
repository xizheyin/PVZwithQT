#ifndef ZOMBIE_H
#define ZOMBIE_H

#include<QPainter>
#include<QStyleOptionGraphicsItem>
#include<QWidget>

#include"object.h"
#include"timectrl.h"


class Zombie:public Object
{
    Q_OBJECT
public:
    Zombie(int xx,int yy,int hpmax,int ttype);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    QRectF boundingRect() const override;
    void Burn(){burned=true;}
    virtual void Move();
    void Ice(){if(!iced){iced=true;speed=1;}}
    int CheckRow(){
        if(y()==130)return 100;
        else if(y()==530)return -100;
        else if(t%2==0)return 100;
        else return -100;
    }
protected:
    bool isatking;
    bool burned;
    int speed;
    bool iced;
    //是否改路
    int change;
    int step;
private:
};


class NormalZombie:public Zombie
{
    Q_OBJECT
public:
    NormalZombie(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
    void CheckAndRemove()override;
};

class BarricadesZombie:public Zombie
{
    Q_OBJECT
public:
    BarricadesZombie(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
    void CheckAndRemove()override;

};



class PaperZombie:public Zombie
{
    Q_OBJECT
public:
    PaperZombie(int xx,int yy);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)override;
    void advance(int phase) override;
    void Attack(int t);
    void CheckAndRemove()override;

};

class PolesZombie:public Zombie
{
    Q_OBJECT
public:
    PolesZombie(int xx,int yy);
    void advance(int phase) override;
    void Move()override;
    void Attack(int t);
    void CheckAndRemove()override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0)override;
    QRectF boundingRect() const override{
        return QRectF(-50,-50,100,90);
    }

private:
    int jmp;
    bool j1;
};

class ClownZombie:public Zombie
{
    Q_OBJECT
public:
    ClownZombie(int xx,int yy);
    void advance(int phase) override;

    void Attack(int t);
    void CheckAndRemove()override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0)override;
    QRectF boundingRect() const override{
        return QRectF(-50,-50,100,90);
    }

};

class CastZombie:public Zombie
{
    Q_OBJECT
public:
    CastZombie(int xx,int yy);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0)override;
    void advance(int phase) override;
    void Attack(int t);
    void CheckAndRemove()override;

};



#endif // ZOMBIE_H
