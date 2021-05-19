#include "plant.h"
#include"bullet.h"
#include"sun.h"
#include"zombie.h"

Plant::Plant(int xx,int yy,int hpmax,int ttype)
    :Object(xx,yy,hpmax,ttype)
{
    setZValue(5);
}




void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    if(walkmovie!=nullptr){
        painter->drawImage(boundingRect(),walkmovie->currentImage());
    }
    if(deadmovie!=nullptr){
        painter->drawImage(boundingRect(),deadmovie->currentImage());
    }
}
bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    return other->y()== y()&&other->x()>x();
}
QRectF Plant::boundingRect() const{
    return QRectF(-35,-35,70,70);
}


PeaShooter::PeaShooter(int xx,int yy)
    :Plant(xx,yy,Hp_PeaShooter,PeaShooter_t)
{
    //qDebug()<<"豌豆射手构造函数";
}

void PeaShooter::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/Peashooter.gif");
        Attack(t);
    }
    else{
        this->QGraphicsItem::update();
    }
}

void PeaShooter::Attack(int t){
    if(t%PeaShooter_Atkgap==0){
        QList<QGraphicsItem*> list=collidingItems();
        for(int i=0;i<list.size();i++){
            if(qgraphicsitem_cast<Object*>(list[i])->IsZombie()){
                Bullet* blt=new Bullet(this->XX+20,this->YY-15,normal_t);
                scene()->addItem(blt);
            }
        }

    }
}


DoubleShooter::DoubleShooter(int xx,int yy)
    :Plant(xx,yy,Hp_PeaShooter,PeaShooter_t)
{
}

void DoubleShooter::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/Repeater.gif");
        Attack(t);
    }
    else{
        this->QGraphicsItem::update();
    }
}

void DoubleShooter::Attack(int t){
    if(t%PeaShooter_Atkgap==0){
        QList<QGraphicsItem*> list=collidingItems();
        for(int i=0;i<list.size();i++){
            if(qgraphicsitem_cast<Object*>(list[i])->IsZombie()){
                Bullet* blt=new Bullet(this->XX+22,this->YY-15,normal_t);
                Bullet* blt2=new Bullet(this->XX+40,this->YY-15,normal_t);
                scene()->addItem(blt);
                scene()->addItem(blt2);
            }
        }
    }
}

SunFlower::SunFlower(int xx,int yy)
    :Plant(xx,yy,Hp_SunFlower,SunFlower_t)
{
}

void SunFlower::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/SunFlower.gif");
        Attack(t);
    }
    else{
        this->QGraphicsItem::update();
    }
}

//太阳花产生阳光
void SunFlower::Attack(int t){
    if(t%SunFlower_Sungap==0){
        Sun* s=new Sun(x()+10,y()+20);
        scene()->addItem(s);
    }
}


NutWall::NutWall(int xx,int yy)
    :Plant(xx,yy,Hp_NutWall,NutWall_t)
{
}

void NutWall::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
    }
    else{
        this->QGraphicsItem::update();
    }
}

void NutWall::CheckAndRemove(){
    if(!IsLive()){
        ClearSelf();
    }
    else{
        //分别以2/3和1/3为分界，更换动画
        qDebug()<<myhp<<" "<<myhpmax;
        if(myhp>=(2*myhpmax/3)){
            SetWalkMovie(":/resource/WallNut.gif");
        }
        else if(myhp<(2*myhpmax/3)&&myhp>=(myhpmax/3)){
            SetWalkMovie(":/resource/WallNut1.gif");
        }
        else{
            SetWalkMovie(":/resource/WallNut2.gif");
        }
    }

}

Cherry::Cherry(int xx,int yy):Plant(xx,yy,Hp_Cherry,Cherry_t)
{
    inittime=t;
    qDebug()<<"樱桃构造函数";
}
void Cherry::advance(int phase){
    if(phase==0){
        CheckAndRemove();
        Attack(t);
    }
    else{
        update();
    }
}
void Cherry::Attack(int t){
    if((t-inittime)%Cherry_ColdTime!=0)return;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsZombie()){//如果是僵尸的话就攻击它
            qgraphicsitem_cast<Zombie*>(tmp)->Burn();
            tmp->IsAttacked(10000);
        }
    }
    this->IsAttacked(10000);
    return;
}

void Cherry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //painter->scale(0.6, 0.58);
    Plant::paint(painter,option,widget);
}


QRectF Cherry::boundingRect() const{
    return QRectF(-35,-35,70,70);
}
bool Cherry::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {
    return abs(x()-other->x())<100&&abs(y()-other->y())<=100;
    //this->QGraphicsItem::collidesWithItem(other,mode);
}

void Cherry::CheckAndRemove(){
    if(!IsLive()){

        SetWalkMovie(":/resource/Boom.gif");
        if(PlayMovieEnd1()){
            qDebug()<<"死掉了";
            ClearSelf();
        }
    }
    else{
        SetWalkMovie(":/resource/CherryBomb.gif");
    }
}


Potato::Potato(int xx,int yy):Plant(xx,yy,Hp_Cherry,Cherry_t)
{
    coldtime=5000;
    qDebug()<<"樱桃构造函数";
}
void Potato::advance(int phase){
    if(phase==0){
        coldtime--;
        CheckAndRemove();
        Attack(t);
    }
    else{
        update();
    }
}
void Potato::Attack(int t){
    if(coldtime>2500)return;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsZombie()){//如果是僵尸的话就攻击它
            qgraphicsitem_cast<Zombie*>(tmp)->Burn();
            tmp->IsAttacked(10000);
            this->IsAttacked(10000);
        }
    }

    return;
}
QRectF Potato::boundingRect() const{
    return QRectF(-20,-20,40,40);
}
bool Potato::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const {
    return y()==other->y()&&abs(x()-other->x())<45;
}

void Potato::CheckAndRemove(){
    if(!IsLive()){
        SetWalkMovie(":/resource/PotatoMineBomb.gif");
        if(PlayMovieEnd1()){
            qDebug()<<"死掉了";
            ClearSelf();
        }
    }
    else{
        if(coldtime>2500){
            SetWalkMovie(":/resource/PotatoMine1.gif");
        }
        else
            SetWalkMovie(":/resource/PotatoMine.gif");
    }
}


IceShooter::IceShooter(int xx,int yy)
    :Plant(xx,yy,Hp_IceShooter,IceShooter_t)
{
    //qDebug()<<"豌豆射手构造函数";
}

void IceShooter::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
        SetWalkMovie(":/resource/SnowPea.gif");
        Attack(t);
    }
    else{
        this->QGraphicsItem::update();
    }
}

void IceShooter::Attack(int t){
    if(t%PeaShooter_Atkgap==0){
        QList<QGraphicsItem*> list=collidingItems();
        for(int i=0;i<list.size();i++){
            if(qgraphicsitem_cast<Object*>(list[i])->IsZombie()){
                Bullet* blt=new Bullet(this->XX+22,this->YY-15,ice_t);
                scene()->addItem(blt);
            }
        }

    }
}


HighNut::HighNut(int xx,int yy)
    :Plant(xx,yy,Hp_HighNut,HighNut_t)
{
}


void HighNut::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->scale(1, 1.3);
    Plant::paint(painter,option,widget);
}

void HighNut::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
    }
    else{
        this->QGraphicsItem::update();
    }
}

void HighNut::CheckAndRemove(){
    if(!IsLive()){
        ClearSelf();
    }
    else{
        //分别以2/3和1/3为分界，更换动画
        qDebug()<<myhp<<" "<<myhpmax;
        if(myhp>=(2*myhpmax/3)){
            SetWalkMovie(":/resource/Tallnut2.gif");
        }
        else if(myhp<(2*myhpmax/3)&&myhp>=(myhpmax/3)){
            SetWalkMovie(":/resource/Tallnut1.gif");
        }
        else{
            SetWalkMovie(":/resource/Tallnut3.gif");
        }
    }

}


Garlic::Garlic(int xx,int yy)
    :Plant(xx,yy,Hp_Garlic,Garlic_t)
{
}


void Garlic::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
    }
    else{
        this->QGraphicsItem::update();
    }
}

void Garlic::CheckAndRemove(){
    if(!IsLive()){
        ClearSelf();
    }
    else{
        //分别以2/3和1/3为分界，更换动画
        qDebug()<<myhp<<" "<<myhpmax;
        if(myhp>=(2*myhpmax/3)){
            SetWalkMovie(":/resource/Garlic.gif");
        }
        else if(myhp<(2*myhpmax/3)&&myhp>=(myhpmax/3)){
            SetWalkMovie(":/resource/Garlic_body2.gif");
        }
        else{
            SetWalkMovie(":/resource/Garlic_body3.gif");
        }
    }
}

Pumpkin::Pumpkin(int xx,int yy)
    :Plant(xx,yy,Hp_Pumpkin,Pumpkin_t)
{
    setZValue(8);
}

void Pumpkin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->scale(1, 0.7);
    Plant::paint(painter,option,widget);
}


void Pumpkin::advance(int phase){
    if(phase==0){//预备更新
        CheckAndRemove();
    }
    else{
        this->QGraphicsItem::update();
    }
}

void Pumpkin::CheckAndRemove(){
    if(!IsLive()){
        ClearSelf();
    }
    else{
        //分别以2/3和1/3为分界，更换动画
        qDebug()<<myhp<<" "<<myhpmax;
        if(myhp>=(2*myhpmax/3)){
            SetWalkMovie(":/resource/Pumpkin.gif");
        }
        else if(myhp<(2*myhpmax/3)&&myhp>=(myhpmax/3)){
            SetWalkMovie(":/resource/pumpkin1.gif");
        }
        else{
            SetWalkMovie(":/resource/Pumpkin2.gif");
        }
    }
}

QRectF Pumpkin::boundingRect() const {
    return QRectF(-35,-20,75,75);
}
