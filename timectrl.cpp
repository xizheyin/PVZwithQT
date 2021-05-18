#include "timectrl.h"
#include<QList>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include "object.h"
#include<random>
#include<time.h>
#include <QtGlobal>
#include"Config.h"
#include"zombie.h"
int t=0;

TimeCtrl::TimeCtrl(QGraphicsScene* sc,QTimer* tm)
{
    scene=sc;
    timer=tm;
}


void TimeCtrl::Update(){
    time++;
    t=time;
    //Check();
    if(time%Create_Zombie_Gap==0){
        //创建僵尸
        CreateZombies();
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

void TimeCtrl::CreateZombies(){
    int randnum=generateRandomNumber()%5;
    int rn1=(generateRandomNumber())%6;//根据僵尸的增加要修改！！！！！！！！！！！！！！！！！！！！！！！！！
    CreateZombie(130+randnum*100,rn1+11);
    //CreateZombie(130+randnum*100,5+11);
}

void TimeCtrl::CreateZombie(int yy,int ttype){
    switch(ttype){
    case NormalZombie_t:CreateNormalZombie(yy);break;
    case BarricadesZombie_t:CreateBarricadesZombie(yy);break;
    case PaperZombie_t:CreatePaperZombie(yy);break;
    case PolesZombie_t:CreatePolesZombie(yy);break;
    case ClownZombie_t:CreateClownZombie(yy);break;
    case CastZombie_t:CreateCastZombie(yy);break;
    }
}
void TimeCtrl::CreateNormalZombie(int yy){
    NormalZombie* zmb=new NormalZombie(1200,yy);
    scene->addItem(zmb);
}
void TimeCtrl::CreateBarricadesZombie(int yy){
    BarricadesZombie* zmb=new BarricadesZombie(1200,yy);
    scene->addItem(zmb);
}
void TimeCtrl::CreateClownZombie(int yy){
    ClownZombie* zmb=new ClownZombie(1200,yy);
    scene->addItem(zmb);
}
void TimeCtrl::CreatePaperZombie(int yy){
    PaperZombie* zmb=new PaperZombie(1200,yy);
    scene->addItem(zmb);
}
void TimeCtrl::CreatePolesZombie(int yy){
    PolesZombie* zmb=new PolesZombie(1200,yy);
    scene->addItem(zmb);
}

void TimeCtrl::CreateCastZombie(int yy){
    CastZombie* zmb=new CastZombie(1200,yy);
    scene->addItem(zmb);
}
