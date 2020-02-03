#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

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
    //connect(pTh, &Teacher::startClass, pSd, &Student::teakBook);

    // 上课
    ClassBing();

    // 有参信号和槽连接
    void (Teacher::*pTeStCl)(QString bookName) = &Teacher::startClass;
    void (Student::*pStTaBo)(QString bookName) = &Student::teakBook;

    connect(pTh,pTeStCl,pSd, pStTaBo );

    // 上课
    //ClassBing();

    // 点击按钮
    QPushButton * btn = new QPushButton("上课", this);

    // 设置窗口大小
    this->resize(800, 600);
    this->setFixedSize(800,600);

    // 连接按钮点击信号和上课触发信号
    //void (Widget::*pclassBing)(void) = &Widget::ClassBing;
    //connect(btn, &QPushButton::clicked, this, pclassBing);

    // 信号和信号连接
    void (Teacher::*pTeStCl2)(void) = &Teacher::startClass;
    void (Student::*pStTaBo2)(void) = &Student::teakBook;
    connect(pTh,pTeStCl2,pSd, pStTaBo2);
    // connect(btn, &QPushButton::clicked,pTh,pTeStCl2);

    // 断开连接
    //disconnect(pTh,pTeStCl2,pSd, pStTaBo2);

    // 理论
    // 信号可以连接信号
    // 一个信号可以连接多个信号和槽函数
    // 多个信号连接一个槽函数
    // 信号和槽函数的类型必须一一对应
    // 信号的参数可以多余槽函数，反之不行


    // Qt4以前信号和槽连接方式
     //connect(btn, SIGNAL(clicked()),pTh, SLOT(teakBook()));
    // connect(pTh, SIGNAL(startClass()), pSd, SLOT(teakBook()));
    // 优点：参数清晰  缺点：不进行类型检查，编译不报错，运行出错，很难查

    [=](){
        connect(btn, &QPushButton::clicked,pTh,pTeStCl2);
    }();
    // lambda表达式
    //  []匿名函数   = 传递值 & 传递引用
    //  ()参数
    //  {}函数体
    //  mutable修饰 值传递变量 可以修改拷贝出的数据 不能修改本体
    //  返回值 []()->returnType{};

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
