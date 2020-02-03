#include "mybutton.h"
#include <QDebug>
mybutton::mybutton(QPushButton *parent) : QPushButton(parent)
{
    qDebug() << "myButton(QWidget *parent) : QWidget(parent)";
}

mybutton::~mybutton()
{
    qDebug() << "~myButton()";
}
