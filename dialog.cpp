#include "dialog.h"
#include "ui_dialog.h"
#include <QFormLayout>
#include <QList>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QObject>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //
}

Dialog::~Dialog()
{
    //
}

void Dialog::setupDialog(QList<QString> names)
{
    QFormLayout *layout = new QFormLayout(this);

    foreach (auto name, names) {
        QLabel *label = new QLabel(name);
        QLineEdit *edit = new QLineEdit();
        this->logins<<edit;

        layout->addRow(label, edit);
    }
    QPushButton *button = new QPushButton("create script");
    layout->addRow(button);
    connect(button,SIGNAL(clicked()),this,SLOT(on_button_clicked()));
    this->setModal(true);
    this->exec();

}

void Dialog::on_button_clicked()
{
    QFile file ("script.ps1");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    foreach (auto login, this->logins)
    {
        out <<"Remove-ADUser "<<login->text()<<"\n";
    }
    file.close();
}

