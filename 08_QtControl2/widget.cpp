#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<< "英雄" << "英雄简介");

    // 添加顶层结点
    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList()<< "力量" );
    QTreeWidgetItem * miItem = new QTreeWidgetItem(QStringList()<< "敏捷" );
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList()<< "智慧" );
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(miItem);
    ui->treeWidget->addTopLevelItem(zhiItem);


    // 添加子层结点
    QTreeWidgetItem * liItem1 = new QTreeWidgetItem(QStringList()<< "liItem1" << "简介1");
    QTreeWidgetItem * liItem2 = new QTreeWidgetItem(QStringList()<< "liItem2" << "简介2");
    QTreeWidgetItem * liItem3 = new QTreeWidgetItem(QStringList()<< "liItem3" << "简介3");
    liItem->addChild(liItem1);
    liItem->addChild(liItem2);
    liItem->addChild(liItem3);

}

Widget::~Widget()
{
    delete ui;
}

