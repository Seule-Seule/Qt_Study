#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击 btn_set 设置到最大
    connect(ui->btn_set, &QPushButton::clicked, [=](){
        ui->widget->setValue(99);
    });

    // 点击 btn_get 打印当前值
    connect(ui->btn_get, &QPushButton::clicked, [=](){
        qDebug() << ui->widget->getValue();
    });

}

Widget::~Widget()
{
    delete ui;
}

