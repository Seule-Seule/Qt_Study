#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    // 修改 spinBox 的值 horizontalSlider相应改变
    void (QSpinBox:: * pSpinBox)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, pSpinBox, ui->horizontalSlider, &QSlider::setValue);

    // 滑动 horizontalSlider ->  spinBox 的值相应改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);
}

// 获取值
int SmallWidget::getValue()
{
    return ui->spinBox->value();
}

// 设置值
void SmallWidget::setValue(int value)
{
    ui->spinBox->setValue(value);
}


SmallWidget::~SmallWidget()
{
    delete ui;
}
