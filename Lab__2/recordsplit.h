#ifndef RECORDSPLIT_H
#include "handler.h"
#include <QDebug>
#include <vector>
#include <stdlib.h>
#include <QVector>
#define RECORDSPLIT_H

using namespace std;

void splitString(string input, string* output);
void setRecord(Record* record, string* arr);
void setRecords(Response* response <recmetr>, string region);

#endif // RECORDSPLIT_H
