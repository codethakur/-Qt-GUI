#include "widget.h"
#include "./ui_widget.h"
#include"QButtonGroup"
#include"QMessageBox"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QButtonGroup *group = new QButtonGroup(this);

    group->addButton(ui->WindowcheckBox);
    group->addButton(ui->MaccheckBox);
    group->addButton(ui->LinuxcheckBox);
    group->setExclusive(true);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_WindowcheckBox_toggled(bool checked)
{
    if(checked){
        qInfo()<<"Window Box checked!";
    }else{
        qInfo()<<"Window Box Uncheck!";
    }
}


void Widget::on_SubmitButton_clicked()
{
    if (ui->WindowcheckBox->isChecked() ||
        ui->MaccheckBox->isChecked() ||
        ui->LinuxcheckBox->isChecked()) {
        QMessageBox::information(this, "Submitted", "Form has been submitted.");
        qInfo() << "Submission successful!";
    } else {
        QMessageBox::warning(this, "Warning", "Please select at least one checkbox before submitting.");
        qInfo() << "Submission cancelled!";
    }
}



void Widget::on_setDefaultButton_clicked()
{
    ui->WindowcheckBox->setChecked(true);
    ui->TeacheckBox->setChecked(true);
    ui->radioButton->setChecked(true);

    QMessageBox::warning(this, "warning", "set as Default");
    qInfo() << "set as Default successful!";
}

