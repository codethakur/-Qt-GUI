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
    static constexpr const char* WELCOME_TEXT = R"(
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


private slots:
    void on_NewFile_triggered();

    void on_NewWindow_triggered();

    void on_OpenFile_triggered();

    void on_OpenFolder_triggered();

    void on_ExitWindow_triggered();

    void on_Cut_triggered();

    void on_Copy_triggered();

    void on_Paste_triggered();

    void on_Undo_triggered();

    void on_Redo_triggered();

    void on_Find_triggered();

    void on_welcome_triggered();

    void on_Layout_triggered();

    void on_About_triggered();

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
