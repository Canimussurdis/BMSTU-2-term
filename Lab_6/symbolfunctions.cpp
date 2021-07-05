#include "symbolfunctions.h"

symbolFunctions::symbolFunctions()
{
    quote_is_allowed = false;
    now_in_quotes = false;
    colon_is_allowed = false;
    comma_is_allowed = false;
    dtfn_is_allowed = false;
    op_brace_is_allowed = true;
    op_sq_bracket_is_allowed = false;
    cl_brace_is_allowed = false;
    cl_sq_bracket_is_allowed = false;
    in_brace_comma_not_allowed = false;
    root_object_brace_opened = false;
    is_correct = true;
}


bool symbolFunctions::getStatus()
{
    return is_correct;
}
string symbolFunctions::getComment()
{
    return comment;
}


void symbolFunctions::foundOpBrace()
{
    if (!op_brace_is_allowed || (stack.size() == 0 && root_object_brace_opened))
    {
        is_correct = false;
        comment = "Встречена неожиданная { в строке номер ";
    }
    else
    {
        stack.push_back('{');
        root_object_brace_opened = true;
        in_brace_comma_not_allowed = true;
        quote_is_allowed = true;
        colon_is_allowed = false;
        comma_is_allowed = false;
        dtfn_is_allowed = false;
        op_brace_is_allowed = false;
        op_sq_bracket_is_allowed = false;
        cl_brace_is_allowed = false;
        cl_sq_bracket_is_allowed = false;
    }
}
void symbolFunctions::foundClBrace()
{
    if (!cl_brace_is_allowed || stack[stack.size() - 1] != '{')
    {
        is_correct = false;
        comment = "Встречена неожиданная } в строке номер ";
    }
    else
    {
        stack.pop_back();
        quote_is_allowed = false;
        colon_is_allowed = false;
        comma_is_allowed = true;
        dtfn_is_allowed = false;
        op_brace_is_allowed = false;
        op_sq_bracket_is_allowed = false;
        cl_brace_is_allowed = true;
        cl_sq_bracket_is_allowed = true;
    }
}
void symbolFunctions::foundOpSqBracket()
{
    if (!op_sq_bracket_is_allowed || stack.size() == 0)
    {
        is_correct = false;
        comment = "Встречена неожиданная [ в строке номер ";
    }
    else
    {
        stack.push_back('[');
        quote_is_allowed = true;
        colon_is_allowed = false;
        comma_is_allowed = false;
        dtfn_is_allowed = true;
        op_brace_is_allowed = true;
        op_sq_bracket_is_allowed = false;
        cl_brace_is_allowed = false;
        cl_sq_bracket_is_allowed = true;
    }
}
void symbolFunctions::foundClSqBracket()
{
    if (!cl_sq_bracket_is_allowed || stack[stack.size() - 1] != '[')
    {
        is_correct = false;
        comment = "Встречена неожиданная ] в строке номер ";
    }
    else
    {
        stack.pop_back();
        quote_is_allowed = false;
        colon_is_allowed = false;
        comma_is_allowed = true;
        dtfn_is_allowed = false;
        op_brace_is_allowed = false;
        op_sq_bracket_is_allowed = false;
        cl_brace_is_allowed = true;
        cl_sq_bracket_is_allowed = true;
    }
}
void symbolFunctions::foundDTFN()
{
    if (!dtfn_is_allowed)
    {
        if (!now_in_quotes)
        {
            is_correct = false;
            comment = "Встречено неожиданное системное слово или число в строке номер ";
        }
    }
    else
    {
        quote_is_allowed = false;
        colon_is_allowed = false;
        comma_is_allowed = true;
        dtfn_is_allowed = true;
        op_brace_is_allowed = false;
        op_sq_bracket_is_allowed = false;
        cl_brace_is_allowed = true;
        cl_sq_bracket_is_allowed = true;
    }
}
void symbolFunctions::foundQuote()
{
    if (!quote_is_allowed)
    {
        is_correct = false;
        comment = "Встречена неожиданная \" в строке номер ";
    }
    else
    {
        if (!now_in_quotes)
        {
            now_in_quotes = true;
            quote_is_allowed = true;
            colon_is_allowed = false;
            comma_is_allowed = false;
            dtfn_is_allowed = false;
            op_brace_is_allowed = false;
            op_sq_bracket_is_allowed = false;
            cl_brace_is_allowed = false;
            cl_sq_bracket_is_allowed = false;
        }
        else
        {
            now_in_quotes = false;
            quote_is_allowed = false;
            colon_is_allowed = true;
            comma_is_allowed = true;
            dtfn_is_allowed = false;
            op_brace_is_allowed = false;
            op_sq_bracket_is_allowed = false;
            cl_brace_is_allowed = true;
            cl_sq_bracket_is_allowed = true;
        }
    }
}
void symbolFunctions::foundColon()
{
    if (!colon_is_allowed || stack[stack.size() - 1] == '[')
    {
        if(!now_in_quotes)
        {
            is_correct = false;
            comment = "Встречено неожиданное : в строке номер ";
        }
    }
    else
    {
        in_brace_comma_not_allowed = false;
        quote_is_allowed = true;
        colon_is_allowed = false;
        comma_is_allowed = false;
        dtfn_is_allowed = true;
        op_brace_is_allowed = true;
        op_sq_bracket_is_allowed = true;
        cl_brace_is_allowed = false;
        cl_sq_bracket_is_allowed = false;
    }
}
void symbolFunctions::foundComma()
{
    if (!comma_is_allowed || in_brace_comma_not_allowed)
    {
        if (!now_in_quotes)
        {
            is_correct = false;
            comment = "Встречена неожиданная , в строке номер ";
        }
    }
    else
    {
        if (stack[stack.size() - 1] == '{')
            in_brace_comma_not_allowed = true;
        quote_is_allowed = true;
        colon_is_allowed = false;
        comma_is_allowed = false;
        dtfn_is_allowed = true;
        op_brace_is_allowed = true;
        op_sq_bracket_is_allowed = true;
        cl_brace_is_allowed = false;
        cl_sq_bracket_is_allowed = false;
    }
}
void symbolFunctions::foundElseSymbol()
{
    is_correct = false;
    comment = "Встречено неожиданное несистемное слово в строке номер ";
}
