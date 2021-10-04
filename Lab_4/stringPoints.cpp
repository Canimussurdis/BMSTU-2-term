#include "stringPoints.h"

void splitString(string input, string* output)
{
    string delimiter = ",";
    int i = 0;

    size_t pos = 0;
    string str;

    while ((pos = input.find(delimiter)) != string::npos)
    {
        str = input.substr(0, pos);

        output[i] = str;
        i++;

        input.erase(0, pos + delimiter.length());
    }

    output[i] = input;
}

void setPoints(Request* request, Point** points, int rows, int cols)
{
    string arr[SIZE];

    for (int i = 0; i < rows; i++)
    {
        splitString((request->loadedData)[i], arr);

        for (int j = 0; j < cols; j++)
        {
            Point point;
            setPoint(&point, (float)i, (float)j, (float)atof(arr[j].c_str()));

            points[i][j] = point;
        }
    }
}
