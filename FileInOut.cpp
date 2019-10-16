#include <fstream>
#include <iostream>
#include "FileInOut.h"

using namespace std;

FileInOut::FileInOut(){ //defalt constructor

}
FileInOut::~FileInOut(){ //destructor

}

void FileInOut::openFile(string path){ //open file with path
  in.open(path);
  if(!in){
    cout << "File not found.\n" << endl;
    exit(EXIT_FAILURE); //will exit if failure
  }
}
void FileInOut::closeFile(){ //closes the ifstream file
  in.close();
}
string FileInOut::readLine(){
  string line;
  getline(in,line);
  return line;
}

void FileInOut::openOutFile(string path){ //opens ofstream file using path
  out.open(path);
}

void FileInOut::closeOutFile(){
  out.close();
}

void FileInOut::writeLine(string s){
  out << s << endl;
}

void FileInOut::write(string s){
  out << s;
}
