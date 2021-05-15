#ifndef TIMECTRL_H
#define TIMECTRL_H
#include<Config.h>
#include<QObject>


extern int t;

class TimeCtrl:public QObject
{
    Q_OBJECT

public:
    TimeCtrl();
    void Update();

private:
    long long int time;

};

#endif // TIMECTRL_H
