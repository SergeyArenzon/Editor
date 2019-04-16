//
// Created by sergey on 4/15/19.
//

#include "Editor.hpp"

#include <iostream>
#include <sstream>
int checkIfInt(string input){

    std::istringstream s(input);
    int x;
    if (!(s >> x)) {
        return -1;
    }
    return x;
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

    }
}



int main(){
    Editor e;
    e.loop();

    return 0;
}