#include "widget.h"
#include "./ui_widget.h"
#include<QDebug>
#include<cstdlib>
#include<ctime>
#include<QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //set up the speed
    std::srand(std::time(nullptr));

    m_Secret_Number = std::rand()%10+1;
    qDebug()<<"Secret Number genrated: "<<QString::number(m_Secret_Number);

    //Disable the Start over Button
    ui->StartOverButton->setDisabled(true);

    //clear message text
    ui->messagelabel->setText("");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_GuessButton_clicked()
{
    m_guess_Number= ui->numberspinBox->value();
    qInfo()<<"User Guess Number"<<QString::number(m_guess_Number);

    if(m_guess_Number==m_Secret_Number){
        ui->messagelabel->setText(
            "Congratulation! the number is: "+QString::number(m_guess_Number
                                                                ));
        ui->GuessButton->setDisabled(true);
        ui->StartOverButton->setDisabled(false);
    }else {
        if(m_Secret_Number < m_guess_Number){
            ui->messagelabel->setText("Number is lesser than that");
        }if(m_Secret_Number > m_guess_Number){
            ui->messagelabel->setText("Number is higher than that");
        }
    }
}

void Widget::on_StartOverButton_clicked()
{
    ui->GuessButton->setDisabled(false);

    ui->StartOverButton->setDisabled(true);

    ui->numberspinBox->setValue(1);

    m_Secret_Number = std::rand()%10+1;
    ui->messagelabel->setText("");
}

