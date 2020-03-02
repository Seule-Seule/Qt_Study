#ifndef COIN_H
#define COIN_H

#include <QPushButton>

class Coin : public QPushButton
{
    Q_OBJECT
public:
    // explicit Coin(QWidget *parent = nullptr);

    Coin(QString btnImg);

public:
    // 金币属性
    int potX; // 金币x坐标
    int potY; // 金币y坐标
    bool coinFlag;

    void falgChange();  // 改变金币标志函数

    QTimer * timer1;  // 金币翻银币
    QTimer * timer2;  // 银币翻金币

    int min = 1;
    int max = 8;

    bool isWin = true;   // 胜利标志

public:

    // 动画完成标志
    bool isAnimation = false;  // 默认没有执行动画

    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // COIN_H
