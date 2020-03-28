#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    // 窗口设置
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("选择关卡");

    // 创建菜单栏
    QMenuBar *bar = this->menuBar();
    this->setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    // 返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton", ":/res/BackButtonSelected");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(), this->height()-backBtn->height());
    connect(backBtn, &MyPushButton::clicked, [=](){
        QSound* backSound = new QSound(":/res/BackButtonSound.wav", this);
        backSound->play();
        QTimer::singleShot(500, this, [=](){
            emit this->chooseSceneBack();
        });
    });

    // 创建关卡
    for(int i=0; i<20; i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+(i%4)*70, 130+(i/4)*70);

        // 监听选择关卡按钮的信号槽
        connect(menuBtn, &MyPushButton::clicked, [=](){
            QSound* sound = new QSound(":/res/TapButtonSound.wav",this);
            sound->play();
            if(pScene==NULL)
            {
                this->hide();
                pScene = new PlayScene(i+1);
                pScene->setGeometry(this->geometry());
                pScene->show();

                // playScene 返回按键监听， 删除该scene并且将指针删除
                connect(pScene, &PlayScene::chooseSceneBack, [=](){
                    this->setGeometry(pScene->geometry());
                    this->show();
                    delete pScene;
                    pScene = NULL;
                });
            }
        });

        // 按键显示的文字
        QLabel *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignHCenter);
        label->move(25+(i%4)*70, 150+(i/4)*70);
        // 鼠标事件穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    // 背景设置
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    pix.scaled(this->width(), this->height());
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);

    // 标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}
