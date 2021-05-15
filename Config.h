#ifndef CONFIG_H
#define CONFIG_H
#include<QDebug>
const int Window_Height=600;
const int Window_Width=950;

const int Create_Zombie_Gap=300;


//豌豆射手初始hp
const int Hp_PeaShooter = 15;
//太阳花初始hp
const int Hp_SunFlower = 20;
//坚果墙初始hp
const int Hp_NutWall = 120;
//双发射手初始hp
const int HP_DoubleShooter = 20;
//寒冰射手初始hp
const int Hp_IceShooter = 20;
//高坚果
const int Hp_HighNut = 240;
//倭瓜
const int Hp_Squash = 10;
//樱桃
const int Hp_Cherry = 20;
//大蒜
const int Hp_Garlic = 20;
//南瓜
const int Hp_Pumpkin = 120;


//豌豆射手攻击gap
const int TIME_GAP_PEASHOOTER_ATTACK = 2000;
//产生阳光gap
const int TIME_GAP_CREATESUN = 20;
//双发射手
const int TIME_GAP_DOUBLESHOOTER_ATTACK = 4;
//寒冰射手
const int TIME_GAP_ICESHOOTER_ATTACK = 4;




struct Location{
    int x,y;
    Location(int xx,int yy){x=xx;y=yy;}
    Location(const Location& rhs){x=rhs.x;y=rhs.y;}
};



enum{
    None=0,
    PeaShooter_t=1,
    SunFlower_t=2,
    NutWall_t=3,
    HighNut_t=4,
    DoubleShooter_t=5,
    IceShooter_t=6,
    Squash_t=7,
    Cherry_t=8,
    Garlic_t=9,
    Pumpkin_t=10,
    NormalZombie_t=11,
    BarricadesZombie_t=12,
    CastZombie_t=13,
    ClownZombie_t=14,
    PaperZombie_t=15,
    PolesZombie_t=16



};

enum{
  normal_t=0,
  ice_t=1,
  car_t=2
};



#endif // CONFIG_H
