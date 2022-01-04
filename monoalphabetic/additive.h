using std::string;

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
  string plaintext = "";
  for (int i = 0; i < ciphertext.length(); i++)
    plaintext += shift(ciphertext[i], -key);

  return plaintext;
}