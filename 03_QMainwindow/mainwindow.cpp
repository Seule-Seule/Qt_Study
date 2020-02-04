#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
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


    // 状态栏 只能有一个
    QStatusBar * statBar = statusBar();

    // 设置状态栏
    setStatusBar(statBar);

    // 添加标签空间
    QLabel * label1 = new QLabel("提示1",this);
    QLabel * label2 = new QLabel("提示2",this);
    // 左侧添加
    statBar->addWidget(label1);
    // 右侧添加
    statBar->addPermanentWidget(label2);

    // 铆接部件 浮动窗口 可以有多个
    QDockWidget * dock1 = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock1);

    // 设置停靠位置
    dock1->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);

    // 设置中心部件 只能一个
    QTextEdit * edit1 = new QTextEdit("编辑",this);
    setCentralWidget(edit1);
}

MainWindow::~MainWindow()
{
}

