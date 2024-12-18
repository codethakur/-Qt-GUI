#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionExit_triggered();

    void on_actionSave_triggered();

    void on_actionNew_Window_triggered();

    void on_actionNew_File_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionFind_triggered();

    void on_actionRun_triggered();

    void on_actionAbout_triggered();

    void on_actionWelcome_triggered();

    void on_actionExplore_triggered();

    void on_actionSearch_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
