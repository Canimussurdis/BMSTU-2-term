#ifndef MAINWINDOW_H
#include <QMainWindow>
#include "logic.h"
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
    void on_fileDialog_bttn_clicked();

    void on_fileLoad_bttn_clicked();

    void on_draw_bttn_clicked();

    void on_rotate_x_bttn_clicked();

    void on_rotate_y_bttn_clicked();

    void on_rotate_z_bttn_clicked();

    void on_offset_x_bttn_clicked();

    void on_offset_y_bttn_clicked();

    void on_offset_z_bttn_clicked();

    void on_rotate_x_back_bttn_clicked();

    void on_rotate_y_back_bttn_clicked();

    void on_rotate_z_back_bttn_clicked();

    void on_normalization_bttn_clicked();

private:
    Ui::MainWindow *ui;
    vector<string> loadedData;

    void displayError(std::string message);

    void drawSurface(Line* lines, int count);

    void drawLine(QPainter* paint, Line* line);

    void rotationHandler(Axis axis, int direction = 1);

    void offsetHandler(Axis axis);
};
#endif // MAINWINDOW_H
