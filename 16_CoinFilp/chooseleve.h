#ifndef CHOOSELEVE_H
#define CHOOSELEVE_H

#include <QMainWindow>
#include "choosesence.h"
class chooseLeve : public QMainWindow
{
    Q_OBJECT
public:
    explicit chooseLeve(QWidget *parent = nullptr);

    ChooseSence * levelnum = NULL;

public:
    void paintEvent(QPaintEvent *);

signals:
    void returnBtnDown();

};

#endif // CHOOSELEVE_H
