#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QMediaPlayer>
#include<QSound>
#include"timectrl.h"
#include"shop.h"
#include"chessboard.h"

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
    Shop* shop;
    TimeCtrl* timectrl;
    QSound* startSound;
    ChessBoard* chessbd;
};
#endif // MAINWINDOW_H
