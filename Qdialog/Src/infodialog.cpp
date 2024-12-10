#include "infodialog.h"
#include "ui_infodialog.h"



infoDialog::infoDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::infoDialog) // Initialize the ui pointer
{
    ui->setupUi(this); // Set up the UI
}

infoDialog::~infoDialog()
{
    delete ui;
}

void infoDialog::on_OkButton_clicked()
{
    QString  user_Position = ui->positionlineEdit->text();

    if(!user_Position.isEmpty()){
        m_Position = user_Position;
        if(ui->WindowRadioButton->isChecked()){
            m_OS = "Window";
        }if(ui->WindowRadioButton->isChecked()){
            m_OS = "Linux";
        }if(ui->WindowRadioButton->isChecked()){
            m_OS = "Mac";
        }
        accept();
    }
    else{
        reject();
    }

}


void infoDialog::on_cancelButton_clicked()
{
    reject();
}

const QString &infoDialog::Position() const
{
    return m_Position;
}

const QString &infoDialog::OS() const
{
    return m_OS;
}



