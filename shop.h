#ifndef SHOP_H
#define SHOP_H
#include"object.h"
#include<QPixmap>
#include"card.h"
#include"plant.h"
#include<QList>
class Shop : public Object
{
public:
    Shop();
    ~Shop();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int phase);
    void CreateCard();
    void CreatePlant(int xx,int yy,int ttype);

    void RecvSun(){sun+=100;}
private:
    void CreatePeaShooter(int xx,int yy){PeaShooter* p1=new PeaShooter(xx,yy);scene()->addItem(p1);sun-=GetMoney(PeaShooter_t); }
    void CreateSunFlower(int xx,int yy){SunFlower* p2=new SunFlower(xx,yy);scene()->addItem(p2);sun-=GetMoney(SunFlower_t); }
    void CreateNutWall(int xx,int yy){NutWall* p=new NutWall(xx,yy);scene()->addItem(p);sun-=GetMoney(NutWall_t); }

    QPixmap* img;
    QList<Card*> cardlist;
    int sun;
};

#endif // SHOP_H
