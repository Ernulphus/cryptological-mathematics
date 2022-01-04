using std::string;

string keywordEncipher(string message, string keyword, char keyletter);
string keywordDecipher(string ciphertext, string keyword, char keyletter);

string keywordEncipher(string message, string keyword, char keyletter)
{
  cleanKeyword(keyword);
  cleanMessage(message);
  string ciphertext= "";
  string keystring = createKeystring(keyword, keyletter);
  
  for (char c : message)
  {
    ciphertext += keystring[c - 97];
  }

  return ciphertext;
}