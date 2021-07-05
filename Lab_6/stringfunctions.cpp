#include "stringfunctions.h"

int stringFunctions::substrCount(string substr, string line)
{
    int pos = line.find(substr);
    int count = 0;
    while (pos != string::npos)
    {
        count++;
        pos = line.find(substr, pos + 1);
    }
    return count;
}

string* stringFunctions::split(string delimeter, string line)
{
    int del_count = substrCount(delimeter, line);
    string* arr = new string[del_count + 1];
    int substr_start = 0;
    int substr_end = line.find(delimeter);
    for (int i = 0; i < del_count + 1; i++)
    {
        arr[i] = line.substr(substr_start, substr_end - substr_start);
        substr_start = substr_end + delimeter.length();
        substr_end = line.find(delimeter, substr_start);
    }

    return arr;
}

int stringFunctions::countLines(string text)
{
    int count = 0;
    int i = 0;
    while (!(text[i] == '\0'))
    {
        if (text[i] == '\n')
            count++;
        i++;
    }

    return count;
}
