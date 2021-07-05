#ifndef STRINGFUNCTIONS_H
#include <iostream>
#define STRINGFUNCTIONS_H

using namespace std;
class stringFunctions
{
public:
    static int substrCount(string substr, string line);
    static string* split(string delimeter, string line);
    static int countLines(string text);
};
#endif // STRINGFUNCTIONS_H
