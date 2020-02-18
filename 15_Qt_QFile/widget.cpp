#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 按下打开文件按钮 打开一个文件选择框
    connect(ui->btn_openFile, &QPushButton::clicked, [=](){

        // 打开文件
        // 默认utf-8 格式

        // 格式转换
       // QTextCodec * gbk = QTextCodec::codecForName("gbk");

        QString filePath = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\soul\\Desktop", "*.txt");

        // 显示文件路径
        ui->LEdit_filePath->setText(filePath);

        // 读打开文件 显示文件内容

        QFile file(filePath);
        file.open(QIODevice::ReadOnly);

        QByteArray array = file.readAll();

         ui->TEdit_fileContent->setText(array);
        //ui->TEdit_fileContent->setText( gbk->toUnicode(array) );

        // 关闭文件
        file.close();

//        // 写入内容
//        file.open(QIODevice::Append); // 追加模式， 避免破坏源文件
//        file.write( "写文件测试" );

//        // 关闭文件
//        file.close();

          // QFileInfo()读取文件信息
        QFileInfo fileInfo(filePath);

        qDebug() << "大小：" << fileInfo.size()
                 << "后缀名：" << fileInfo.suffix()
                 << "文件名称：" << fileInfo.fileName()
                 << "文件路径："<< fileInfo.filePath()
                 << "文件创建日期：" << fileInfo.created().toString("yyyy/MM/dd hh:mm:ss")
                 << "文件最后修改日期："<< fileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss");
    });

}

Widget::~Widget()
{
    delete ui;
}

