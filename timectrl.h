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
    void CreateZombies();
    void CreateZombie(int yy,int ttype);
private:
    void CreateNormalZombie(int yy);
    void CreateBarricadesZombie(int yy);
    void CreateClownZombie(int yy);
    void CreatePaperZombie(int yy);
    void CreatePolesZombie(int yy);

    long long int time;
    QGraphicsScene* scene;
    QTimer* timer;

};

#endif // TIMECTRL_H
