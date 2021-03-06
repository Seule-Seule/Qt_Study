#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MoveButton : public QPushButton
{
    Q_OBJECT
public:
    // explicit MoveButton(QWidget *parent = nullptr);

public:
    // normalImg正常显示图片
    // pressImg按下后显示图片
    MoveButton(QString normalImg, QString pressImg = "");

    QString pressImgPath;
    QString normalImgPath;

    // 按钮特效    true 向下跳  false 向上跳
    void buttomZoom(bool flag);

    // 重写按钮点击事件
    void mousePressEvent(QMouseEvent * e);

    void mouseReleaseEvent(QMouseEvent * e);
signals:

};

#endif // MOVEBUTTON_H
