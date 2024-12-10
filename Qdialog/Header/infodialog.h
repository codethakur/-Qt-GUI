#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class infoDialog;
}

class infoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoDialog(QWidget *parent = nullptr);
    ~infoDialog();


    const QString &Position() const;
    const QString &OS() const;

private slots:
    void on_OkButton_clicked();

    void on_cancelButton_clicked();

private:
    QString m_Position;
    QString m_OS;
    Ui::infoDialog *ui;
};

#endif // INFODIALOG_H
