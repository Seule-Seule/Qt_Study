#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}


void Student::teakBook()
{
    qDebug()<<"学生拿出书，准备上课";
}


void Student::teakBook(QString bookName)
{
    // QSting -> char *
    // QString -> QByteArray(.toUtf8())  -> char * ( .data() )
    qDebug()<<"学生拿出"<<bookName.toUtf8().data() << "，准备上课";
}
