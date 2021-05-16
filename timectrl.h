#ifndef TIMECTRL_H
#define TIMECTRL_H
#include<Config.h>
#include<QObject>
#include<QGraphicsScene>
#include<QTimer>

extern int t;

class TimeCtrl:public QObject
{
    Q_OBJECT

public:
    TimeCtrl(QGraphicsScene* sc,QTimer* tm);
    void Update();
    void Check();

private:
    long long int time;
    QGraphicsScene* scene;
    QTimer* timer;

};

#endif // TIMECTRL_H
