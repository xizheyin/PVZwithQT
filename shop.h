#ifndef SHOP_H
#define SHOP_H
#include"object.h"
#include<QPixmap>
#include"card.h"
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
private:
    QPixmap* img;
    QList<Card*> cardlist;
    int sun;
};

#endif // SHOP_H
