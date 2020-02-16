#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 连接右移
    connect(ui->btn_moveRight, &QPushButton::clicked, [=](){
        // 每次右移20个单元
        cmdPixX+=20;
        // 调用paintEvent函数使用update
        update();
    });
    // 连接下移
    connect(ui->btn_moveBttom, &QPushButton::clicked, [=](){
        // 每次右移20个单元
        cmdPixY+=20;
        // 调用paintEvent函数使用update
        update();
    });

    QTimer* timer = new QTimer(this);
    // 连接自动
    connect(ui->btn_auto, &QPushButton::clicked, [=](){

       timer->start(50);
    });

    // 捕捉定时器信号 移动图片
    connect(timer, &QTimer::timeout, [=](){
        cmdPixX+=20;
        cmdPixY+=20;
        update();
    });


}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
//    // 实例化画家对象 this指定画板
//    QPainter painter(this);

//    // 设置画笔
//    QPen pen(QColor(255,0,0));
//    //设置画笔风格
//    pen.setStyle(Qt::DashDotDotLine);
//    // 设置线宽
//    pen.setWidth(4);
//    painter.setPen(pen);

//    // 设置画刷
//    QBrush brush(QColor(0, 255, 0));
//    // 设置风格
//    brush.setStyle(Qt::Dense7Pattern);
//    painter.setBrush(brush);


//    // 画线
//    painter.drawLine(QPoint(300,50), QPoint(300,500));

//    // 画圆
//    painter.drawEllipse(QPoint(300,500),100, 100);

//    // 画矩形
//    painter.drawRect(300, 50, 200, 200);

//    // 画文字
//    painter.drawText(QPoint(300, 300),QString("好好学习，天天向上"));


    //////////////////////////////高级设置/////////////////

    // QPainter painter(this);

//    painter.drawEllipse(QPoint(200,300),100, 100);

//    // 设置抗锯齿能力 抗锯齿越高效率越低
//    painter.setRenderHint(QPainter::HighQualityAntialiasing);
//    painter.drawEllipse(QPoint(400,300),100, 100);


//     // 保存画家状态
//     painter.save();
//     // 移动画家
//     painter.translate(200, 0);
//     painter.drawRect(20, 50, 100, 100);

//     // 恢复画家状态
//     painter.restore();
//     painter.drawRect(20, 50, 100, 100);


    ////////////////////////画家 画资源图片 /////////////////////

    QPainter painter(this);

    //防止移除屏幕
    if (cmdPixX > (this->width()-QPixmap(":/cloudshell .png").width()) ||
        cmdPixY > (this->height()-QPixmap(":/cloudshell .png").height()))
    {
        cmdPixX = 0;
        cmdPixY = 0;
    }


    painter.drawPixmap(QPoint(cmdPixX,cmdPixY), QPixmap(":/cloudshell .png"));



}

