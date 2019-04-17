//
// Created by sergey on 4/15/19.
//

#ifndef C_ADV_AS2_DOCUMENT_HPP
#define C_ADV_AS2_DOCUMENT_HPP

#endif //C_ADV_AS2_DOCUMENT_HPP


#include <string>
#include <vector>

using namespace std;
class Document{
public:
    Document();
    int currLine;
    vector <string> lines;
    void p()const;//prints curr line
    void n()const;//prints number of line + line
    void percentP();//prints all lines
    void changeCurrLine(int lineNumber);//changes currLine to lineNumber
    void a(string line);//insert txt to ++curr line
    void i(string line);//insert txt to --curr line
    void c(string line);//insert txt to curr line
    void d();//deletes curr line
    void text(string text);
    void replace(string oldStr,string newStr);
    void Q();
};