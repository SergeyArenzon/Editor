//
// Created by Sergey Arenzon 321211286 on 4/15/19.
//

#include <iostream>
#include "Document.h"
using namespace std;
void token(string& line,string input,string newWord){


    size_t from = line.find(input);
    size_t to=from+input.size();
    std::vector<char> chars(line.c_str(), line.c_str() + line.size() + 1u);

    string newLine="";
    int i=0;
    while(i<from){
        newLine=newLine+line.at(i);
        i++;
    }
    newLine=newLine+newWord;
    i=to;
    while(i<line.size()){
        newLine=newLine+line.at(i);
        i++;


    }


    line=newLine;


}
Document::Document(){
    currLine=1;
    lines=vector <string>();
}
void Document::p()const{
    cout<<lines.at(currLine-2)<<endl;
}
void Document::n()const {
    cout<<currLine-1<<"     "<<lines.at(currLine-2)<<endl;
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

    int counter=1;
    for (vector<string>::iterator it = lines.begin() ; it != lines.begin()+currLine ; ++it){
       if((*it).find(text)!= std::string::npos) {
           cout<<*it<<endl;
           currLine=counter+1;
           break;
       }
       counter++;
    }

}
void Document::replace(string oldStr,string newStr) {
    token(lines.at(currLine-2),oldStr,newStr);
}
void Document::Q() {



}







