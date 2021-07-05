#ifndef FILEPARSER_H
#include <iostream>
#define FILEPARSER_H

using namespace std;

class fileParser
{
private:
    string file_text;
    bool is_correct = true;
    int error_line;
    string comment;
public:
    fileParser();
    fileParser(string text);

    bool getStatus();
    string getComment();

    void parse();
    void checkBracketErrors();
    void checkSyntaxErrors();

    string makeLineSyntaxPattern(string line);
    void addCurWordToNewLine(string *cur_word, string *new_line, bool *in_word, bool now_in_quotes);

};

#endif // FILEPARSER_H
