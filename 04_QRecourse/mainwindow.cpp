#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // ui->actionnewFile->setIcon(QIcon("C:/Users/soul/Pictures/Camera Roll/Windows_terminal/git.png"));


    // 添加Qt资源 ": + 前缀名 + 文件名"
    ui->actionnewFile->setIcon(QIcon(":/Images/git.png"));
    ui->actionopenFile->setIcon(QIcon(":/Images/Qt.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

