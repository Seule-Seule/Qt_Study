#include "firstwindow.h"
#include <QPushButton>

#include "mybutton.h"

#include <QDebug>

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton;
    //button->show(); //show以顶层的方式弹出
    // 让button依赖于FirstWindow
    button->setParent(this);
    // 显示文本
    button->setText("按钮");

    // 按钮大小
    button->resize(80,30);

    // 移动按钮
    button->move(10,50);


    // 按钮2
    QPushButton *button2 =  new QPushButton("按钮2",this);

    // 按钮2大小
    button2->resize(80,30);

    // 移动按钮2
    button2->move(100,50);

    // 重置窗口大小
    resize(600,400);

    // 固定窗口大小
    setFixedSize(600,400);

    // 设置窗口标题
    setWindowTitle("主窗口");

    mybutton *myBut = new mybutton();

    myBut->setParent(this);
    myBut->setText("我的按钮");
    // 按钮大小
    myBut->resize(150,30);

    // 移动按钮
    myBut->move(200,50);

    // 信号与槽
    connect(myBut, &QPushButton::clicked, this, &QMainWindow::close);
}

FirstWindow::~FirstWindow()
{
    qDebug() << "~FirstWindow()";  // 对象树析构对象
}

