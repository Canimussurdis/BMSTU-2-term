#ifndef SYMBOLFUNCTIONS_H
#include <iostream>
#include <vector>
#define SYMBOLFUNCTIONS_H

using namespace std;

class symbolFunctions
{
private:
    bool quote_is_allowed;
    bool now_in_quotes;
    bool colon_is_allowed;
    bool comma_is_allowed;
    bool dtfn_is_allowed;
    bool op_brace_is_allowed;
    bool op_sq_bracket_is_allowed;
    bool cl_brace_is_allowed;
    bool cl_sq_bracket_is_allowed;
    bool in_brace_comma_not_allowed;
    bool root_object_brace_opened;

    bool is_correct;
    string comment;
    vector<int> stack;
public:
    symbolFunctions();

    bool getStatus();
    string getComment();

    void foundOpBrace();
    void foundClBrace();
    void foundOpSqBracket();
    void foundClSqBracket();
    void foundDTFN();
    void foundQuote();
    void foundColon();
    void foundComma();
    void foundElseSymbol();

};

#endif // SYMBOLFUNCTIONS_H
