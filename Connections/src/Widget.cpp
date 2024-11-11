#include "widget.h"
#include "./ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*// Old-Style (String-Based) Syntax
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)), this, SLOT(respond(int)));

    // New-Style (Functor-Based) Syntax
    // Correct new-style syntax
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Widget::respond);*/

    // Lambda-Based Connections
    // Lambda-based connection for updating progress bar
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, [=](int value) {
        ui->progressBar->setValue(value);  // Update the progress bar
        respond(value);                    // Call the respond function
    });


}

Widget::~Widget()
{
    delete ui;
}

void Widget::respond(int value)
{
    qDebug()<<"Value: "<<value;
}
