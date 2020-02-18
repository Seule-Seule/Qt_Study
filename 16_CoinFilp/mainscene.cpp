#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <QPixmap>
#include "movebutton.h"
#include <QDebug>

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

    // 开始按钮
    MoveButton * startButton = new MoveButton(":/res/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(this->width()*0.5-startButton->width()*0.5, this->height()*0.7);
    connect(startButton, &MoveButton::clicked, [=](){
        // qDebug() << "开始按钮按下";
        // 弹下弹起特效
        startButton->buttomZoom(true);
        startButton->buttomZoom(false);
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

