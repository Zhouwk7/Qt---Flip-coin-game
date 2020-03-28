#include "playscene.h"
#include <QMenuBar>
#include "mypushbutton.h"
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include "mydata.h"
#include<QPropertyAnimation>
#include <QSound>

PlayScene::PlayScene(int index)
{
    this->levalIndex = index;
    qDebug() << "levelIndex: " << levalIndex << endl;
    this->setFixedSize(320, 588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币");

    //创建菜单栏
    QMenuBar *bar = this->menuBar();
    this->setMenuBar(bar);
    QMenu* startMenu = bar->addMenu("开始");
    QAction* quitAction = startMenu->addAction("退出");
    connect(quitAction, &QAction::triggered,[=](){
        this->close();
    });

    // 返回按钮
    MyPushButton* backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());
    connect(backBtn, &MyPushButton::clicked, [=](){
        QSound* sound = new QSound(":/res/TapButtonSound.wav",this);
        sound->play();
        QTimer::singleShot(500, this, [=](){
            this->hide();
            emit this->chooseSceneBack();
        });
    });

    // 当前关卡标题
    QLabel* label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = "Level: " + QString::number(this->levalIndex);
    label->setText(str);
    label->setGeometry(QRect(30, this->height()-50, 160, 50)); // 坐标x，坐标y, 字体所在框大小160*50

    // 成功图片
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width()-tmpPix.width())*0.5, -tmpPix.height());

    // 创建金币的背景图片，初始化二位数组
    MyData mydat;
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode(1).png"));
            label->setParent(this);
            label->move(57+i*50, 200+j*50);

            // 金币对象
            gameArray[i][j] = mydat.mmap[this->levalIndex][i][j];
            QString img;
            if(gameArray[i][j]==1)
            {
                img = ":/res/Coin0001.png";
            }
            else
            {
                img = ":/res/Coin0008.png";
            }
            MyCoin* coin = new MyCoin(img);
            coin->setParent(this);
            coin->move(59 + i*50, 203 + j*50);
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];
            coinBtn[i][j] = coin;
            // 监听点击事件，实现翻转
            connect(coin, &MyCoin::clicked, [=](){
                QSound* flidSound = new QSound(":/res/ConFlipSound.wav",this);
                flidSound->play();
                this->coinBtn[coin->posX][coin->posY]->changeFlag();
                this->gameArray[coin->posX][coin->posY] = this->gameArray[coin->posX][coin->posY]==0 ? 1:0;

                QTimer::singleShot(300, this, [=](){ // 有延时，需要注意时序
                    if(coin->posX+1 <= 3){
                        this->coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY]==0 ? 1:0;
                    }
                    if(coin->posX-1 >= 0){
                        this->coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY]==0 ? 1:0;
                    }
                    if(coin->posY+1 <= 3){
                        this->coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1]==0 ? 1:0;
                    }
                    if(coin->posY-1 >= 0){
                        this->coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1]==0 ? 1:0;
                    }

                    // 判断游戏成功
                    this -> isWin = true;
                    for(int i=0; i<4; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            if(this->gameArray[i][j]==0)
                            {
                                this->isWin = false;
                                //qDebug() << "不胜利";
                                break;
                            }
                        }
                        if(this->isWin == false) break;
                    }
                    if(this->isWin)
                    {
                        //qDebug() << "胜利";
                        // 加载胜利图片
                        QSound* winSound = new QSound(":/res/LevelWinSound.wav");
                        winSound->play();
                        QPropertyAnimation* animatioa1 = new QPropertyAnimation(winLabel, "geometry");
                        animatioa1->setDuration(1000);
                        animatioa1->setStartValue(QRect(winLabel->x(), winLabel->y(),winLabel->width(), winLabel->height()));
                        animatioa1->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        animatioa1->setEasingCurve(QEasingCurve::OutBounce);
                        animatioa1->start();
                        // 使得点击翻转按钮无效
                        for(int i=0; i<4; i++)
                        {
                            for(int j=0; j<4; j++)
                            {
                                coinBtn[i][j]->isWin = true;
                            }
                        }
                    }

                });

            });
        }
    }


}

void PlayScene::paintEvent(QPaintEvent *)
{
    // 加背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    // 加标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
