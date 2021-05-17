#include "mainwindow.h"
#include "Config.h"
#include"plant.h"
#include"zombie.h"
#include"shop.h"
#include"chessboard.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QTimer>
#include<QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //初始化成员变量
    this->scene=new QGraphicsScene(150,0,Window_Width,Window_Height,this);
    this->view=new QGraphicsView(scene,this);
    this->timer=new QTimer(this);
    this->timectrl=new TimeCtrl(scene,timer);
    this->shop=new Shop;
    this->chessbd=new ChessBoard(600,320);
    scene->addItem(shop);
    scene->addItem(chessbd);
    shop->CreateCard();
    chessbd->SetShop(shop);
    //设定窗口大小
    this->setFixedSize(Window_Width,Window_Height);


    //禁用索引，防止运行缓慢
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);


    timer->start();

    view->resize(Window_Width+2,Window_Height+2);
    view->setBackgroundBrush(QPixmap(":/resource/Background.jpg"));

    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();

    startSound=new QSound(":/resource/Grazy Dave.wav");  //创建一个音乐播放器
    startSound->play();




    //宽80 高100
    //DoubleShooter* a=new DoubleShooter(290,120);
    //PeaShooter* a=new PeaShooter(650,130);
    //PeaShooter* b=new PeaShooter(290,230);
    //PeaShooter* c=new PeaShooter(380,230);
    //PeaShooter* d=new PeaShooter(290,430);
    //PeaShooter* e=new PeaShooter(290,530);

    //NormalZombie* z=new NormalZombie(700,120);
    BarricadesZombie* z=new BarricadesZombie(750,130);
    //scene->addItem(a);
    //scene->addItem(b);
    //scene->addItem(c);
    //scene->addItem(d);
    //scene->addItem(e);
    scene->addItem(z);
    //scene->addItem(ts);









    connect(timer,&QTimer::timeout,timectrl,&TimeCtrl::Update);
    connect(timer,&QTimer::timeout,scene,&QGraphicsScene::advance);

}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
    delete timer;
    delete timectrl;
    delete startSound;
}

