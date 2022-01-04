using std::string;

string multiplicativeEncipher(string message, int key);
string multiplicativeEncipher(string ciphertext, int key);

string multiplicativeEncipher(string message, int key)
{
  if (gcd(key, 26) != 1)
    return "Cannot encipher; invalid key";

  cleanMessage(message);
  string ciphertext = "";
  for (int i = 0; i < message.length(); i++)
  {
    ciphertext += multiply(message[i], key);
    if ((i+1) % 3 == 0)
    ciphertext += " ";
  }
  return ciphertext;
}

string multiplicativeDecipher(string ciphertext, int key)
{
  int invkey = inverse(key, 26);
  std::cout << "inverse of " << key << " is " << invkey << std::endl;
  cleanMessage(ciphertext);
  string plaintext = "";
  for (int i = 0; i < ciphertext.length(); i++)
    plaintext += multiply(ciphertext[i], invkey);

  return plaintext;
}