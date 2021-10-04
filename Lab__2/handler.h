#ifndef HANDLER_H
#include <QMainWindow>
#include <fstream>
#include <QStandardItemModel>
#define HANDLER_H

using namespace std;

struct Record
    {
        int year;
        string region;
        float npg;
        float birthRate;
        float deathRate;
        float gdw;
        float urbanization;

        float arr[7];
    };

struct Request {
        int action;
        string path;
        string region;
        int metricColumn;
        vector<string> loadedData;
        vector<Record> records;
        int col;
        QVector<double> x;
        QVector<double> y;
    };

struct Response {
        int status;
        vector<Record> records;
        float* metrics;
        vector<string> loadedData;
//        vector<Record>* recmetr;
    };

Response* execute(Request* request);

#endif // HANDLER_H
