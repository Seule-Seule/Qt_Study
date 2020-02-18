#include "movebutton.h"
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
//MoveButton::MoveButton(QWidget *parent) : QPushButton(parent)
//{

//}
MoveButton::MoveButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    //QPainter painter(this);
    QPixmap pix;

    bool ret = pix.load(normalImgPath);
    if (!ret)
    {
        qDebug() << "图片" << normalImg << "加载失败";
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

}

void MoveButton::buttomZoom(bool flag)
{
    // 创建特效对象
    QPropertyAnimation * animation = new QPropertyAnimation(this, "geometry");

    // 设置时间间隔
    animation->setCurrentTime(200);

    if (flag)  // 如果向下跳
    {
        // 设置起始时间
        animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));

        // 设置结束时间
        animation->setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
    }
    else {
        // 设置起始时间
        animation->setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));

        // 设置结束时间
        animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
    }
    // 设置缓和曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // 启动执行动画
    animation->start();

}
