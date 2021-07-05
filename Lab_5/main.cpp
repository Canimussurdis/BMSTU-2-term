#include <QCoreApplication>
#include "testFunctions.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    lauch_tests();
    return a.exec();
}

