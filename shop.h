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
    void CreateHighNut(int xx,int yy){HighNut* p=new HighNut(xx,yy);scene()->addItem(p);sun-=GetMoney(HighNut_t);}
    void CreateDoubleShooter(int xx,int yy){DoubleShooter* p=new DoubleShooter(xx,yy);scene()->addItem(p);sun-=GetMoney(DoubleShooter_t); }
    void CreateIceShooter(int xx,int yy){IceShooter* p=new IceShooter(xx,yy);scene()->addItem(p);sun-=GetMoney(IceShooter_t); }
    void CreatePotato(int xx,int yy){Potato* p=new Potato(xx,yy);scene()->addItem(p);sun-=GetMoney(Potato_t); }
    void CreateCherry(int xx,int yy){Cherry* p=new Cherry(xx,yy);scene()->addItem(p);sun-=GetMoney(Cherry_t); }
    void CreateGarlic(int xx,int yy){Garlic* p=new Garlic(xx,yy);scene()->addItem(p);sun-=GetMoney(Garlic_t); }
    void CreatePumpkin(int xx,int yy){Pumpkin* p=new Pumpkin(xx,yy);scene()->addItem(p);sun-=GetMoney(Pumpkin_t);}
    QPixmap* img;
    QList<Card*> cardlist;
    int sun;
};

#endif // SHOP_H
