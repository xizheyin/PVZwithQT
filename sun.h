#ifndef SUN_H
#define SUN_H
#include"object.h"
#include"plant.h"

class Sun:public Plant
{
public:
    Sun(int xx,int yy);
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void MoneyToShop();

};

#endif // SUN_H
