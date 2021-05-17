#include "card.h"
#include"Config.h"



Card::Card(int xx,int yy,QString pth,int tt)
{
    ttype=tt;
    imgpth=pth;
    coldtime=2000;
    setPos(xx,yy);
}


QRectF Card::boundingRect() const{
    return QRectF(-25,-40,50,80);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-25, -40, 50, 80), QPixmap(":/resource/Card.png"));
    painter->drawPixmap(QRect(-15, -20, 30, 40), QPixmap(imgpth));
    QFont font;
    font.setPointSizeF(8);
    painter->setFont(font);
    int cost=GetMoney(ttype);
    painter->drawText(-20, 35, QString().sprintf("%3d", cost));
    if (coldtime>0){
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-25, -40, 50, 80 * (coldtime /2000.0)));
    }
}


void Card::advance(int phase){
    if(phase==0){
        if(coldtime>0){
            coldtime--;
            canbuy=false;
        }
        else canbuy=true;
    }
        else update();
}


void Card::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"按下鼠标！";
    if (!canbuy){ event->ignore();return;}
    QDrag* drag = new QDrag(this);
    QMimeData* mime = new QMimeData;
    QImage image(imgpth);
    mime->setText(QString().sprintf("%d", ttype));
    //mime->setHtml(QString().sprintf("%d %d",getLocation().x, getLocation().y));
    drag->setHotSpot(QPoint(35, 35));
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->exec();
}


