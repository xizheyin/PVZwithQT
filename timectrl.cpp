#include "timectrl.h"
#include<QList>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include "object.h"

int t=0;

TimeCtrl::TimeCtrl(QGraphicsScene* sc,QTimer* tm)
{
    scene=sc;
    timer=tm;
}


void TimeCtrl::Update(){
    time++;
    t=time;
    Check();
    if(time%Create_Zombie_Gap==0){
        //创建僵尸
    }


}


void TimeCtrl::Check(){
    QList<QGraphicsItem*> list=scene->items();
    for(int i=0;i<list.size();i++){
        Object* obj=qgraphicsitem_cast<Object*>(list[i]);
        if(obj->IsZombie()){
            if(obj->x()<=200){
                QPixmap img(QString(":/resource/ZombiesWon.png"));

                scene->addPixmap(img);
                //scene->setBackgroundBrush(img);
                timer->stop();
                        //setPixmap(QPixmap::fromImage(image));

            }

        }
    }

}
