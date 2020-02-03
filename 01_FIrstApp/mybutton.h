#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QPushButton *parent = nullptr);
    ~mybutton();
signals:

};

#endif // MYBUTTON_H
