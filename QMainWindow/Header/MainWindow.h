#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

    // QWidget interface
private:
    QSize sizeHint() const;
    QAction *quitAction;
};

#endif // MAINWINDOW_H
