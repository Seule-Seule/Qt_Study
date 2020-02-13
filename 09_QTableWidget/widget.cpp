#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



    // 设置列数
    ui->tableWidget->setColumnCount(3);

    // 设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");

    // 设置行数
    ui->tableWidget->setRowCount(5);

    // 添加内容
    // ui->tableWidget->setItem(0, 0, new QTableWidgetItem("张三"));

    // 姓名
    QStringList name;
    name << "张三" << "李四" << "王五" << "周六" << "麻七" ;

    // 性别
    QList<QString> sex;
    sex << "男" << "女" << "男" << "女"<< "男" ;

    for (int i = 0; i< 5;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(sex.at(i)));
        // int -> QString
        ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(i+20)));
    }

}

Widget::~Widget()
{
    delete ui;
}

