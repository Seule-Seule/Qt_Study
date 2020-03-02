#include "coin.h"
#include <QDebug>
#include <QTimer>

//Coin::Coin(QWidget *parent) : QWidget(parent)
//{

//}

Coin::Coin(QString btnImg)
{
    QPixmap pix ;
    bool ret = pix.load(btnImg);
    if (!ret)
    {
        qDebug() << "图片" << btnImg << "加载失败";
        return;
    }
    // 设置按钮固定大小
    this->setFixedSize(QSize(pix.width(), pix.height()));

    // 设置不规则样式
    this->setStyleSheet("QPushButton{border:0px}");

    // 设置图标
    this->setIcon(pix);

    // 设置图标大小
    this->setIconSize(QSize(pix.width(), pix.height()));

    // 初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // 金币翻银币
    connect(timer1, &QTimer::timeout, [=](){
        QString str1 = QString(":/res/Coin000%1.png").arg(min++);
        QPixmap pix;

        bool ret = pix.load(str1);
        if (!ret)
        {
            qDebug() << "图片" << str1 << "加载失败";
            return;
        }
        // 设置按钮固定大小
        this->setFixedSize(QSize(pix.width(), pix.height()));
        // 设置不规则样式
        this->setStyleSheet("QPushButton{border:0px}");
        // 设置图标
        this->setIcon(pix);
        // 设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));

        if (min > max)
        {
            min = 1;
            isAnimation = false;
            timer1->stop();
        }
    });

    // 银币翻金币
    connect(timer2, &QTimer::timeout, [=](){
        QString str2 = QString(":/res/Coin000%1.png").arg(max--);
        QPixmap pix;

        bool ret = pix.load(str2);
        if (!ret)
        {
            qDebug() << "图片" << str2 << "加载失败";
            return;
        }
        // 设置按钮固定大小
        this->setFixedSize(QSize(pix.width(), pix.height()));
        // 设置不规则样式
        this->setStyleSheet("QPushButton{border:0px}");
        // 设置图标
        this->setIcon(pix);
        // 设置图标大小
        this->setIconSize(QSize(pix.width(), pix.height()));

        if (max < min)
        {
            max = 8;
            isAnimation = false;
            timer2->stop();
        }
    });

}

void Coin::mousePressEvent(QMouseEvent *e)
{
    if ( isAnimation == true || isWin == true)
    {
        return;
    }
    {
        QPushButton::mousePressEvent(e);
    }

}

void Coin::falgChange()
{
    // 金币翻银币
    if (coinFlag)
    {
        timer1->start(30);
        isAnimation = true;
        coinFlag = false;
    }
    else
    {
        timer2->start(30);
        isAnimation = true;
        coinFlag = true;
    }
}
