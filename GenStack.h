#include <iostream>

using namespace std;

template <class S>
class GenStack
{
public:
    GenStack();            //constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack();           //destructor

    void push(S d);
    S pop();
    S peek(); //AKA top()

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    char *myArray; //pointer / dinamic memory allocation
    char *temp;
};

//overloaded constructor
template <class S>
GenStack<S>::GenStack(){
  myArray= new S[100]; // array length 100
  size =100;
  top = -1; //top position in the stack
}

template <class S>
GenStack<S>::GenStack(int maxSize){
  myArray = new S[maxSize]; // array length maxzize
  size = maxSize;
  top = -1;
}

//destructor
template <class S>
GenStack<S>::~GenStack(){
  delete myArray;
}

//add to the stack
template <class S>
void GenStack<S>::push(S d){
  //check error/boundary
  if (isFull()){
    temp = new char [size]; //temp array
    for(int i = 0; i<size; ++i){
      temp[i] = myArray[1];
    }
    delete myArray;
    myArray = new char[size*2];
    size += 2;
    for(int i=0; i<size;++i){
      myArray[i] = temp[i]; //put elements back in
    }
    delete temp; //delete temportary array
  }
  myArray[++top] =d;
}

template <class S>
S GenStack<S>::pop(){
  if (isEmpty()){
    cout << "Stack is empty." << endl;
    exit(0);
  }
  //making sure it is not empty
  return myArray[top--];
}
