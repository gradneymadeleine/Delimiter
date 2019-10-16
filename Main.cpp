#include <iostream>
#include "Syntax.h"
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  string filePath;
  if(argc !=2){
    cout<< "Incorrect number of arguments" <<endl;
    return 0;
  }
  else{
    filePath = argv[1];
  }

  GenStack<char> s(100);
  FileInOut inpout;
  Syntax check;

  while(true){
    inpout.openFile(filePath);
    bool checker = check.areSyntaxMatch(inpout.in, s);
    inpout.closeFile();

    if(checker){
      cout<< "No delimiter errors"  <<filePath<<endl;
    }
    cout << "Would you like to input another file? (y/n)"<< endl;
    string input;
    cin >> input;

    if(input == "Y" || input == "y"){
      cout<< "Please input file name" <<endl;
      cin >> filePath;
    }
    else{
      break;
    }
  }
}
