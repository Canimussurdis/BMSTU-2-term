#include "mainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("C:/Qt/ProgrammingIntermidiate/Lab_1_final/logo_2.png"));
    MainWindow w;
    w.show();
    return a.exec();
}
