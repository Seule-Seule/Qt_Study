#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QMovie>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // stackedWidget 栈控件

    // 设置默认
    ui->stackedWidget->setCurrentIndex(0);

    //scrollArea
    connect(ui->btn_scrollArea, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //scrollArea
    connect(ui->btn_toolBox, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    //scrollArea
    connect(ui->btn_tabWidget, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });


    // 下拉框
    // 添加选项
    ui->comboBox->addItem("学生");
    ui->comboBox->addItem("老师");
    ui->comboBox->addItem("家长");

    connect(ui->btn_student, &QPushButton::clicked, [=](){
        ui->comboBox->setCurrentIndex(0);
    });

    // 利用QLable 显示图片
    ui->lal_Picture->setPixmap(QPixmap(":/Qt.png"));

    // 利用QLable 显示动图 支持gif
    QMovie * movie = new QMovie(":/Qt.png");
    ui->lal_movie->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

