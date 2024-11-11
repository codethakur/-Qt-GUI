#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //string Notation
    //connect(ui->myButton, SIGNAL(clicked()), this, SLOT(change_txt()));

    //New-Style (Functor-Based) Syntax
    //connect(ui->myButton, &QPushButton::clicked, this, &Widget::change_txt);

    //Lambda-Based Connections
    connect(ui->myButton,&QPushButton::clicked,this, [=](){
        ui->label->setText("WELCOMEBACK, Coder!");
    });



}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_txt()
{
    ui->label->setText("Hi, User!");
}
