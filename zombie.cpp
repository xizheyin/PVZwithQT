#include<QList>


#include "zombie.h"
#include"Config.h"

//僵尸构造函数
Zombie::Zombie(int xx,int yy,int hpmax,int ttype)
    :Object(xx,yy,hpmax,ttype)
{
    isatking=false;
    burned=false;
    iced=false;
    speed=2;
    step=20;
    change=0;
    setZValue(10);
}


//绘制僵尸，身体和死亡时的头部
void Zombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    if(walkmovie!=nullptr){
        painter->drawImage(boundingRect(),walkmovie->currentImage());
    }
    if(deadmovie!=nullptr){
        painter->drawImage(boundingRect(),deadmovie->currentImage());
    }
}
bool Zombie::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
    return other->y()==y()&&abs(x()-other->x()-other->boundingRect().right())<10;
}
QRectF Zombie::boundingRect() const{
    return QRectF(-50,-50,100,100);
}


void Zombie::Move(){
    if(!IsLive())return;
    if(t%100==0){
        if(change!=0){
            if(change>0){
                SetY(GetY()+step);
                change-=step;
            }
            else if(change<0){
                SetY(GetY()-step);
                change+=step;
            }
            qDebug()<<change;
            return;
        }
        if(!isatking)
            SetX(GetX() - speed);
    }
}




//普通僵尸构造函数*******************************
NormalZombie::NormalZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_NormalZombie,NormalZombie_t)
{
    atk=NormalZombie_ATK;
}

void NormalZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void NormalZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            flag=1;
            if(change==0&&tmp->GetType()==Garlic_t){change=CheckRow();return;}
            break;
        }
    }
    if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }
}

void NormalZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/Burn.gif");
        }
        else{
            SetWalkMovie(":/resource/ZombieDie.gif");
            SetDeadMovie(":/resource/ZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            qDebug()<<"死掉了";
            ClearSelf();
        }
    }
    else{
        if(!isatking)SetWalkMovie(":/resource/ZombieWalk1.gif");
        else SetWalkMovie(":resource/ZombieAttack.gif");
    }
}


BarricadesZombie::BarricadesZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_NormalZombie,NormalZombie_t)
{
    atk=NormalZombie_ATK;
}

void BarricadesZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void BarricadesZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            flag=1;
            if(change==0&&tmp->GetType()==Garlic_t){change=CheckRow();return;}
            break;
        }
    }
    if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }
}

void BarricadesZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/Burn.gif");
        }
        else{
            SetWalkMovie(":/resource/ZombieDie.gif");
            SetDeadMovie(":/resource/ZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            ClearSelf();
        }
    }
    else{
        if(myhp>myhpmax/2){
            if(!isatking)SetWalkMovie(":/resource/ScreenZombieWalk.gif");
            else SetWalkMovie(":resource/ScreenZombieAttack.gif");
        }
        else{
            if(!isatking)SetWalkMovie(":/resource/ZombieWalk1.gif");
            else SetWalkMovie(":resource/ZombieAttack.gif");
        }
    }
}

PaperZombie::PaperZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_PaperZombie,PaperZombie_t)
{
    atk=NormalZombie_ATK;
}

void PaperZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->scale(1.2, 1.2);
    Zombie::paint(painter,option,widget);
}

void PaperZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        if(myhp<myhpmax/2){speed=4;}
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void PaperZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            flag=1;
            if(change==0&&tmp->GetType()==Garlic_t){change=CheckRow();return;}
            break;
        }
    }
    if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }
}

void PaperZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/Burn.gif");
        }
        else{
            SetWalkMovie(":/resource/ZombieDie.gif");
            SetDeadMovie(":/resource/ZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            ClearSelf();
        }
    }
    else{
        if(myhp>myhpmax/2){
            if(!isatking)SetWalkMovie(":/resource/NewspaperZombie1.gif");
            else SetWalkMovie(":/resource/NewspaperZombieAttack1.gif");
        }
        else{
            if(!isatking)SetWalkMovie(":/resource/NewspaperZombie2.gif");
            else SetWalkMovie(":/resource/NewspaperZombieAttack2.gif");
        }
    }
}

PolesZombie::PolesZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_PolesZombie,PolesZombie_t)
{
    atk=NormalZombie_ATK;
    jmp=0;
    j1=false;
}

void PolesZombie::Move(){
    if(jmp==1){//跳了第一次
        if(PlayMovieEnd1()){
            SetX(GetX() - speed);
            jmp=2;
            return;
        }
        else if(!PlayMovieEnd1()) return;
    }
    else if(jmp==2){
        if(PlayMovieEnd1()){
            jmp=3;
            speed=2;
        }
        else return;
    }

    if(jmp==0){//还没跳过
        QList<QGraphicsItem*> list=collidingItems();
        Object* tmp=nullptr;
        for(int i=0;i<list.size();i++){
            tmp=qgraphicsitem_cast<Object*>(list[i]);
            if(tmp->IsPlant()&&tmp->GetType()!=HighNut_t){//如果是植物的话就跳过它
                jmp=1;
                speed=90;
                return;
            }
        }
    }
    Zombie::Move();
}

void PolesZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void PolesZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            flag=1;
            if(change==0&&tmp->GetType()==Garlic_t){change=CheckRow();return;}
            break;
        }
    }
    if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }
}

void PolesZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/Burn.gif");
        }
        else{
            SetWalkMovie(":/resource/PoleVaultingZombieDie.gif");
            SetDeadMovie(":/resource/PoleVaultingZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            ClearSelf();
        }
    }
    else{
        if(jmp==3){
            if(!isatking)SetWalkMovie(":/resource/PoleVaultingZombieWalk.gif");
            else SetWalkMovie(":/resource/PoleVaultingZombieAttack.gif");
        }
        else if(jmp==1){
            SetWalkMovie(":/resource/PoleVaultingZombieJump.gif");
        }
        else if(jmp==2){
            SetWalkMovie(":/resource/PoleVaultingZombieJump2.gif");
        }
        else SetWalkMovie(":/resource/PoleVaultingZombie.gif");

    }
}

void PolesZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->scale(1.3, 1.3);
    Zombie::paint(painter,option,widget);
}




ClownZombie::ClownZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_PolesZombie,PolesZombie_t)
{
    atk=NormalZombie_ATK;
    qDebug()<<"小丑僵尸";
}



void ClownZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void ClownZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    int bomb=generateRandomNumber()%10;
    if(bomb==1){
        QList<QGraphicsItem*> list=collidingItems();
        Object* tmp=nullptr;
        for(int i=0;i<list.size();i++){
            tmp=qgraphicsitem_cast<Object*>(list[i]);
            if(tmp->IsPlant()){//如果是植物的话就攻击它
                tmp->IsAttacked(100000);
            }
        }
        IsAttacked(100000);
        Burn();
        return;
    }
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            flag=1;
            if(change==0&&tmp->GetType()==Garlic_t){change=CheckRow();return;}
            break;
        }
    }
    if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }
}

void ClownZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/baozha.gif");
        }
        else{
            SetWalkMovie(":/resource/Die.gif");
            SetDeadMovie(":/resource/ZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            ClearSelf();
        }
    }
    else{
        if(myhp>myhpmax/2){
            if(!isatking)SetWalkMovie(":/resource/Walk.gif");
            else SetWalkMovie(":/resource/Attack.gif");
        }
        else{
            if(!isatking)SetWalkMovie(":/resource/LostHead.gif");
            else SetWalkMovie(":/resource/LostHeadAttack.gif");
        }
    }
}

void ClownZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->scale(1.3, 1.3);
    Zombie::paint(painter,option,widget);
}




CastZombie::CastZombie(int xx,int yy)
    :Zombie(xx,yy,Hp_CastZombie,CastZombie_t)
{
    atk=NormalZombie_ATK;
}

void CastZombie::advance(int phase) {
    if(phase==0){//预备更新
        CheckAndRemove();
        Move();
        Attack(t);

    }
    else{
        this->QGraphicsItem::update();
    }
}
void CastZombie::Attack(int t){
    if(!IsLive())return;
    int flag=0;
    QList<QGraphicsItem*> list=collidingItems();
    Object* tmp=nullptr;
    for(int i=0;i<list.size();i++){
        tmp=qgraphicsitem_cast<Object*>(list[i]);
        if(tmp->IsPlant()){//如果是植物的话就攻击它
            tmp->IsAttacked(10000);
        }
    }
    /*if(flag==1)isatking=true;
    else isatking=false;
    if(t%2000==0&&isatking){
        tmp->IsAttacked(atk);
    }*/
}


void CastZombie::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->scale(2.0, 2.0);
    Zombie::paint(painter,option,widget);
}


void CastZombie::CheckAndRemove(){
    if(!IsLive()){
        if(burned){
            SetWalkMovie(":/resource/carBoomDie.gif");
        }
        else{
            SetWalkMovie(":/resource/cardie.gif");
            //SetDeadMovie(":/resource/ZombieHead.gif");
        }
        if(PlayMovieEnd1()){
            ClearSelf();
        }
    }
    else{
        if(myhp>2*myhpmax/3){
            SetWalkMovie(":/resource/car1.gif");
        }
        else if(myhp>myhpmax/3){
            SetWalkMovie(":/resource/car2.gif");
        }
        else{
            SetWalkMovie(":/resource/car3.gif");
        }
    }
}




