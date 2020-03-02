#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPainter>
#include "chooseleve.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    // 重写画家事件 ，加载背景图
    void paintEvent(QPaintEvent *ev);

    // 选择关卡场景
    chooseLeve * chooseL = NULL;

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
