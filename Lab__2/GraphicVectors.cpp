#include "GraphicVectors.h"
#include <handler.h>
//vector<Record>* records = new vector<Record>;

void setGraphicVectors(vector<Record> records, QVector<double> *x, QVector<double> *y, int col)
{
    for (int i = 0; i < records.size(); i++)
    {
        (*x).push_back((records)[i].year);
        (*y).push_back((records)[i].arr[col]);
    }
}
