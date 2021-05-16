#include "shop.h"
#include"plant.h"

Shop::Shop()
{
    sun=10000;
    img = new QPixmap(":/resource/Shop.png");
    setPos(600,30);
    mytype=Shop_t;
}

Shop::~Shop()
{
    if (img!=nullptr) delete img;
}

QRectF Shop::boundingRect() const
{
    return QRectF(-200, -30, 400, 60);
}

void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if (img!=nullptr) painter->drawPixmap(QRect(-270, -45, 540, 90), *img);
    QFont font;
    font.setPointSizeF(10);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

void Shop::advance(int phase)
{
    if(phase==1)
        update();
}

void Shop::CreateCard(){
    Card* c1=new Card(450,30,":/resource/Peashooter.png",PeaShooter_t);
    Card* c2=new Card(500,30,":/resource/SunFlower.png",SunFlower_t);
    Card* c3=new Card(550,30,":/resource/WallNut.png",NutWall_t);

    scene()->addItem(c1);cardlist.append(c1);
    scene()->addItem(c2);cardlist.append(c2);
    scene()->addItem(c3);cardlist.append(c3);
}

void Shop::CreatePlant(int xx,int yy,int ttype){
    qDebug()<<"即将放置 : "<<ttype;
    cardlist[ttype-1]->Cold();
    switch (ttype) {
    case PeaShooter_t:CreatePeaShooter(xx,yy);break;
    case SunFlower_t:CreateSunFlower(xx,yy);break;
    case NutWall_t:CreateNutWall(xx,yy);break;
    /*case HighNut_t:;
    case DoubleShooter_t:;
    case IceShooter_t:;
    case Squash_t:;
    case Cherry_t:;
    case Garlic_t:;
    case Pumpkin_t:;*/
    }
    return;
}
