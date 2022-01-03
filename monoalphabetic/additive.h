/*
characters
a-97
b-98
...
z-122
*/
using std::string;

// Assuming an alphabet of 26 letters (a-z)

string additiveEncipher(string message, int key);
string additiveDecipher(string ciphertext, int key);
void cleanMessage(string &message);
char shift(char c, int offset);

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
  string plaintext = "";
  return plaintext;
}

void cleanMessage(string &message)
{
  auto x = message.begin();
  while (x !=  message.end())
  {
    if (*x >= 65 && *x <= 90)
      *x += 32;
    if (*x < 97 || *x > 122)
      message.erase(x);
    if (x == message.end())
      break;
    x++;
  }
  return;
}

char shift(char c, int offset)
{
  return (((c - 97) + offset) % 26) + 97;
}