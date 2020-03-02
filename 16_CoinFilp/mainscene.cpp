#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <QPixmap>
#include "movebutton.h"
#include <QDebug>
#include "chooseleve.h"
#include <QTimer>
#include <QSound>

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    // 配置主场景
    // 设置主窗口大小
    setFixedSize(600, 600);
    // 设置主窗口图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    // 设置标题
    setWindowTitle("翻金币");


    // 退出菜单
    connect(ui->actionquit, &QAction::triggered, [=](){
        this->close();
    });

    // 选择关卡场景
    chooseL = new  chooseLeve();

    // 添加开始按钮音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav");
//    startSound->setLoops(-1);  // 设置循环次数 若循环次数为-1则永远循环
//    startSound->play();
    // 开始按钮
    MoveButton * startButton = new MoveButton(":/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(this->width()*0.5-startButton->width()*0.5, this->height()*0.7);
    connect(startButton, &MoveButton::clicked, [=](){
        // qDebug() << "开始按钮按下";
        // 播放开始音效
        startSound->play();
        // 弹下弹起特效
        startButton->buttomZoom(true);
        startButton->buttomZoom(false);

        // 延时，进入下一个场景
        QTimer::singleShot(300, this, [=](){
            // 设置chooseL场景的位置
            chooseL->setGeometry(this->geometry());
            // 显示选择关卡场景
            chooseL->show();
            // 隐藏这个场景
            this->hide();
        });
    });

    // 连接选择关卡返回信号
    connect(chooseL, &chooseLeve::returnBtnDown, [=](){
        this->setGeometry(chooseL->geometry());
        // 显示选择关卡场景
        chooseL->hide();
        // 隐藏这个场景
        this->show();
    });

}

void MainScene::paintEvent(QPaintEvent *)
{
    // 加载背景图
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    // 加载小标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.5, pix.height() * 0.5);
    painter.drawPixmap(100, 100, pix);
}
MainScene::~MainScene()
{
    delete ui;
}

