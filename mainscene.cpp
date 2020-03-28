#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    // 设置窗口大小
    this->setFixedSize(320,588);
    // 设置窗口小图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    // 设置窗口标题
    this->setWindowTitle("翻金币游戏");
    connect(ui->actionQuit, &QAction::triggered, [=](){this->close();});

    // 开始按钮
    chooseScene = new ChooseLevelScene;
    MyPushButton *startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5, this->height()*0.7); // 将 start 图片放在 x 轴中间，y 轴 0.7位置处
    connect(startBtn, &MyPushButton::clicked, [=](){
        QSound *startSound = new QSound(":/res/TapButtonSound.wav", this);
        startSound->play();
        startBtn->zoom1();  // 向上跳跃
        startBtn->zoom2();  // 向下跳跃
        QTimer::singleShot(500, this, [=](){
            // 自身隐藏
            this->hide();
            // 显示选择关卡
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();
        });
    });

    // 返回按钮
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, [=](){
       this->setGeometry(chooseScene->geometry());
       chooseScene->hide();
       this->show();
    });
}

void MainScene::paintEvent(QPaintEvent *)
// 架子啊MainScene界面是会调用该函数
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

MainScene::~MainScene()
{
    delete ui;
}

