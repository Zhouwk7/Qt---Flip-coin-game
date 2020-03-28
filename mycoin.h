#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    MyCoin(QString butImg); // butImg 图片路径
    int posX;   // x坐标
    int posY;   // y坐标
    bool flag; // 正反标志
    // 特效
    void changeFlag();
    QTimer* timer1;
    QTimer* timer2;
    int min = 1;
    int max = 8;

    // 做翻转动漫的标志
    bool isAnimation = false;

    // 重写按下按钮
    void mousePressEvent(QMouseEvent *e);

    // 胜利标志
    bool isWin = false;
};

#endif // MYCOIN_H
