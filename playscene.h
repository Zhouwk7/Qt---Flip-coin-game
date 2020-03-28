#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QPainter>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int index);
    void paintEvent(QPaintEvent *);
    int gameArray[4][4]; // 当前关卡数据
    MyCoin* coinBtn[4][4]; // 金币按钮数目

    // 游戏成功 flag
    bool isWin = true;
signals:
    void chooseSceneBack();
private:
    int levalIndex;
};

#endif // PLAYSCENE_H
