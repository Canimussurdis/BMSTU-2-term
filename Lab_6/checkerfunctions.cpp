#include "checkerfunctions.h"

bool checkerFunctions::isSystemSymbol(char symbol)
{
    bool isSystemSymbol = false;

    if (symbol == '[' || symbol == ']' || symbol == '{' || symbol == '}' || symbol == '\"' || symbol == ',' || symbol == ':')
        isSystemSymbol = true;

    return isSystemSymbol;

}

bool checkerFunctions::isBracket(char symbol)
{
    bool isSystemSymbol = false;

    if (symbol == '[' || symbol == ']' || symbol == '{' || symbol == '}')
        isSystemSymbol = true;

    return isSystemSymbol;

}

bool checkerFunctions::isSpaceSymbol(char symbol)
{
    bool isSpaceSymbol = false;

    if (symbol == ' ' || symbol == '\n' || symbol == '\t')
        isSpaceSymbol = true;

    return isSpaceSymbol;

}

char checkerFunctions::identifyNonSystemStringType(string str)
{
    char result;
    bool all_chars_are_digits = true;
    for (int i = 0; i < str.length() && all_chars_are_digits; i++)
    {
        if (!((0 <= str[i] - '0' && str[i] - '0' <= 9) || str[i] == '-' || str[i] == '.'))
            all_chars_are_digits = false;
    }

    if (all_chars_are_digits)
        result = 'd';
    else if (str == "true")
        result = 't';
    else if (str == "false")
        result = 'f';
    else if (str == "null")
        result = 'n';
    else
        result = 'e'; // else

    return result;
}
