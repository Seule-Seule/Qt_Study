#include "choosesence.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "movebutton.h"
#include <QTimer>
#include <QLabel>
#include "coin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSound>

ChooseSence::ChooseSence(int leveln) : QMainWindow()
{
    // 配置游戏主场景
    // 设置主窗口大小
    setFixedSize(600, 600);
    // 设置主窗口图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    // 设置标题
    setWindowTitle("翻金币");

    // 创建菜单栏
    QMenuBar * menBar  = menuBar();
    setMenuBar(menBar);

    // 创建菜单
    QMenu * startMenu = menBar->addMenu("开始");

    // 创建退出菜单项
    QAction * quitAction = startMenu->addAction("退出");

    // 点击退出，退出游戏
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });
    // 返回按钮音效
    QSound * backSound = new QSound(":/res/BackButtonSound.wav");
    QSound * flipCoinSound = new QSound(":/res/ConFlipSound.wav");
    QSound * winSound = new QSound(":/res/LevelWinSound.wav");
    // 返回按钮
    MoveButton * returnBtn = new MoveButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    returnBtn->setParent(this);
    returnBtn->move((this->width()-returnBtn->width()) * 0.5 ,( this->height()- returnBtn->height()) - 50);
    connect(returnBtn, &MoveButton::clicked, [=](){
        //qDebug() << "返回按钮按下！";
        backSound->play();
        // 延时发送返回信号
        QTimer::singleShot(500, this, [=](){
           emit this->returnBtnDown();
        });
    });

    // QString str = QString("choose %1 ").arg(leveln);
    // qDebug() << str;
    lavelIndex = leveln;

    // 显示当前关卡
    QString strLabel = QString("第%1关").arg(this->lavelIndex);
    QFont font;
    font.setFamily("楷体");
    font.setPointSize(16);
    QLabel * label = new  QLabel;
    label->setParent(this);
    label->setText(strLabel);
    // 设置字体
    label->setFont(font);
    label->setGeometry(20, this->width() - 130, 150, 50);


    // 加载胜利图片 放于窗口上方， 暂时不显示
    QLabel * winLabel  = new QLabel();
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setPixmap(tmpPix);
    winLabel->setGeometry(0,0, tmpPix.width(), tmpPix.height());
    winLabel->setParent(this);
    winLabel->move((this->width()-tmpPix.width())*0.5, -tmpPix.height());

    // 初始化游戏数据
    dataConfig config;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            this->gameArray[i][j] = config.mData[this->lavelIndex][i][j];
        }
    }
    for (int i = 0;i < 4;i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // 加载金币背景图
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel * label = new QLabel;
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move( 200+i*pix.width(), 200+j*pix.height() );

            // 加载金币
            QString str2;
            if (gameArray[i][j])
            {
                str2 = QString(":/res/Coin0001.png");
            }
            else
            {
                str2 = QString(":/res/Coin0008.png");
            }
            Coin * coin = new Coin(str2);
            coin->setParent(this);
            coin->move( 202+i*pix.width(), 204+j*pix.height() );

            // 记录每一个金币
            coinArray[i][j] = coin;
            coinArray[i][j]->isWin = false;

            // 记录信息
            coin->potX = i;
            coin->potY = j;
            coin->coinFlag = gameArray[i][j];

            // 连接鼠标点击事件
            connect(coin, &Coin::clicked, [=](){
                flipCoinSound->play();
                coin->falgChange();
                gameArray[i][j] = gameArray[i][j] == 0? 1:0;

                // 反转周围金币 延时
                QTimer::singleShot(300, this, [=](){
                    // 有按钮点下时禁止再一次点下按钮
                    for (int m = 0; m < 4 ; m++)
                    {
                        for (int n = 0; n < 4; n++)
                        {
                            coinArray[m][n]->isWin = true;
                        }
                    }

                    // 反转右侧金币
                  if (coin->potX +1 <= 3)
                  {
                      coinArray[coin->potX+1][coin->potY]->falgChange();
                      gameArray[coin->potX+1][coin->potY] = gameArray[coin->potX+1][coin->potY] == 0? 1:0;
                  }
                  // 反转左侧金币
                  if (coin->potX -1 >= 0)
                  {
                      coinArray[coin->potX-1][coin->potY]->falgChange();
                      gameArray[coin->potX-1][coin->potY] = gameArray[coin->potX-1][coin->potY] == 0? 1:0;
                  }
                  // 反转下侧金币
                  if (coin->potY +1 <= 3)
                  {
                      coinArray[coin->potX][coin->potY+1]->falgChange();
                      gameArray[coin->potX][coin->potY+1] = gameArray[coin->potX][coin->potY+1] == 0? 1:0;
                  }
                  // 反转上侧金币
                  if (coin->potY -1 >= 0)
                  {
                      coinArray[coin->potX][coin->potY-1]->falgChange();
                      gameArray[coin->potX][coin->potY-1] = gameArray[coin->potX][coin->potY-1] == 0? 1:0;
                  }

                  // 按钮将反转完成，开启按钮
                  for (int m = 0; m < 4 ; m++)
                  {
                      for (int n = 0; n < 4; n++)
                      {
                          coinArray[m][n]->isWin = false;
                      }
                  }

                  // 翻转完成后 进行胜利检验
                  this->isWin = true;
                  for (int m = 0; m < 4 ; m++)
                  {
                      for (int n = 0; n < 4; n++)
                      {
                          if (coinArray[m][n]->coinFlag == false) // 只要有一个方面，没有胜利
                          {
                                this->isWin = false;
                                break;
                          }
                      }
                  }
                  if (this->isWin == true)
                  {
                       winSound->play();
                       qDebug() << "游戏胜利";
                       for (int m = 0; m < 4 ; m++)
                       {
                           for (int n = 0; n < 4; n++)
                           {
                               coinArray[m][n]->isWin = true;
                           }
                       }

                       // 胜利图片下移显示
                       QPropertyAnimation * animation = new QPropertyAnimation(winLabel, "geometry");
                       // 设置开始时间
                       animation->setStartValue(QRect(winLabel->x(), winLabel->y(),winLabel->width(),winLabel->height()));
                       // 设置结束时间
                       animation->setEndValue(QRect(winLabel->x(), winLabel->y()+200,winLabel->width(),winLabel->height()));
                       // 设置动画曲线
                       animation->setEasingCurve(QEasingCurve::OutBounce);
                       // 设置时间间隔
                       animation->setDuration(1000);
                       // 开始动画
                       animation->start();
                  }
                });

            });
        }
    }
}

void ChooseSence::paintEvent(QPaintEvent *)
{
    // 加载背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 加载小标题
    pix.load(":/res/Title.png");
    // pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap((this->width() - pix.width() ) * 0.5, 50, pix);
}
