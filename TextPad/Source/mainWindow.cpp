#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QApplication>
#include <QTextStream>
#include<QMessageBox>
#include <QStatusBar>
#include<QTimer>
#include<QFileDialog>
#include<QFile>
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

void MainWindow::on_NewFile_triggered()
{

}


void MainWindow::on_NewWindow_triggered()
{
    MainWindow* newWindow = new MainWindow(this);

    // Show the new window
    newWindow->show();
    QDialog* newDialog = new QDialog(this);

    // Show the dialog
    //newDialog->exec();
}


void MainWindow::on_OpenFile_triggered()
{
     QString defaultDir = QDir::currentPath(); // Default to the current directory
    static QString lastDir = defaultDir; // Static variable to remember last directory used

    // Open a file dialog
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), lastDir, tr("Text Files (*.txt);;All Files (*)"));

    // Check if user selected a file
    if (!fileName.isEmpty()) {
        lastDir = QFileInfo(fileName).absolutePath(); // Update last used directory

        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll()); // Load file content into textEdit
            file.close();

            ui->textEdit->document()->setModified(false); // Reset modified flag
        } else {
            QMessageBox::warning(this, tr("Open File"), tr("Failed to open the selected file."));
        }
    }

}


void MainWindow::on_OpenFolder_triggered()
{

}


void MainWindow::on_ExitWindow_triggered()
{
    if (ui->textEdit->document()->isModified()) {
        // Show a warning message box to confirm exit
        QMessageBox::StandardButton reply;
        reply = QMessageBox::warning(
            this,
            "TextPad",
            "The document has unsaved changes. Are you sure you want to exit?",
            QMessageBox::Yes | QMessageBox::No
            );

        // Handle the user's response
        if (reply == QMessageBox::Yes) {
            statusBar()->showMessage(tr("Quit"), 1000); // Show the message for 2 seconds
            QTimer::singleShot(1000, this, []() {
                QApplication::quit(); // Exit the application after delay
            });
        }
    } else {
        statusBar()->showMessage(tr("Quit"), 000); // Show the message for 2 seconds
        QTimer::singleShot(1000, this, []() {
            QApplication::quit();
        });
    }
}




void MainWindow::on_Cut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_Copy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_Paste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_Undo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_Redo_triggered()
{
  ui->textEdit->redo();
}


void MainWindow::on_Find_triggered()
{

}


void MainWindow::on_welcome_triggered()
{
    // Create the QMessageBox
    QMessageBox welcomeBox;
    welcomeBox.setWindowTitle("Welcome to Qt Academy");
    welcomeBox.setText(WELCOME_TEXT); // Use the constant defined in the header file
    welcomeBox.setStandardButtons(QMessageBox::Ok); // Add an OK button
    welcomeBox.setStyleSheet("background-color: #006F6A; color: white;"); // Customize the background color

    welcomeBox.exec();
}


void MainWindow::on_Layout_triggered()
{

}


void MainWindow::on_About_triggered()
{
    QApplication::aboutQt();
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
            ui->textEdit->document()->setModified(false);

        }else{
            QMessageBox::warning(this, tr("Save File"), tr("Failed to save file."));
        }
    }

}

