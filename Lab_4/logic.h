#ifndef LOGIC_H
#include <vector>
#include <string>
#include "drawhandler.h"
#define LOGIC_H

using namespace std;

enum Operations
{
    LOAD_DATA,
    DRAW,
    ROTATE,
    OFFSET,
    NORMALIZE,
    FREE_MEMORY
};

struct Request
{
    int operation;
    string fileName;
    Axis axis;
    float rotationAngle;
    float offsetValue;
    float normalization[2];
    vector<string> loadedData;
};

struct Response
{
    bool done = true;
    string message;
    int lineCount;
    vector<string> loadedData;
    Line* lines;
};

Response* execute(Request* request);

#endif // LOGIC_H
