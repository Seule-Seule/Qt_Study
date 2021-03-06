#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    // 定时器
    void timerEvent(QTimerEvent *e);

    // 定时器ID
    int time1Id;
    int time2Id;

    // label 的事件过滤器
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
