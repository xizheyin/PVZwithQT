#ifndef CONFIG_H
#define CONFIG_H
#include <QtGlobal>
#include<QDebug>
#include<QTime>
const int Window_Height=600;
const int Window_Width=950;

const int Create_Zombie_Gap=5000;


//豌豆射手初始hp
const int Hp_PeaShooter = 20;
//太阳花初始hp
const int Hp_SunFlower = 20;
//坚果墙初始hp
const int Hp_NutWall = 30;
//双发射手初始hp
const int HP_DoubleShooter = 20;
//寒冰射手初始hp
const int Hp_IceShooter = 20;
//高坚果
const int Hp_HighNut = 240;
//倭瓜
const int Hp_Squash = 20;
//樱桃
const int Hp_Cherry = 20;
//大蒜
const int Hp_Garlic = 20;
//南瓜
const int Hp_Pumpkin = 60;


//普通僵尸基础生命
const int Hp_NormalZombie = 30;
//路障僵尸基础生命
const int Hp_BarricadesZombie = 30;
//读报僵尸基础生命
const int Hp_PaperZombie = 30;
//撑杆僵尸基础生命
const int Hp_PolesZombie = 30;
//小丑僵尸基础生命
const int Hp_ClownZombie = 30;
//投石僵尸基础生命
const int Hp_CastZombie = 30;


//豌豆射手攻击gap
const int PeaShooter_Atkgap = 2000;
//产生阳光gap
const int SunFlower_Sungap = 20000;
//双发射手
const int TIME_GAP_DOUBLESHOOTER_ATTACK = 4;
//寒冰射手
const int TIME_GAP_ICESHOOTER_ATTACK = 4;
//Cherry的攻击倒计时
const int Cherry_ColdTime = 3000;


const int NormalZombie_ATK=10;



const int NormalBullet_Mvgap=30;
const int NormalBullet_Speed=6;


struct Location{
    int x,y;
    Location(int xx,int yy){x=xx;y=yy;}
    Location(const Location& rhs){x=rhs.x;y=rhs.y;}
};



enum{
    None_t=0,
    PeaShooter_t=1,
    SunFlower_t=2,
    NutWall_t=3,
    HighNut_t=4,
    DoubleShooter_t=5,
    IceShooter_t=6,
    Potato_t=7,
    Cherry_t=8,
    Garlic_t=9,
    Pumpkin_t=10,
    NormalZombie_t=11,
    BarricadesZombie_t=12,
    PaperZombie_t=13,
    PolesZombie_t=14,
    ClownZombie_t=15,
    CastZombie_t=16,


    Shop_t=30,

    Sun_t=40

};

enum{
  normal_t=0,
  ice_t=1,
  car_t=2
};


int GetMoney(int ttype);
int CurX(int x);
int CurY(int y);
int generateRandomNumber();


#endif // CONFIG_H
