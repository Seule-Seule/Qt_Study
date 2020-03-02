#include "chooseleve.h"
#include <QPainter>
#include <QPixmap>
#include <QMenuBar>
#include "movebutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include "choosesence.h"
#include <QSound>

chooseLeve::chooseLeve(QWidget *parent) : QMainWindow(parent)
{
    // 配置选择关卡场景
    // 设置主窗口大小
    setFixedSize(600, 600);
    // 设置主窗口图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    // 设置标题
    setWindowTitle("选择关卡");

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

    // 选择关卡按钮音效
    QSound * chooseLaveaSound = new QSound(":/res/TapButtonSound.wav");
    // 返回按钮音效
    QSound * backSound = new QSound(":/res/BackButtonSound.wav");
    // 返回按钮
    MoveButton * returnBtn = new MoveButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    returnBtn->setParent(this);
    returnBtn->move((this->width()-returnBtn->width()) * 0.5 ,( this->height()- returnBtn->height()) - 50);
    connect(returnBtn, &MoveButton::clicked, [=](){
        backSound->play();

        // qDebug() << "返回按钮按下！";
        // 延时发送返回信号
        QTimer::singleShot(500, this, [=](){
            emit this->returnBtnDown();
        });
    });


    // 关卡创建
    for (int i = 0; i < 20; i++)
    {
        MoveButton * guanqiaBtn = new MoveButton(":/res/LevelIcon.png");
        guanqiaBtn->setParent(this);
        guanqiaBtn->move(95 + i%4 * 120, 170 + i/4 * 60);


        // 选择关卡
        connect(guanqiaBtn, &QPushButton::clicked, [=](){
            chooseLaveaSound->play();
            //QString str = QString("choose %1 ").arg(i+1);
            //qDebug() << str;

            this->hide();  // 隐藏选择关卡窗口
            levelnum = new ChooseSence(i+1);
            // 设置游戏界面位置
            levelnum->setGeometry(this->geometry());
            levelnum->show(); // 显示游戏界面

            // 连接游戏界面返回信号
            connect(levelnum, &ChooseSence::returnBtnDown, [=](){
                // qDebug() << "游戏界面返回！";
                // 设置返回位置
                this->setGeometry(levelnum->geometry());

                // 显示选择关卡场景
                this->show();
                // 删除游戏场景
                delete levelnum;
                levelnum = NULL;
            });

        });



        // 关卡标签
        QLabel * label = new QLabel;
        label->setFixedSize(guanqiaBtn->width(), guanqiaBtn->height());
        label->setParent(this);
        label->setText(QString::number(i+1));
        label->move( 95 + i%4 * 120, 170 + i/4 * 60);

        // 设置对齐方式 水平 垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // 设置鼠标穿透属性 51号
        label->setAttribute(Qt::WA_TransparentForMouseEvents);


    }



}

void chooseLeve::paintEvent(QPaintEvent *)
{
    // 加载背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 加载小标题
    pix.load(":/res/Title.png");
    // pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap((this->width() - pix.width() ) * 0.5, 50, pix);
}
