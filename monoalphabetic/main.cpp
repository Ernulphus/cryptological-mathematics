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
  // string keyword = "mathematics";
  // char keyletter = 'f';
  // string message = "abcdefghijklmnopqrstuvwxyz";
  // cout << "Keyword cipher of message \"" << message << "\" with keyword " << keyword << " and keyletter " << keyletter << endl;
  // string ci = keywordEncipher(message, keyword, keyletter);
  // cout << ci << endl;
  // cout << keywordDecipher(ci, keyword, keyletter) << endl << endl;

  // Test additive
  int key = 13;
  string message = "Dear Mich, This letter utilizes a number of cipher techniques from the book you lent me period I am very excited to get to work enciphering it period I regret that I did not start earlier period It took time for me to really understand that math could be enjoyed outside of school period Not just in an academic way like watching numberphile videos but in a practical and active way period Cryptography is fun period I enjoy learning and implementing all these different walls people have erected to protect their messages and all the ways other people have tried to tear them down period If you are reading this you know that the first section was a Caesar cipher or what the book calls an additive monoalphabetic cipher period The next section will be enciphered using a certain type of special square period I will figure out a way to transmit the key to you securely period If I put it in this section of the letter then it would be too easy for an interceptor to decode it given that I have just drastically narrowed down possibilities for the next enciphering method period";
  // cout << "Additive cipher of message \"" << message << "\" with key " << key << endl;
  string c = additiveEncipher(message, key);
  cout << c << endl;
  cout << additiveDecipher(c, key) << endl << endl;

  // // Test multiplicative
  // key = 11;
  // message = "Let's talk about it together!";
  // cout << "Multiplicative cipher of message \"" << message << "\" with key " << key << endl;
  // c = multiplicativeEncipher(message, key);
  // cout << c << endl;
  // cout << multiplicativeDecipher(c, key) << endl << endl;

  // // Test affine
  // int keyM = 7;       // Multiplicative key
  // int keyA = 11; // Additive key
  // message = "Meet me at the usual place at eight o'clock";
  // cout << "Affine cipher of message \"" << message << "\" with mult. key " << keyM << " and add. key " << keyA << endl;
  // c = affineEncipher(message, keyA, keyM);
  // cout << c << endl;
  // cout << affineDecipher(c, keyA, keyM) << endl << endl;

  return 0;
}
/*
characters
a-97
b-98
...
z-122
*/