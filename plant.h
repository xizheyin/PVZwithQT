#ifndef PLANT_H
#define PLANT_H


#include<QPainter>
#include<QStyleOptionGraphicsItem>
#include<QWidget>

#include"object.h"
#include"timectrl.h"


class Plant : public Object
{
    Q_OBJECT
public:
    Plant(int xx,int yy,int hpmax,int ttype);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    QRectF boundingRect() const override;
protected:

private:
};


class PeaShooter : public Plant
{
    Q_OBJECT
public:
    PeaShooter(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
private:
};

class DoubleShooter : public Plant
{
    Q_OBJECT
public:
    DoubleShooter(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
private:
};


class SunFlower : public Plant
{
    Q_OBJECT
public:
    SunFlower(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
private:
};

class NutWall : public Plant
{
    Q_OBJECT
public:
    NutWall(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
    void CheckAndRemove()override;
private:
};

class Cherry : public Plant
{
    Q_OBJECT
public:
    Cherry(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)override;
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void CheckAndRemove()override;
private:
};


class Potato : public Plant
{
    Q_OBJECT
public:
    Potato(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void CheckAndRemove()override;
private:
    int coldtime;
};


class IceShooter : public Plant
{
    Q_OBJECT
public:
    IceShooter(int xx,int yy);
    void advance(int phase) override;
    void Attack(int t);
private:
};










#endif // PLANT_H
