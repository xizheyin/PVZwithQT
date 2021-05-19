#include "shovel.h"
#include<QDrag>
#include<QMimeData>



shovel::shovel():Object(1050,40)
{
    img=new QPixmap(":/resource/Shovel.png");
    imgpth=QString(":/resource/Shovel.png");
}

void shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRect rect=QRect(-15,-15,30,30);
    painter->scale(2.0, 2.0);
    if (img)painter->drawPixmap(rect, *img);
}



QRectF shovel::boundingRect() const{
    return QRectF(-15,-15,30,30);
}

void shovel::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"按下鼠标！";

    QDrag* drag = new QDrag(this);
    QMimeData* mime = new QMimeData;
    QPixmap image(imgpth);
    image = image.scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放
    mime->setText(QString("remove"));
    drag->setHotSpot(QPoint(1,1));
    drag->setMimeData(mime);
    drag->setPixmap(image);
    drag->exec();
}
