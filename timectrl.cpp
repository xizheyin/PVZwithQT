#include "timectrl.h"

int t=0;

TimeCtrl::TimeCtrl()
{

}


void TimeCtrl::Update(){
    time++;
    t=time;

    if(time%Create_Zombie_Gap==0){
        //创建僵尸
    }


}
