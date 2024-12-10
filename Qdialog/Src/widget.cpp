#include "widget.h"
#include "./ui_widget.h"
#include"infodialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ProvideInfoButton_clicked()
{

    infoDialog * dialog = new infoDialog(this);
    auto result =  dialog->exec();
    if(result==QDialog::Accepted){

        QString OperatingSys = dialog->OS();
        QString position = dialog->Position();

        ui->Infolabel->setText("Youir position is: " +position+
                               " and operation system is"+OperatingSys);

    }
    else{
        ui->Infolabel->setText("Dialog rejected");
    }
}

