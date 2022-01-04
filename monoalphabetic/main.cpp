#include <iostream>
#include "helpers.h"
#include "additive.h"
#include "multiplicative.h"

using std::cout;
using std::endl;
using std::string;

// Assuming an alphabet of 26 letters (a-z)

int main()
{
  // Test helpers
  // std::cout << shift('a',3) << std::endl;
  // std::string m = "This is a message!";
  // cleanMessage(m);
  // std::cout << m << std::endl;

  // Test multiplicative
  int key = 3;
  string ci = multiplicativeEncipher("I love your sense of humor", key);
  cout << ci << endl;
  cout << multiplicativeDecipher(ci, key) << endl;

  // Test additive
  // int key = 13;
  // string c = additiveEncipher("I am reading an enthralling book", key);
  // cout << c << endl;
  // cout << additiveDecipher(c, key) << endl;


  return 0;
}
/*
characters
a-97
b-98
...
z-122
*/