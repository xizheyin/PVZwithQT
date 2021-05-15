#include "mainwindow.h"
#include "Config.h"
#include"plant.h"
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
    this->timectrl=new TimeCtrl();
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
    PeaShooter* a=new PeaShooter(290,120);
    PeaShooter* b=new PeaShooter(290,220);
    PeaShooter* c=new PeaShooter(290,320);
    PeaShooter* d=new PeaShooter(290,420);
    PeaShooter* e=new PeaShooter(290,520);
    PeaShooter* f=new PeaShooter(370,120);
    PeaShooter* g=new PeaShooter(450,120);
    PeaShooter* h=new PeaShooter(530,120);
    PeaShooter* i=new PeaShooter(610,120);
    PeaShooter* j=new PeaShooter(690,120);
    PeaShooter* k=new PeaShooter(770,120);

    scene->addItem(a);
    scene->addItem(b);
    scene->addItem(c);
    scene->addItem(d);
    scene->addItem(e);
    scene->addItem(f);
    scene->addItem(g);
    scene->addItem(h);
    scene->addItem(i);
    scene->addItem(j);
    scene->addItem(k);

    //scene->addItem(ts);
    scene->advance();
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

