#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <lib/parser.h>
#include <dialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_clicked()
{
    QString str;
    str = QFileDialog::getOpenFileName(this, "Выбрать файл");
    ui->label->setText(str);

    Parser *parser = new Parser();
    parser->loadFile(str);
    parser->parseFiredEmployes();

    QList<QString> firedEmployes = parser->firedEmployes;
    foreach (auto firedEmployee, firedEmployes) {
            qDebug() << firedEmployee;
        }
    this->close();

    Dialog *dialog = new Dialog();

    dialog->setupDialog(firedEmployes);
}


