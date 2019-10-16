#include <iostream>
#include "Syntax.h"
#include "FileInOut.h"
#include <fstream>


using namespace std;

//let s be an empty stack
Syntax::Syntax(){
}

bool Syntax::areSyntaxMatch(ifstream& file, GenStack<char>& s){
  int currentLine = 0;
  string expr;
  while(getline(file,expr)){
    currentLine++;
    for(int i=0; i<expr.length(); i++){
      if (expr[i]== '(' || expr[i]=='['|| expr[i]=='{'){
        s.push(expr[i]);
        continue;
      }
      else if (expr[i] == ')' || expr[i]== ']' || expr[i]=='}'){
        if (s.isEmpty()){ //nothing to match with
          cout << "On line " << currentLine << " an extra" <<expr[i]<<" was found" << endl;
          return false;
        }
        if (s.peek() == '('){
          if(expr[i] != ')'){
            cout<< "On line" << currentLine<<": " << expr[i] << " is expected" << s.peek() << endl;
            return false; //wrong type
          }
        }
        if (s.peek() == '['){
          if(expr[i] != ']'){
            cout<< "On line" << currentLine<<": " << expr[i] << " is expected" << s.peek() << endl;
            return false; //wrong type
          }
        }
        if (s.peek() == '{'){
          if(expr[i] != '}'){
            cout<< "On line" << currentLine<<": " << expr[i] << " is expected" << s.peek() << endl;
            return false; //wrong type
          }
        }
        s.pop();
      }
    if (s.isEmpty()){
      cout << "";
      return true; //every symbol matched
    }
    else {
      return false; // some symbols never matched
    }

    }
    bool endVal = s.isEmpty();
    while(!s.isEmpty()){
      cout<< "Match not found" << s.pop() << endl;
    }
    return endVal;

  }

  }
