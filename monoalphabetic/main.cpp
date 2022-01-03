#include <iostream>
#include "additive.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
  // std::cout << shift('a',3) << std::endl;
  // std::string m = "This is a message!";
  // cleanMessage(m);
  // std::cout << m << std::endl;
  int key = 13;
  string c = additiveEncipher("I am reading an enthralling book", key);
  cout << c << endl;
  cout << additiveDecipher(c, key) << endl;



  return 0;
}