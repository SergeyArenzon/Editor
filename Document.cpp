//
// Created by sergey on 4/15/19.
//

#include <iostream>
#include "Document.hpp"
using namespace std;

Document::Document(){
    currLine=1;
    lines=vector <string>();
}
void Document::p()const{
    cout<<lines.at(currLine-2)<<endl;
}
void Document::n()const {
    cout<<currLine-1<<"   "<<lines.at(currLine-2)<<endl;
}
void Document::percentP() {
    for (vector<string>::iterator it = lines.begin() ; it != lines.end(); ++it)
        cout << *it<<endl;
    }
void Document::changeCurrLine(int lineNumber) {
    currLine=lineNumber+1;
    p();
}
void Document::a(string line) {
    lines.insert(lines.begin()+currLine-1,line);
    currLine++;
}
void Document::i(string line) {
    lines.insert(lines.begin()+currLine-2,line);
    currLine--;


}
void Document::c(string line) {
    lines.at(currLine-2).assign(line);
}
void Document::d(){
    lines.erase(lines.begin()+currLine-2);
}
void Document::text(string text) {
    for (vector<string>::iterator it = lines.begin()+currLine-1 ; it != lines.end(); ++it)
        cout << *it<<endl;
}







