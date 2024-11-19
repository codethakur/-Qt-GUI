#include "widget.h"
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QDebug>
#include<QString>
#include<QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    /*QLabel *FirstName_labet_Edit = new QLabel("First Name: ", this);
    FirstName_labet_Edit->setMinimumSize(70, 60);
    FirstName_labet_Edit->move(10, 10);*/

    QLineEdit *FirstName_Line_Edit = new QLineEdit(this);
    FirstName_Line_Edit->setMinimumSize(150, 50);
    FirstName_Line_Edit->move(100, 10);


    /*QLabel *LastName_labet_Edit = new QLabel("Last Name: ", this);
    LastName_labet_Edit->setMinimumSize(70, 60);
    LastName_labet_Edit->move(10, 70);*/

    QLineEdit *LastName_Line_Edit = new QLineEdit(this);
    LastName_Line_Edit->setMinimumSize(150, 50);
    LastName_Line_Edit->move(100, 70);

    /*QLabel *City_LabelEdit = new QLabel("City Name: ", this);
    City_LabelEdit->setMinimumSize(70, 60);
    City_LabelEdit->move(10, 130);*/

    QLineEdit *City_Edit = new QLineEdit(this);
    City_Edit->setMinimumSize(150, 50);
    City_Edit->move(100, 130);


    FirstName_Line_Edit->setPlaceholderText(" Enter First Name");
    LastName_Line_Edit->setPlaceholderText(" Enter Last Name");
    City_Edit->setPlaceholderText(" Enter City Name");

    QPushButton *submitButton = new QPushButton("submit", this);
    submitButton->move(130,190);

    connect(submitButton, &QPushButton::clicked, [=](){
        QString firstName = FirstName_Line_Edit->text();
        QString LastName = LastName_Line_Edit->text();
        QString city = City_Edit->text();

        if (!firstName.isEmpty() && !LastName.isEmpty() && !city.isEmpty())
        {
            QMessageBox::information(this, "Submitted", "Form has been submitted.");
            qInfo() << "Form has been submitted.";
        }else {
            QMessageBox::warning(this, "warning", "Submission cancelled.");
            qInfo() << "Cancelled!";
        }

    });


}

Widget::~Widget() {}
