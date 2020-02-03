#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    // 自定义槽函数， 响应Teacher startClass
    // 返回值为void 需要声明，也需要实现
    void teakBook();

    void teakBook(QString bookName);
signals:

};

#endif // STUDENT_H
