#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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


void MainWindow::on_button_file_clicked()
{
    QString path = QFileDialog::getOpenFileName(0, tr("Open File"), "../", tr("(*.json)"));
    ui->label_file->setText(path);
    ui->label_status->setText("");
    ui->label_comment->setText("");
    loader = fileLoader(path.toStdString());
    ui->plainTextEdit->setPlainText(QString::fromStdString(loader.getFileText()));
}

void MainWindow::on_button_check_clicked()
{
    parser = fileParser(loader.getFileText());
    parser.parse();
    if (parser.getStatus())
    {
        ui->label_status->setText("Файл корректный");
        ui->label_comment->setText(QString::fromStdString(parser.getComment()));
    }
    else
    {
        ui->label_status->setText("Файл некорректный");
        ui->label_comment->setText(QString::fromStdString(parser.getComment()));
    }
}
