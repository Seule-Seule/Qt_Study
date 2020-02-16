#include "mylabel.h"
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    // 设置一直捕捉鼠标移动
    setMouseTracking(true);
}

// 鼠标进入
void myLabel::enterEvent(QEvent *event)
{
   // qDebug() << "鼠标进入了mylabel";
}

// 鼠标离开
void myLabel::leaveEvent(QEvent *event)
{
  //  qDebug() << "鼠标离开了mylabel";
}

// 鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
     // 捕捉鼠标左键
    if (ev->buttons() & Qt::LeftButton)  // 运动状态按键判断
    {
        QString str = QString("按键移动 X=%1 Y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

// 鼠标点击
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    // 捕捉鼠标左键
    if (ev->button() == Qt::LeftButton)  // 瞬间状态按键判断
    {
        QString str = QString("按键点击 X=%1 Y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }

}

// 鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    // 捕捉鼠标左键
    if (ev->button() == Qt::LeftButton)  // 瞬间状态按键判断
    {
        QString str = QString("按键释放 X=%1 Y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }

}
