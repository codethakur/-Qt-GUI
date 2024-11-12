#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_person.setWeight(ui->WeightSpinBox->value());
    m_time = ui->TimeSpinBox->value();
    m_speed = ui->SpeedSpinBox->value();

    //connect ui component to respective slots
    connect(ui->WeightSpinBox,&QDoubleSpinBox::valueChanged, this,
            &Widget::weight_changed);
    connect(ui->TimeSpinBox,&QDoubleSpinBox::valueChanged, this,
            &Widget::time_changed);
    connect(ui->SpeedSpinBox,&QDoubleSpinBox::valueChanged, this,
            &Widget::time_changed);

    //Display  the calory count
    connect(this, &Widget::calory_count_changed, this, [=](){
        ui->CaloryCountLabel->setText(QString::number(m_calory_count));
    });
    calculate_Calory();
}


Widget::~Widget()
{
    delete ui;
}

void Widget::calculate_Calory()
{
    // Corrected formula: [0.0215 * KPH^3 - 0.1765 * KPH^2 + 0.8710 * KPH + 1.4577] * WKG * T
    m_calory_count = ((0.0215 * m_speed * m_speed * m_speed)
                      - (0.1765 * m_speed * m_speed)
                      + (0.8710 * m_speed)
                      + 1.4577) * m_person.weight() * m_time;
    emit calory_count_changed();
}
void Widget::weight_changed(double weight)
{
    m_person.setWeight(weight);
    calculate_Calory();

}

void Widget::time_changed(double time)
{
    m_time = time;
    calculate_Calory();
}

void Widget::speed_changed(double speed)
{
    m_speed = speed;
    calculate_Calory();
}
