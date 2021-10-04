#ifndef MAINWINDOW_H
#include <QMainWindow>
#include <QStandardItemModel>
#include <QVector>
#include <QPen>
#include "handler.h"
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
    void on_fileSelect_bttn_clicked();

    void on_loadDataButton_clicked();

    void on_calcButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    vector<string> loadedData;

    double xBegin, xEnd, xStep;
    double yBegin, yEnd, yStep;
    QVector<double> x, y;
    QVector<double> xLine;
    QPen* redPen, *greenPen, *orangePen;

    void drawGaphic(float* metrics, int col);
    void drawLine(double yValue, int inx, QPen* pen, QString name);
};
#endif // MAINWINDOW_H
