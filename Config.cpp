#include"Config.h"



int GetMoney(int ttype){

    switch (ttype) {
    case PeaShooter_t:return 100;
    case SunFlower_t:return 100;
    case NutWall_t:return 100;
    case HighNut_t:return 100;
    case DoubleShooter_t:return 100;
    case IceShooter_t:return 100;
    case Squash_t:return 100;
    case Cherry_t:return 100;
    case Garlic_t:return 100;
    case Pumpkin_t:return 100;
    }
}


int CurX(int x){
    int n=(x-290)/80;
    return n*80+290;
}
int CurY(int y){
    int n=(y-130)/100;
    return n*100+130;
}
