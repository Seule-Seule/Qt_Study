#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器1 参数1 时间间隔 单位ms
    time1Id = startTimer(1000);

    // 启动定时器2 参数1 时间间隔 单位ms
    time2Id = startTimer(2000);

    // 定时器使用方法2 定时器类
    // 定义定时器3 定时0.5s
    QTimer* timer3 = new QTimer(this);
    timer3->start(500);
    // lebal4 显示定时器值
    connect(timer3, &QTimer::timeout,[=](){
         static int num4 = 0;
        ui->label_4->setText(QString::number(num4++));
    });
    // 连接定时器3 的暂停 开始 按钮
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        timer3->stop();
    });
    connect(ui->pushButton_2, &QPushButton::clicked,[=](){
        timer3->start(500);
    });


    // 给label安装 事件过滤器
    ui->label->installEventFilter(this);

}

bool Widget::eventFilter(QObject *watched, QEvent *e)
{
     if (watched == ui->label)
     {
         if (e->type()  == QEvent::MouseButtonPress)
         {
             QMouseEvent * ev = dynamic_cast<QMouseEvent *>(e);
             QString str = QString("eventFilter:: 按键点击 X=%1 Y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
             qDebug() << str;

             // 表示用户处理， 不向下分发
             return true;
         }

     }

     // 其余事件扔给父类处理
     return QWidget::eventFilter(watched,e);
}


Widget::~Widget()
{
    delete ui;
}


// 定时器使用方法1 重载定时器事件函数
void Widget::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == time1Id)
    {
        static int num = 0;
        ui->label_2->setText(QString::number(num++));
    }
    if(e->timerId() == time2Id)
    {
        static int num2 = 0;
        ui->label_3->setText(QString::number(num2++));
    }


}

