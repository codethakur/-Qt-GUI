#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_AddButton_clicked();

    void on_RemoveButton_clicked();

    void on_ButtonButton_clicked();

    void on_selectButton_clicked();

private:
    Ui::Widget *ui;
    int maxItem =5;
};
#endif // WIDGET_H
