#include "widget.h"
#include "./ui_widget.h"
#include<QButtonGroup>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QRadioButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout();

    QButtonGroup *group = new QButtonGroup();
    group->addButton(ui->window);
    group->addButton(ui->MacOs);
    group->addButton(ui->Linux);
    group->setExclusive(true);

    QButtonGroup *languageGroup = new QButtonGroup();

    languageGroup->addButton(ui->Cpp);
    languageGroup->addButton(ui->java);
    languageGroup->addButton(ui->Linux);


    ui->Default_Window->setChecked(true);
    ui->Default_Cpp->setChecked(true);
    ui->Default_Window->setChecked(true);


    QPushButton *submitButton = new QPushButton();

    layout->addWidget(submitButton);

    connect(ui->Submit, &QPushButton::clicked, this, [=]() {
        QString selectedOS;
        QString selectedLanguage;

        // Get the selected OS
        if (ui->Default_Window->isChecked() && ui->Default_Cpp) {
            selectedOS = "Windows";
            selectedLanguage = "C++";
        }
        QMessageBox::information(this, "Selections",
                                 "Selected OS: " + selectedOS + "\n" +
                                     "Selected Language: " + selectedLanguage);
    });

    //widget->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
