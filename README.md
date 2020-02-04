## Qt

> Qt 框架学习

## 目录

- [背景](#背景)
- [运行](#运行)
- [项目目录](#项目目录)
- [相似项目](#相似项目)
- [主要开发者](#主要开发者)
- [参考](#参考)
- [开源协议](#License)

## 背景

大三了，也慢慢找到了自己的方向(确实太晚了)，但千里之行、始于足下。过去浪费的时间已经过去了，当下要做的是珍惜现在，努力做好自己想做的。加油吧！

## 运行

所有项目均采用Qt Creator 4.11.0编译。

## 相似项目

- [C语言基础](https://github.com/Seule-Seule/C_Basis) -- C语言基础学习时使用的代码库。
- [C++基础](https://github.com/Seule-Seule/C-_Study)  -- C++学习代码库

## 项目目录

- [QPushButton](01_FIrstApp\firstwindow.cpp)
  - 按钮定义`QPushButton *button = new QPushButton;`
  - 让button依赖于FirstWindow `button->setParent(this);`
  - 显示文本 `button->setText("按钮");`
  - 按钮大小 `button->resize(80,30);`
  - 移动按钮 `button->move(10,50);`
  - 重置窗口大小 `resize(600,400);`
  - 固定窗口大小 `setFixedSize(600,400);`
  - 设置窗口标题 `setWindowTitle("主窗口");`

- [信号与槽函数](02_singalStoes\widget.cpp)
  - 按钮点击，窗口关闭`connect(myBut, &QPushButton::clicked, this, &QMainWindow::close);`
  - 自定义信号
    - 返回值void 只需要声明 不需要实现
    - 可以有参数，可以重载
    - `void startClass();` `void startClass(QString bookName);`
  - 自定义槽函数
    - 自定义槽函数， 响应Teacher startClass
    - 返回值为void 需要声明，也需要实现
    - `void teakBook();` `void teakBook(QString bookName);`
  - 信号和槽函数连接
    - 无参槽函数连接
      - connect(pTh, &Teacher::startClass, pSd, &Student::teakBook);
    - 有参槽函数连接(借助触发信号)
      - 触发信号定义(上课) `ClassBing();`
      - 定义信号函数指针 `void (Teacher::*pTeStCl)(QString bookName) = &Teacher::startClass;`
      - 定义槽函数函数指针 `void (Student::*pStTaBo)(QString bookName) = &Student::teakBook;`
      - 信号和槽连接 `connect(pTh,pTeStCl,pSd, pStTaBo );`
  - 连接按钮点击信号和上课触发信号
    - `void (Widget::*pclassBing)(void) = &Widget::ClassBing;`
    - `connect(btn, &QPushButton::clicked, this, pclassBing);`
  - 信号和信号连接
    - `void (Teacher::*pTeStCl2)(void) = &Teacher::startClass;`
    - `void (Student::*pStTaBo2)(void) = &Student::teakBook;`
    - `connect(pTh,pTeStCl2,pSd, pStTaBo2);`
    - `connect(btn, &QPushButton::clicked,pTh,pTeStCl2);`
  - 断开连接
    - `disconnect(pTh,pTeStCl2,pSd, pStTaBo2);`
  - 总结理论
    - 信号可以连接信号
    - 一个信号可以连接多个信号和槽函数
    - 多个信号连接一个槽函数
    - 信号和槽函数的类型必须一一对应
    - 信号的参数可以多余槽函数，反之不行
  - Qt4以前信号和槽连接方式
    - `connect(btn, SIGNAL(clicked()),pTh, SLOT(teakBook()));`
    - `connect(pTh, SIGNAL(startClass()), pSd, SLOT(teakBook()));`
    - 优点：参数清晰  缺点：不进行类型检查，编译不报错，运行出错，很难查
  - lambda表达式
      ```C++
      [=](){
          connect(btn, &QPushButton::clicked,pTh,pTeStCl2);
      }();
       ```
    - lambda表达式
    - []匿名函数   = 传递值 & 传递引用
    - ()参数
    - {}函数体
    - mutable修饰 值传递变量 可以修改拷贝出的数据 不能修改本体
    - 返回值 []()->returnType{};

- [QMainWindows](03_QMainwindow\mainwindow.cpp)

  - 菜单栏
    - 只能有一个
      - `QMenuBar * mainMenu = menuBar();`
    - 将菜单放入窗口
      - `setMenuBar(mainMenu);`
    - 添加菜单
      - `QMenu * fileMenu = mainMenu->addMenu("文件");`
      - `QMenu * editMenu = mainMenu->addMenu("编辑");`
    - 创建菜单项
      - `QAction * newFile = fileMenu->addAction("新建");`
      - `QAction * openFile = fileMenu->addAction("打开");`
      - `editMenu->addAction("复制");`
      - `editMenu->addAction("粘贴");`
    - 添加分隔线
      - `fileMenu->addSeparator();`
  - 工具栏
    - 工具栏创建   可以有多个
      - `QToolBar * mainToolBar = new QToolBar(this);`
    - 默认位置 左侧
      - `addToolBar(Qt::LeftToolBarArea, mainToolBar);`
    - 只允许左右两侧停靠
      - `mainToolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);`
    - 设置浮动
      - `mainToolBar->setFloatable(false);`
    - 设置移动
      - `mainToolBar->setMovable(false);`
    - 添加工具项
      - `mainToolBar->addAction(newFile);`
      - `mainToolBar->addAction(openFile);`
    - 添加分隔线
      - `mainToolBar->addSeparator();`
    - 工具栏中添加控件
      - `QPushButton * toolBtn = new QPushButton("Git");`
      - `mainToolBar->addWidget(toolBtn);`
  - 状态栏 
    - 创建 只能有一个
      - `QStatusBar * statBar = statusBar();`
    - 设置状态栏
      - setStatusBar(statBar);
    - 添加标签空间
      - `QLabel * label1 = new QLabel("提示1",this);`
      - `QLabel * label2 = new QLabel("提示2",this);`
      - 左侧添加
        - `statBar->addWidget(label1);
      - 右侧添加
        - `statBar->addPermanentWidget(label2);`
  - 铆接部件 浮动窗口 
    - 创建 可以有多个
      - `QDockWidget * dock1 = new QDockWidget("浮动",this);`
      - `addDockWidget(Qt::BottomDockWidgetArea,dock1);`
    - 设置停靠位置
      - `dock1->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);`
  - 设置中心部件 只能一个
    - `QTextEdit * edit1 = new QTextEdit("编辑",this);`
    - `setCentralWidget(edit1);`
  

## 主要开发者

- [@Seule-Seule](https://github.com/Seule-Seule)  -- 就只有我自己了。

## 参考

> 如果有参考我会放在这下面。
- 黑马程序员-Qt教程


## License

[@MIT](LICENSE) © Seule-Seule.
