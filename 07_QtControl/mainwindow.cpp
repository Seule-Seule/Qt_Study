#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 设置默认性别选男
    ui->rButMan->setChecked(true);

    // 选择学习情况差
    connect(ui->cBoxBad, &QCheckBox::stateChanged, [=](int stat){
        qDebug() << stat;
    });



//    // QListWidget
//    // 单个行添加
//    QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
//    ui->listWidget->addItem(item);
//    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // 整个list添加
    // QStringList   List<String>  QList<QString>
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
    ui->listWidget->addItems(list);


}

MainWindow::~MainWindow()
{
    delete ui;
}

