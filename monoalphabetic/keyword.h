using std::string;

string keywordEncipher(string message, string keyword, char keyletter);
string keywordDecipher(string ciphertext, string keyword, char keyletter);

string keywordEncipher(string message, string keyword, char keyletter)
{
  cleanKeyword(keyword);
  cleanMessage(message);
  string ciphertext = "";
  string keystring = createKeystring(keyword, keyletter);

  int i = 1;
  for (char c : message)
  {
    ciphertext += keystring[c - 97];
    if (i % 3 == 0)
      ciphertext += " ";
    i++;
  }

  return ciphertext;
}

string keywordDecipher(string ciphertext, string keyword, char keyletter)
{
  cleanKeyword(keyword);
  cleanMessage(ciphertext);
  string plaintext = "";
  string keystring = createKeystring(keyword, keyletter);

  for (char c : ciphertext)
  { plaintext += keystring.find(c) + 97; }

  return plaintext;
}