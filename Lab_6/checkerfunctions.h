#ifndef CHECKERFUNCTIONS_H
#include <iostream>
#define CHECKERFUNCTIONS_H

using namespace std;

class checkerFunctions
{
public:
    static bool isSystemSymbol(char symbol);
    static bool isBracket(char symbol);
    static bool isSpaceSymbol(char symbol);
    static char identifyNonSystemStringType(string str);
};

#endif // CHECKERFUNCTIONS_H
