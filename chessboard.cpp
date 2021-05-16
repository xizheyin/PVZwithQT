#include "chessboard.h"
#include<QList>


ChessBoard::ChessBoard(int xx,int yy):Object(xx,yy)
{
    shop=nullptr;
    setAcceptDrops(true);
}


QRectF ChessBoard::boundingRect() const{
    return QRectF(-320,-240,640,480);
}

void ChessBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //painter->drawPixmap(QRect(-350,-240,700,480), QPixmap(":/resource/ui.png"));

}


void ChessBoard::advance(int phase){
    //if(phase==1)update();
}


void ChessBoard::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
    qDebug()<<"拖动事件进入";
    if(event->mimeData()!=nullptr){
        qDebug()<<"接受";
        event->accept();
    }
    else {
        qDebug()<<"忽略";
        event->ignore();
    }
}

void ChessBoard::dragMoveEvent(QGraphicsSceneDragDropEvent *event) {
    qDebug()<<"接受拖动";
    event->accept();

}


void ChessBoard::dropEvent(QGraphicsSceneDragDropEvent *event) {
    qDebug()<<"放植物";
    const QMimeData* mdata=event->mimeData();
    int ittype = event->mimeData()->text().toInt();
    QPointF pos = mapToScene(event->pos());
    int curx=CurX(pos.x());
    int cury=CurY(pos.y());
    qDebug()<<curx<<" "<<cury;
    bool canput=true;
    bool pro=false;
    QList<QGraphicsItem*> list = scene()->items(QPoint(curx, cury));
    for(int i=0;i<list.size();i++){
        Object* obj=qgraphicsitem_cast<Object*>(list[i]);
        if(obj->IsPlant()){
            //看看是不是南瓜头
            canput=false;
        }
        else{

        }
    }
    if(!canput)event->ignore();
    else{//开始种植物了
        qDebug()<<"放植物aaaa";
        shop->CreatePlant(curx,cury,ittype);
    }
}
