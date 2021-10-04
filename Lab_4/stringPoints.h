#ifndef STRINGPOINTS_H
#include <vector>
#include <string>
#include "drawhandler.h"
#include <stdlib.h>
#include "logic.h"
#include "filehandler.h"
#include "metrichandler.h"
#include "logic.h"
#define STRINGPOINTS_H

#define SIZE 20

void splitString(string input, string* output);
void setPoints(Request* request, Point** points, int rows, int cols);

#endif // STRINGPOINTS_H
