#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    // 自定义信号和槽
    // 上课后， 老师说上课， 学生拿出书准备上课

    // 初始化学生对象
    pSd = new Student(this);

    // 初始化老师对象
    pTh = new Teacher(this);

    // 自定义信号和槽函数连接
//    connect(pTh, &Teacher::startClass, pSd, &Student::teakBook);

    // 上课
    ClassBing();

    // 有参信号和槽连接
    void (Teacher::*pTeStCl)(QString bookName) = &Teacher::startClass;
    void (Student::*pStTaBo)(QString bookName) = &Student::teakBook;

    connect(pTh,pTeStCl,pSd, pStTaBo );

    // 上课
    ClassBing();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::ClassBing()
{
    emit pTh->startClass("课本");  // 触发信号
}

void Widget::ClassBing(QString bookName)
{
    emit pTh->startClass(bookName);  // 触发信号
}
