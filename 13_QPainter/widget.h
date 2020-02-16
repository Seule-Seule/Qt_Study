#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

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
    void paintEvent(QPaintEvent *event);

    int cmdPixX = 0;
    int cmdPixY = 0;
    bool timerFlag = false;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
