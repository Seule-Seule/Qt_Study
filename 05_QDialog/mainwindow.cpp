#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 对话框
    // 按下新建 弹出对话框
    connect(ui->actionnew, &QAction::triggered, [=](){
        // 对话框
        // 分两类 模态对话框 非模态对话框
        // 模态对话框  不可对其他对话框进行操作 阻塞
//        QDialog Dlg1(this);
//        Dlg1.resize(100,80);
//        Dlg1.exec();

//        qDebug() << "模态对话框";
        // 非模态对话框  可对其他对话框进行操作
//        QDialog * Dlg2 = new QDialog(this);
//        Dlg2->resize(100,80);
//        Dlg2->setAttribute(Qt::WA_DeleteOnClose);    // Qt::WA_DeleteOnClose 55号
//        Dlg2->show();
//        qDebug() << "非模态对话框";


        // 标准对话框 -> 消息对话框 QMessageBox
        // 错误对话框
        // QMessageBox::critical(this, "CRITICAL", "错误");

        // 信息对话框
        // QMessageBox::information(this, "information", "信息");

        // 提问对话框
        // 参数1 父亲 参数2 标题 参数3 显示内容 参数4 按钮类型 参数5 默认关联回车按钮
//        if (QMessageBox::Cancel == QMessageBox::question(this, "QUESTION", "提问", QMessageBox::Save| QMessageBox::Cancel, QMessageBox::Cancel))
//        {
//            qDebug() << "选择了Cancel";
//        }
//        else
//        {
//            qDebug() << "选择了Save";
//        }

        // 警告对话框
        // QMessageBox::warning(this, "WARNING", "警告");

        // 颜色对话框
   //    QColor col = QColorDialog::getColor(QColor(255,0,0));
   //    qDebug() << "r: "<<col.red() << "  g:"<<col.green() << "  b:"<<col.blue();

        // 文件对话框
//        QString fileName = QFileDialog::getOpenFileName(this,"打开文件","C:/Users/soul/Desktop","(*.txt)");
//        qDebug()<< fileName.toUtf8().data();

        // 字体对话框
//        bool flag;
//        QFont font = QFontDialog::getFont(&flag,QFont("宋体"),this, "字体选择");
//        qDebug() << "字体：" << font.family() << " 字号："<<font.pointSize()<<" 是否加粗："<<font.bold()<<" 是否倾斜："<<font.italic();

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

