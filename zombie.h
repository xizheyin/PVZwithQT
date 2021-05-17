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
    bool Burn(){burned=true;}
    void Move();
    void Ice(){if(!iced){iced=true;speed=1;}}
protected:
    bool isatking;
    bool burned;
    int speed;
    bool iced;
private:
};


class NormalZombie:public Zombie
{
    Q_OBJECT
public:
    NormalZombie(int xx,int yy);
    void advance(int phrase) override;
    void Attack(int t);
    void CheckAndRemove()override;
};

class BarricadesZombie:public Zombie
{
    Q_OBJECT
public:
    BarricadesZombie(int xx,int yy);
    void advance(int phrase) override;
    void Attack(int t);
    void CheckAndRemove()override;
};









#endif // ZOMBIE_H
