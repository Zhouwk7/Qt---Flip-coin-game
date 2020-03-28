#include "mycoin.h"
#include <QDebug>
MyCoin::MyCoin(QString butImg)
{
    QPixmap pixmap;
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    bool ret = pixmap.load(butImg);
    if(!ret)
    {
        qDebug() << butImg << "加载图片失败！";
    }
    this -> setFixedSize(pixmap.width(), pixmap.height());
    this -> setStyleSheet("QPushButton{border:Opx;}");
    this -> setIcon(pixmap);
    this -> setIconSize(QSize(pixmap.width(),pixmap.height()));

    // 监听正面翻转的信号槽
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1.png").arg((this->min)++);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border:Opx;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        if(this->min > this->max)
        {
            this->min = 1;
            timer1->stop();
            this->isAnimation = false;
        }
    });
    // 监听反面翻转的信号槽
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1").arg((this->max)--);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(),pixmap.height());
        this->setStyleSheet("QPushButton{border;Opx;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
        if(this->max < this->min)
        {
            this->max = 8;
            timer2->stop();
            this->isAnimation = false;
        }
    });
}

void MyCoin::changeFlag()
{
    this->isAnimation = true;
    if(this->flag)
    {
        timer1->start(30);
        this->flag = false;
    }
    else
    {
        timer2 -> start(30);
        this->flag = true;
    }
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation||isWin==true)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}
