#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
#include <QWidget>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent=0);
    MyPushButton(QString normalImg, QString pressImg="");
    QString normalImgPath;  // 正常显示的路径
    QString pressedImgPath;   // 按下后显示的图片路径
    void zoom1();
    void zoom2();

    // 重写按键按下和释放事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:

};

#endif // MYPUSHBUTTON_H
