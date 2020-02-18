#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    // QPixmap 绘图设备 专门为平台做了对显示优化
//    QPixmap pix = QPixmap(300, 300);

//    // 背景填充
//    pix.fill(Qt::white);
//    QPainter painter(&pix);

//    // 画圆
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    // 保存图像
//    pix.save("./test.png");

//    // QImage 绘图设备   可以对像素进行访问
//    QImage img = QImage(300, 300, QImage::Format_RGB32);
//    // 背景填充
//    img.fill(Qt::white);
//    QPainter painter(&img);

//    // 画圆
//    painter.setPen(QPen(Qt::red));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    // 保存图像
//    img.save("./test.png");


    // QPicture 绘图设备 记录和重现画家操作
    QPicture picture;
    QPainter painter;

    // 开始往picture上画  记录画家操作
    painter.begin(&picture);
    painter.setPen(QPen(Qt::yellow));
    painter.drawEllipse(QPoint(150, 150), 100, 100);

    // 结束往picture上画
    painter.end();

    picture.save("./PictureTest.cyp");

}


void Widget::paintEvent(QPaintEvent *event)
{
//    // QImage 绘图设备   对像素进行访问
//    QPainter painter(this);
//    QImage img = QImage(300, 300, QImage::Format_RGB32);

//    img.load(":/test.png");
//    for (int i = 100; i < 200; i++)
//    {
//        for(int j = 100; j < 200; j++)
//        {
//            QRgb rgb = qRgb(255, 0, 0);
//            img.setPixel(i, j, rgb);
//        }
//    }
//    painter.drawImage(0, 0, img);

    // 重现画家操作
    QPicture picture;
    QPainter painter(this);
    picture.load("./PictureTest.cyp");

    painter.drawPicture(0, 0, picture);

}
Widget::~Widget()
{
    delete ui;
}

