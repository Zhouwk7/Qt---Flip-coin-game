#include "mypushbutton.h"
#include<QPushButton>
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    normalImgPath = normalImg;
    pressedImgPath = pressImg;
    QPixmap pixmap;
    bool ret = pixmap.load(normalImgPath);
    if(!ret)
    {
        qDebug() << normalImg << "加载图片失效" << endl;
    }
    this->setFixedSize(pixmap.width(), pixmap.height());
    // 设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
}

void MyPushButton::zoom1()
{
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    animation1->setDuration(200);
    // 设置初始位置
    animation1->setStartValue(QRect(this->x(), this->y(),this->width(),this->height()));
    // 设置末位置
    animation1->setEndValue(QRect(this->x(), this->y()+10,this->width(),this->height()));
    // 设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    // 开始执行动漫
    animation1->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation *animation1 = new QPropertyAnimation(this, "geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    animation1->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(pressedImgPath != "")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(pressedImgPath);
        if(!ret)
        {
            qDebug() << pressedImgPath << "加载图片失败" << endl;
        }
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:Opx;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(normalImgPath != "")
    {
        QPixmap pixmap;
        bool ret = pixmap.load(normalImgPath);
        if(!ret)
        {
            qDebug() << normalImgPath << "加载图片失败" << endl;
        }
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:Opx;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    }
    QPushButton::mouseReleaseEvent(e);
}
