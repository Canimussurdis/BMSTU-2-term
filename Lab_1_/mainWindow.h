#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool OnlyDigits();
    void SetDigits(bool);
    void checkNumber();

private:
    Ui::MainWindow *ui;
    QWidget* defaultCalcWidget;
        QWidget* simpleCalcWidget;
        QWidget* complCalcWidget;
        QWidget* mainWidget;

        QGridLayout* defaultCalcLayout;
        QGridLayout* simpleCalcLayout;
        QGridLayout* complCalcLayout;
        QGridLayout* mainLayout;

        void CreateDefaultCalcWidget();
        void CreateSimpleCalcWidget();
        void CreateComplCalcWidget();
        void SpawnSimpleMode();
        void SpawnComplMode();

        bool digits_only = true;

private slots:
    void SwitchMode();
    void NumberClicked();
    void UnFnClicked();
    void BinFnClicked();
    void DotClicked();
    //void LBracketClicked();
    //void RBracketClicked();
    void ClearInput();
    void BackSpace();
    void Equals();
    void ChangeSignClicked();

};
#endif // MAINWINDOW_H
