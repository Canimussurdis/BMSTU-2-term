#include "fileparser.h"
#include "stringfunctions.h"
#include "checkerfunctions.h"
#include <vector>
#include "symbolfunctions.h"

fileParser::fileParser(): file_text(""), comment("Ошибки не обнаружены"){    }

fileParser::fileParser(string text): file_text(text), comment("Ошибки не обнаружены"){   }

bool fileParser::getStatus()
{
    return is_correct;
}

string fileParser::getComment()
{
    return comment;
}

void fileParser::parse()
{
    checkSyntaxErrors();
}

void fileParser::checkSyntaxErrors()
{
    string* file_arr = stringFunctions::split("\n", file_text);
    int num_of_lines = stringFunctions::countLines(file_text);
    symbolFunctions flag_holder = symbolFunctions();
    for(int i = 0; i < num_of_lines && is_correct; i++)
    {
        file_arr[i] = makeLineSyntaxPattern(file_arr[i]);
        for(int j = 0; j < file_arr[i].length() && flag_holder.getStatus(); j++)
        {
            switch (file_arr[i][j]){
            case '{':
                flag_holder.foundOpBrace();
                break;
            case '}':
                flag_holder.foundClBrace();
                break;
            case '[':
                flag_holder.foundOpSqBracket();
                break;
            case ']':
                flag_holder.foundClSqBracket();
                break;
            case 'd':
            case 't':
            case 'f':
            case 'n':
                flag_holder.foundDTFN();
                break;
            case '\"':
                flag_holder.foundQuote();
                break;
            case ':':
                flag_holder.foundColon();
                break;
            case',':
                flag_holder.foundComma();
                break;
            case'e':
                flag_holder.foundElseSymbol();
                break;
            }

        }

        if(!flag_holder.getStatus())
        {
            is_correct = false;
            comment = flag_holder.getComment() + to_string(i + 1);
        }
    }

}

string fileParser::makeLineSyntaxPattern(string line)
{
    line += '\n';
    string new_line;
    string cur_word;
    bool in_word = false, now_in_quotes = false;
    for(int i = 0; i < line.length(); i++)
    {
        char cur_symbol = line[i];
        if (checkerFunctions::isSystemSymbol(cur_symbol))
        {

            if (!in_word)
                new_line += cur_symbol;
            else
            {
                addCurWordToNewLine(&cur_word, &new_line, &in_word, now_in_quotes);
                new_line += cur_symbol;
            }

            if(cur_symbol == '\"')
                now_in_quotes = !now_in_quotes;
        }
        else if (checkerFunctions::isSpaceSymbol(cur_symbol))
        {
            if (in_word)
            {
                addCurWordToNewLine(&cur_word, &new_line, &in_word, now_in_quotes);
            }
        }
        else
        {
            if (!in_word)
                in_word = true;
            cur_word += cur_symbol;
        }
    }
    return new_line;
}

void fileParser::addCurWordToNewLine(string *cur_word, string *new_line, bool *in_word, bool now_in_quotes)
{
    *cur_word = checkerFunctions::identifyNonSystemStringType(*cur_word);
    if (*cur_word != "e")
        *new_line += *cur_word;
    else if (!now_in_quotes)
        *new_line += *cur_word;
    *cur_word = "";
    *in_word = false;
}
