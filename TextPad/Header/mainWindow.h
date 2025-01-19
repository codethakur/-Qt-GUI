#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();
    void on_actionExit_triggered();
    void on_actionNew_Text_File_triggered();
    void closeTab(int index);  // Close tabs

private:
    Ui::MainWindow *ui;
    QTabWidget *tabWidget;  // Used for tab functionality
    QTextEdit *textEditor;   // Placeholder editor in the first tab

    void createNewTab();  // Helper to create new tabs

};

#endif // MAINWINDOW_H
