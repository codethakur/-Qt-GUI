#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include<QApplication>
#include <QLabel>
#include <QString>
#include <QDebug>
#include<QTemporaryFile>
#include <QFileDialog>
#include <QTextStream>
#include<QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    // Check if the text edit has unsaved changes (if needed)
    if (ui->textEdit->document()->isModified()) {
        // Create a QMessageBox for Save, Don't Save, Cancel
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(
            this,
            "Exit Application",
            "Do you want to save changes before exiting?",
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel
            );

        if (reply == QMessageBox::Save) {
            on_actionSave_triggered();
            qApp->quit();
        } else if (reply == QMessageBox::Discard) {
            qApp->quit();
        } else if (reply == QMessageBox::Cancel) {
            return;
        }
    } else {
        qApp->quit();
    }
}
void MainWindow::on_actionSave_triggered()
{
    if(ui->textEdit->document()->isModified()){

     QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
        if(fileName.isEmpty()){
         return;
        }
        QFile file(fileName);
        if(file.open(QIODevice::WriteOnly | QIODevice::ReadOnly))
        {
             QTextStream out(&file);
            out<<ui->textEdit->toPlainText();
             file.close();
        }else{
            QMessageBox::warning(this, tr("Save File"), tr("Failed to save file."));
        }
    }

}


void MainWindow::on_actionNew_Window_triggered()
{
    // Create a new instance of MainWindow
    MainWindow* newWindow = new MainWindow(this);

    // Show the new window
    newWindow->show();
    QDialog* newDialog = new QDialog(this);

    // Show the dialog
    newDialog->exec();

}



void MainWindow::on_actionNew_File_triggered()
{
    if(ui->textEdit->document()->isModified()){
        ui->textEdit->clear();
    }
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{

    ui->textEdit->redo();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionFind_triggered()
{

}


void MainWindow::on_actionRun_triggered()
{

}

void MainWindow::on_actionWelcome_triggered()
{
    // Create the HTML formatted text
    QString welcomeText = R"(
        <h1 style="color:white; font-size: 36px; font-family: Arial, sans-serif; text-align: center;">
            Welcome to Qt Academy
        </h1>
        <p style="color:white; font-size: 18px; font-family: Arial, sans-serif; text-align: center;">
            The free eLearning platform where code meets creativity.
        </p>
        <p style="color:white; font-size: 14px; font-family: Arial, sans-serif; text-align: center;">
            A community of Qt users, partners, universities, and learners, where technology and Qt education converge to create endless opportunities for ingenuity.
        </p>
    )";

    // Create the QMessageBox
    QMessageBox welcomeBox;
    welcomeBox.setWindowTitle("Welcome to Qt Academy");
    welcomeBox.setText(welcomeText);
   // welcomeBox.setIcon(QMessageBox::Information); // Set the icon (optional)
    welcomeBox.setStandardButtons(QMessageBox::Ok); // Add an OK button
    welcomeBox.setStyleSheet("background-color: #006F6A; color: white;"); // Customize the background color

    // Show the message box
    welcomeBox.exec();
}



void MainWindow::on_actionAbout_triggered()
{
    QApplication::aboutQt();
}


void MainWindow::on_actionExplore_triggered()
{

}


void MainWindow::on_actionSearch_triggered()
{

}

