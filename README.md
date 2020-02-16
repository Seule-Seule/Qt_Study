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

- [QPushButton](01_FIrstApp/firstwindow.cpp)
  - 按钮定义`QPushButton *button = new QPushButton;`
  - 让button依赖于FirstWindow `button->setParent(this);`
  - 显示文本 `button->setText("按钮");`
  - 按钮大小 `button->resize(80,30);`
  - 移动按钮 `button->move(10,50);`
  - 重置窗口大小 `resize(600,400);`
  - 固定窗口大小 `setFixedSize(600,400);`
  - 设置窗口标题 `setWindowTitle("主窗口");`

- [信号与槽函数](02_singalStoes/widget.cpp)
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

- [QMainWindows](03_QMainwindow/mainwindow.cpp)

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
  
- [Qt资源文件](04_QRecourse/mainwindow.cpp)
  - 将资源文件拷贝到项目目录下
  - 右键项目-> 添加新文件 -> Qt -> Qt Recourse File -> 给资源文件起名
  - ResourceFile -> ResourceFile.qrc
  - open in editor 添加资源
  - 添加前缀 添加文件
  - 添加Qt资源 ": + 前缀名 + 文件名"

- [对话框](05_QDialog/mainwindow.cpp)
  - 分两类 模态对话框 非模态对话框
    - 模态对话框  不可对其他对话框进行操作 阻塞
      - `QDialog Dlg1(this);`
      - `Dlg1.resize(100,80);`
      - `Dlg1.exec();`
    - 非模态对话框  可对其他对话框进行操作
      - `QDialog * Dlg2 = new QDialog(this);`
      - `Dlg2->resize(100,80);`
      - `Dlg2->setAttribute(Qt::WA_DeleteOnClose); // Qt::WA_DeleteOnClose 55号`
      - `Dlg2->show();`
    - 标准对话框
      - 消息对话框 QMessgaeBox
        - 错误对话框
          - `QMessageBox::critical(this, "CRITICAL", "错误");`

        - 信息对话框
          - `QMessageBox::information(this, "information", "信息");`

        - 提问对话框
          - `参数1 父亲 参数2 标题 参数3 显示内容 参数4 按钮类型 参数5 默认关联回车按钮`
          ```c++
          if (QMessageBox::Cancel == QMessageBox::question(this, "QUESTION", "提问", QMessageBox::Save| QMessageBox::Cancel, QMessageBox::Cancel))
          {
              qDebug() << "选择了Cancel";
          }
          else
          {
              qDebug() << "选择了Save";
          }
          ```

        - 警告对话框
          - `QMessageBox::warning(this, "WARNING", "警告");`

      - 颜色对话框
        - `QColor col = QColorDialog::getColor(QColor(255,0,0));`
        - `qDebug() << "r: "<<col.red() << "  g:"<<col.green() << "  b:"<<col.blue();`

      - 文件对话框
        - `QString fileName = QFileDialog::getOpenFileName(this,"打开文件","C:/Users/soul/Desktop","(*.txt)");`
        - `qDebug()<< fileName.toUtf8().data();`

      - 字体对话框
        - `bool flag;`
        - `QFont font = QFontDialog::getFont(&flag,QFont("宋体"),this, "字体选择");`
        - `qDebug() << "字体：" << font.family() << " 字号："<<font.pointSize()<<" 是否加粗："<<font.bold()<<" 是否倾斜："<<font.italic();`

- [页面布局](06_Layouts/mainwindow.ui)
  - 实现登陆窗口
  - 利用布局方式， 进行窗口美化
  -  选取 widget 进行布局， 水平布局 、 垂直布局、 栅格布局
  - 给用户名、 密码 、 登录、 退出按钮进行布局
  - 默认窗口控件之间有 9 间隙、 可以调整
  - 利用弹簧进行布局

- [控件学习](07_QtControl/mainwindow.cpp)
  - QPushButton 常用按钮
  - QToolButton 工具按钮 、 列表显示选中项
    - toolButtonStyle 突起风格 autoRaise
  - radioButton 单选按钮， 设置默认( ui->rButMan->setChecked(true);)
  - checkBox 多选按钮， 监听状态， 2 选中  1 半选   0 不选
  - QListWidget  列表容器
    - `QListWidgetItem * item = new QListWidgetItem("锄禾日当午");`
    - `ui->listWidget->addItem(item);`
    - `item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);  // 设置居中`
    - 整个list添加
      - `list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";`
      - `ui->listWidget->addItems(list);`
  - [QTreeWidget 树控件](08_QtControl2/widget.cpp)
    -设置水平头
      - `ui->treeWidget->setHeaderLabels(QStringList()<< "英雄" << "英雄简介");`
    - 添加顶层结点
      - `QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList()<< "力量" );`
      - `ui->treeWidget->addTopLevelItem(liItem);`
    - 添加子层结点
      - `QTreeWidgetItem * liItem1 = new QTreeWidgetItem(QStringList()<< "liItem1" << "简介1");`
      - `liItem->addChild(liItem1);`
  - [QTableWidget 表控件](09_QTableWidget/widget.cpp)
    - 设置列数
      - `ui->tableWidget->setColumnCount(3);`
    - 设置水平表头
      - `ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");`
    - 设置行数
      - `ui->tableWidget->setRowCount(5);`
    - 添加内容
      ```c++
      ui->tableWidget->setItem(0, 0, new QTableWidgetItem("张三"));
      姓名
        QStringList name;
        name << "张三" << "李四" << "王五" << "周六" << "麻七" ;
      性别
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
    ```

  - [其他控件](10_OtherControl/widget.cpp)
    - stackedWidget 栈控件
      - 设置默认
        - ui->stackedWidget->setCurrentIndex(0);
      - 按钮切换

        ```c++
        connect(ui->btn_scrollArea, &QPushButton::clicked, [=](){
            ui->stackedWidget->setCurrentIndex(0);
        });
        ```
    - 下拉框
      - 添加选项
        - ui->comboBox->addItem("学生");
      - 按钮选择下拉框选项
        ```
        connect(ui->btn_student, &QPushButton::clicked, [=](){
           ui->comboBox->setCurrentIndex(0);
        });
         ```
    - 利用QLable 显示图片
      - ui->lal_Picture->setPixmap(QPixmap(":/Qt.png"));
    - 利用QLable 显示动图 支持gif
      - QMovie * movie = new QMovie(":/Qt.png");
      - ui->lal_movie->setMovie(movie);
      - movie->start();

- [自定义控件封装](11_smallWidget/smallwidget.cpp)
  - 添加新文件 Qt -设计师界面类(.h .cpp .ui)
  - .ui中设计 spinBox 和 horizontalSlider 两个控件
  - widget 中使用自定义控件， 拖拽一个新的 widget 点击提升为， 点击添加。 点击提升
  - 实现功能， 改变数字，滑条跟随滑动， 信号槽监听
  - 提供对外接口， setValue 和 getValue
  - 测试接口

- [鼠标事件](12_QtEvent\mylabel.cpp)
  - 设置一直捕捉鼠标移动
    - `setMouseTracking(true);`
  - 鼠标进入
    - `void myLabel::enterEvent(QEvent *event)`
  - 鼠标离开
    - `void myLabel::leaveEvent(QEvent *event)`
  - 鼠标移动
    - `void myLabel::mouseMoveEvent(QMouseEvent *ev)`
    - 捕捉鼠标左键 // 运动状态按键判断
      `if (ev->buttons() & Qt::LeftButton)` 
  - 鼠标点击
    - `void myLabel::mousePressEvent(QMouseEvent *ev)`
    - 捕捉鼠标左键// 瞬间状态按键判断
      - `if (ev->button() == Qt::LeftButton)  `
  - 鼠标释放
    - `void myLabel::mouseReleaseEvent(QMouseEvent *ev)`
  - 格式化字符串
    - `QString str = QString("按键点击 X=%1 Y=%2 globalX=%3 globalY=%4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());`

- [定时器](12_QtEvent\widget.cpp)
  - 定时器使用方式1 定时器事件
    - 重写定时器事件函数 `void Widget::timerEvent(QTimerEvent *e)`
    - 启动定时器，返回定时器ID, 单位ms ` time1Id = startTimer(1000);`
    - 在重写的定时器事件函数中判断timerId 执行操作`if(e->timerId() == time1Id){...}`
  - 定时器使用方式2 定时器类 QTimer
    - 定义定时器 `QTimer* timer3 = new QTimer(this);`
    - 定时0.5s开始定时器 `timer3->start(500);`, 使用时监听timeout 信号
    - 暂停定时器  `timer3->stop();`

- [事件分发机制](12_QtEvent\mylabel.cpp)
  - [事件分发示意图](12_QtEvent\事件分发机制.png)
  - 重写事件分发函数 `bool event(QEvent *e)`
  - 事件分发函数的返回值如果是true， 表示事件由用户处理，不向下分发
  - 事件类型判断`if (e->type()  == QEvent::MouseButtonPress){...}`

- [事件过滤器](12_QtEvent\widget.cpp)
  - [事件过滤器机制图](12_QtEvent\事件过滤器.png)
  - 在程序将事件分发到事件分发器之前，可以由事件过滤器过滤
  - 事件过滤器使用步骤
    - 给控件安装事件过滤器`ui->label->installEventFilter(this);`
    - 重写事件过滤器函数`bool Widget::eventFilter(QObject *watched, QEvent *e);`

- [画家事件QPainter](13_QPainter\widget.cpp)
  - 重写画家事件函数，主动调用`void Widget::paintEvent(QPaintEvent *event)`
  - 实例化画家对象 this指定画板`QPainter painter(this);`
  - 设置画笔`QPen pen(QColor(255,0,0));`
    - 设置画笔风格`pen.setStyle(Qt::DashDotDotLine);`
    - 设置线宽`pen.setWidth(4);`
    - `painter.setPen(pen);`
  - 设置画刷`QBrush brush(QColor(0, 255, 0));`
    - 设置风格`brush.setStyle(Qt::Dense7Pattern);`
    - `painter.setBrush(brush);`
  - 画线`painter.drawLine(QPoint(300,50), QPoint(300,500));`
  - 画圆`painter.drawEllipse(QPoint(300,500),100, 100);`
  - 画矩形`painter.drawRect(300, 50, 200, 200);`
  - 画文字`painter.drawText(QPoint(300, 300),QString("好好学习，天天向上"));`
  - 高级设置
    - 设置抗锯齿能力 抗锯齿越高效率越低 `painter.setRenderHint(QPainter::HighQualityAntialiasing);`
    - 保存画家状态 `painter.save();`
    - 恢复画家状态 `painter.restore();`
    - 移动画家 `painter.translate(200, 0);`
  - 利用画家画图片 `painter.drawPixmap(QPoint(cmdPixX,cmdPixY), QPixmap(":/cloudshell .png"));`



## 主要开发者

- [@Seule-Seule](https://github.com/Seule-Seule)  -- 就只有我自己了。

## 参考

> 如果有参考我会放在这下面。
- 黑马程序员-Qt教程


## License

[@MIT](LICENSE) © Seule-Seule.
