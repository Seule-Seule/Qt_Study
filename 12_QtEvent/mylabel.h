#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);


public:

    // 鼠标进入
    void enterEvent(QEvent *event);

    // 鼠标离开
    void leaveEvent(QEvent *event);

    // 鼠标移动
    virtual void mouseMoveEvent(QMouseEvent *ev) override;

    // 鼠标点击
    virtual void mousePressEvent(QMouseEvent *ev) override;

    // 鼠标释放
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;

    // 在事件分发层 做事件拦截
    bool event(QEvent *e) ;

signals:

};

#endif // MYLABEL_H
