#include "helpers.h"
using std::string;

// Assuming an alphabet of 26 letters (a-z)

string additiveEncipher(string message, int key);
string additiveDecipher(string ciphertext, int key);


string additiveEncipher(string message, int key)
{
  cleanMessage(message);
  string ciphertext = "";
  for (int i = 0; i < message.length(); i++)
  {
    ciphertext += shift(message[i], key);
    if ((i+1) % 3 == 0)
    ciphertext += " ";
  }
  return ciphertext;
}

string additiveDecipher(string ciphertext, int key)
{
  cleanMessage(ciphertext);
  std::cout << ciphertext << "\n";
  string plaintext = "";
  for (int i = 0; i < ciphertext.length(); i++)
    plaintext += shift(ciphertext[i], -key);

  return plaintext;
}