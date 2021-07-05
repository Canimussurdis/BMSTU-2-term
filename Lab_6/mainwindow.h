#ifndef MAINWINDOW_H
#include <QMainWindow>
#include "fileloader.h"
#include "fileparser.h"
#define MAINWINDOW_H

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_file_clicked();

    void on_button_check_clicked();

private:
    fileLoader loader;
    fileParser parser;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
