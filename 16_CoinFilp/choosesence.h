#ifndef CHOOSESENCE_H
#define CHOOSESENCE_H

#include <QMainWindow>
#include "coin.h"
class ChooseSence : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseSence(QWidget *parent = nullptr);
public:
    ChooseSence(int leveln);

    // 重写绘图事件
    void paintEvent(QPaintEvent *);

    int lavelIndex;
    int gameArray[4][4];  // 维护游戏数据

    Coin * coinArray[4][4];

    bool isWin = true;     // 游戏胜利标志

signals:

    // 返回按钮的返回信号
    void returnBtnDown();
};

#endif // CHOOSESENCE_H
