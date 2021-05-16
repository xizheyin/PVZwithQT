#include "sun.h"
#include"shop.h"



Sun::Sun(int xx,int yy)
    :Plant(xx,yy,10000,Sun_t)
{

}
void Sun::advance(int phase){
    SetWalkMovie(":/resource/Sun.gif");
    update();
}
void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event){
    MoneyToShop();
    ClearSelf();
}


void Sun::MoneyToShop(){
    QList<QGraphicsItem*> list=scene()->items();
    for(int i=0;i<list.size();i++){
        Object* obj =qgraphicsitem_cast<Object*>(list[i]);
        if (obj->IsShop()){//收到阳光，加钱
            qgraphicsitem_cast<Shop*>(obj)->RecvSun();
        }
    }
}
