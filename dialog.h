#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setupDialog(QList<QString> names);
    ~Dialog();
    QList<QLineEdit *> logins;

private slots:

    void on_button_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
