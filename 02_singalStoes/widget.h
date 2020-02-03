#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 触发上课机制
    void ClassBing();

    void ClassBing(QString bookName);

private:
    Ui::Widget *ui;

    // 定义老师对象
    Teacher * pTh;

    // 定义学生对象
    Student * pSd;

};

#endif // WIDGET_H
