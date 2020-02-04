#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    // 重置窗口大小
    resize(1000,800);

    // 菜单栏创建  最多只能有一个
    QMenuBar * mainMenu = menuBar();

    // 将菜单放入窗口
    setMenuBar(mainMenu);

    // 添加菜单
    QMenu * fileMenu = mainMenu->addMenu("文件");
    QMenu * editMenu = mainMenu->addMenu("编辑");

    // 创建菜单项
    QAction * newFile = fileMenu->addAction("新建");

    // 添加分隔线
    fileMenu->addSeparator();

    QAction * openFile = fileMenu->addAction("打开");
    editMenu->addAction("复制");
    editMenu->addAction("粘贴");


    // 工具栏创建   可以有多个
    QToolBar * mainToolBar = new QToolBar(this);
    // 默认位置 左侧
    addToolBar(Qt::LeftToolBarArea, mainToolBar);

    // 只允许左右两侧停靠
    mainToolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    // 设置浮动
    mainToolBar->setFloatable(false);

    // 设置移动
    mainToolBar->setMovable(false);

    // 添加工具项
    mainToolBar->addAction(newFile);

    // 添加分隔线
    mainToolBar->addSeparator();
    mainToolBar->addAction(openFile);

    // 工具栏中添加控件
    QPushButton * toolBtn = new QPushButton("Git");

    mainToolBar->addWidget(toolBtn);


}

MainWindow::~MainWindow()
{
}

