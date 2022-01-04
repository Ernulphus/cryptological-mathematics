#include <iostream>
#include "helpers.h"
#include "additive.h"
#include "multiplicative.h"
#include "affine.h"
#include "keyword.h"

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
  // string k = "mathematics";
  // cleanKeyword(k);
  // cout << k << endl;

  // Test keyword
  string keyword = "mathematics";
  char keyletter = 'f';
  string message = "abcdefghijklmnopqrstuvwxyz";
  cout << "Keyword cipher of message \"" << message << "\" with keyword " << keyword << " and keyletter " << keyletter << endl;
  string ci = keywordEncipher(message, keyword, keyletter);
  cout << ci << endl;
  cout << keywordDecipher(ci, keyword, keyletter) << endl << endl;

  // Test additive
  int key = 13;
  message = "I am reading an enthralling book";
  cout << "Additive cipher of message \"" << message << "\" with key " << key << endl;
  string c = additiveEncipher(message, key);
  cout << c << endl;
  cout << additiveDecipher(c, key) << endl << endl;

  // Test multiplicative
  key = 11;
  message = "Let's talk about it together!";
  cout << "Multiplicative cipher of message \"" << message << "\" with key " << key << endl;
  c = multiplicativeEncipher(message, key);
  cout << c << endl;
  cout << multiplicativeDecipher(c, key) << endl << endl;

  // Test affine
  int keyM = 7;       // Multiplicative key
  int keyA = 11; // Additive key
  message = "Meet me at the usual place at eight o'clock";
  cout << "Affine cipher of message \"" << message << "\" with mult. key " << keyM << " and add. key " << keyA << endl;
  c = affineEncipher(message, keyA, keyM);
  cout << c << endl;
  cout << affineDecipher(c, keyA, keyM) << endl << endl;

  return 0;
}
/*
characters
a-97
b-98
...
z-122
*/