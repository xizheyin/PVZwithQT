#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include"shop.h"
#include"object.h"
#include<QGraphicsSceneDragDropEvent>
#include<QMimeData>

class ChessBoard : public Object
{
public:
    ChessBoard(int xx,int yy);
    void SetShop(Shop* s){shop=s;}
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
private:
    Shop* shop;

};

#endif // CHESSBOARD_H
