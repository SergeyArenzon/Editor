//
// Created by Sergey Arenzon 321211286 on 4/15/19.
//

#include "Editor.h"

#include <iostream>
#include <sstream>
#include <cstring>


int checkIfInt(string input){

    std::istringstream s(input);
    int x;
    if (!(s >> x)) {
        return -1;
    }
    return x;
}


vector<string> splitHelper(string input){

    std::stringstream test(input);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(test, segment, '/'))
    {
        seglist.push_back(segment);
    }

    return seglist;

}

Editor::Editor(){
     doc=Document();
}
void Editor::loop() {
    bool dotPressed=false;
    bool stop = false;
    string input;
    while (stop == false) {
        getline(cin, input);
        if (input.compare("c") == 0) {
            int counter=0;
            while(dotPressed==false){
                getline(cin, input);
                if(input.compare(".")==0){
                    dotPressed=true;
                }
                else {
                    if(counter==0) doc.c(input);
                    else doc.a(input);
                }
                counter++;
            }
            dotPressed=false;
        }
        else if (input.compare("p") == 0) doc.p();
        else if(input.compare("n") == 0) doc.n();
        else if(input.compare("%p") == 0) doc.percentP();
        else if(checkIfInt(input)>0) doc.changeCurrLine(checkIfInt(input));
        else if(input.compare("a") == 0){
          while(dotPressed==false){
             getline(cin, input);
             if(input.compare(".")==0){
                 dotPressed=true;
             }   else doc.a(input);
          }
            dotPressed=false;
        }
        else if(input.compare("i") == 0){
            while(dotPressed==false){
                getline(cin, input);
                if(input.compare(".")==0){
                    dotPressed=true;
                }   else doc.i(input);

            }
            dotPressed=false;
        }
        else if(input.compare("d") == 0) doc.d();
        else if (input.find("/") == 0) {
           input.erase(0, 1);
           doc.text(input);
        }
        else if (input.find("s/") == 0) {
            input.erase(0, 2);
            vector <string>v = splitHelper(input);
            if(v.size()>2){
                cout<<"?"<<endl;
            }else{
                string oldStr = v.at(0);
                string newStr = v.at(1);
                doc.replace(oldStr,newStr);
            }
        }
        else if(input.find("q")) stop = true;
        else cout<<"?"<<endl;
    }
   return;
}



