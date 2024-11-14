#include "mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include<QApplication>
#include<QAction>
#include<QMenu>
#include<QMenuBar>
#include<QStatusBar>
#include<QMessageBox>


MainWindow::MainWindow()
{
    // Create a central widget and set it to the MainWindow
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create a layout for the central widget
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Adjust layout margins to position the button
    layout->setContentsMargins(325, 50, 0, 0); // Left, Top, Right, Bottom

    // Create a button and add it to the layout
    QPushButton *button = new QPushButton("submit", this);
    button->setFixedWidth(100);
    layout->addWidget(button);

    // Set the central widget layout
    centralWidget->setLayout(layout);

    connect(button,&QPushButton::clicked, [=](){

        //menually
        QMessageBox message;
        /* message.setWindowTitle("Alret");
        message.setIcon(QMessageBox::Warning);
        message.setText("Form 1");
        message.setInformativeText("are you sure you want to submit");
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message.setDefaultButton(QMessageBox::Cancel);

        int response = message.exec();*/
        int response = QMessageBox::warning(this, "Alert", "Are you sure you want to submit?",
                                            QMessageBox::Ok | QMessageBox::Cancel);

        if (response == QMessageBox::Ok) {
            QMessageBox newMessage;
            newMessage.setIcon(QMessageBox::Information); 
            newMessage.setWindowTitle("Submitted");
            newMessage.setText("Form has been submitted.");
            newMessage.exec();  // Display the message box
            qInfo() << "Form has been submitted.";
        }

        if (response == QMessageBox::Cancel) {
            QMessageBox newMessage;
            newMessage.setIcon(QMessageBox::Warning);
            newMessage.setWindowTitle("Cancelled");
            newMessage.setText("Submission cancelled.");
            newMessage.exec();  
            qInfo() << "Cancelled!";
        }

    });



    quitAction = new QAction("❌ Exit");
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    //Add Menu
    QMenu *FileMenu = menuBar()->addMenu("File");
    FileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Build");
    menuBar()->addMenu("Debug");
    menuBar()->addMenu("Help");


    statusBar()->showMessage(tr("Ready"), 1000);

    //statusBar()->showMessage("Ready...");
    //statusBar()->clearMessage();




}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}
