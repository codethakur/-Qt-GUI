#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTabWidget>
#include <QTextEdit>
#include <QTabBar>
#include <QDebug>
#include <QLineEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tabWidget(new QTabWidget(this))   // Initialize tab widget
    , textEditor(new QTextEdit(this))  // Initialize placeholder editor
{
    ui->setupUi(this);

    setMenuBar(ui->menubar);

    tabWidget->setTabsClosable(true);
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);

    textEditor->setDisabled(true);
    textEditor->setPlaceholderText("Click 'New Text File' to start writing");
    textEditor->setAlignment(Qt::AlignHCenter);  // Align the placeholder text to the center
    // Set the placeholder editor initially
    setCentralWidget(textEditor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createNewTab()
{
    if (centralWidget() != tabWidget) {
        setCentralWidget(tabWidget);  // ✅ Ensure tabWidget is active
    }

    QString tabTitle = QString("Untitled-%1").arg(tabWidget->count() + 1);

    QTextEdit *textEdit = new QTextEdit(tabWidget);  // ✅ Correct parent
    tabWidget->addTab(textEdit, tabTitle);
    tabWidget->setCurrentWidget(textEdit);  // Focus on new tab
}



void MainWindow::on_actionNew_Text_File_triggered()
{
    createNewTab();
}
void MainWindow::closeTab(int index)
{
    QWidget *tabPage = tabWidget->widget(index);

    if (tabPage) {
        tabWidget->removeTab(index);   // Remove from UI
        tabPage->setParent(nullptr);   // Detach safely
        tabPage->deleteLater();        // Safe deletion
    }

    if (tabWidget->count() == 0) {
        int result = QMessageBox::warning(this, "Message title", 
                    "All tabs are closing. Do you want to close the application?",
                    QMessageBox::Ok | QMessageBox::Cancel);

        if (result == QMessageBox::Ok) {
            on_actionExit_triggered();  // Exit the application
        } else if (result == QMessageBox::Cancel) {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);  // Corrected icon setting
            msgBox.setText("Click 'New Text File' to start editing.");
            msgBox.exec();
        }
    }
}






void MainWindow::on_actionOpen_triggered()
{
    // To be implemented
}

void MainWindow::on_actionSave_triggered()
{
    // To be implemented
}

void MainWindow::on_actionSaveAs_triggered()
{
    // To be implemented
}

void MainWindow::on_actionExit_triggered()
{
    close();  // Gracefully exit the application
}
