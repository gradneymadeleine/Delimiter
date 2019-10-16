#include <iostream>
#include "GenStack.h"


using namespace std;

class Syntax{
public:
  Syntax();
  ~Syntax();

  string expr;
  char x;



  bool areSyntaxMatch(ifstream& file, GenStack<char>& s);
};
