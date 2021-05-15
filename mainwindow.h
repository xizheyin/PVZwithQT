#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QMediaPlayer>
#include<QSound>
#include"timectrl.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene* scene;
    QGraphicsView * view;
    QTimer* timer;
    TimeCtrl* timectrl;
    QSound* startSound;
};
#endif // MAINWINDOW_H
