#include <string>

using std::string;

int inverse(int n, int modulus);
int gcd(int n, int m);
char multiply(char c, int offset);
char shift(char c, int offset);
void cleanKeyword(string &keyword);
void cleanMessage(string &message);

// True iff x is in str
bool isIn(char x, string str)
{
  for (auto i = str.begin(); i != str.end(); i++)
    if (*i == x) return true;
  return false;
}

string createKeystring(string keyword, char keyletter)
{
  // Assign each letter to a cipher letter based on the keyword and letter
  char keystring [26] = { };
  int k = keyletter - 97;
  for (int i = 0; i < keyword.length(); i++)
  {
      if (k >= 26)
        k -= 26;
      keystring[k] = keyword[i];
      k++;
  }
  // At this point, the keyword has been written along the alphabet starting at the key letter
  char x = 'a';
  while (keystring[k] == 0)
  { // Write the remaining characters in order continuing from where k left off
    while (isIn(x, keyword))
      x += 1;
    keystring[k] = x;
    //std::cout << "x is " << x << " and k is " << k << std::endl;
    x += 1;
    k++;
    if (k >= 26)
      k -= 26;
  }

  string q = "";
  for (int c = 0; c < 26; c++)
  {
    q += keystring[c];
  }

  return q;
}

// Return the multiplicative inverse of n mod modulus
int inverse(int n, int modulus)
{
  for (int i = modulus; i > 0; i--)
  {
    if ((n*i) % modulus == 1)
      return i;
  }
  return -1;
}

// Return the greatest common denominator of n and m
int gcd(int n, int m)
{
  for (int i = (n < m ? n : m); i > 0; i--)
  {
    if ((n % i == 0) && (m % i == 0))
      return i;
  }
  return 0;
}

// Return c multiplied by the offset mod 26
char multiply(char c, int offset)
{
  char s = ((c - 96) * offset) % 26;
  if (s == 0) s += 26;
  return s + 96;
}

// Return the additive shift of one letter mod 26
char shift(char c, int offset)
{
  char s = ((c - 97) + offset) % 26;
  if (s < 0)
    s = 26 + s;
  return s + 97;
}

// Rewrite keyword eliminating any duplicate letters
void cleanKeyword(string &keyword)
{
  cleanMessage(keyword);
  for (auto x = keyword.begin() + 1; x != keyword.end(); x++)
  {
    for (auto i = keyword.begin(); i != x; i++)
    {
      if (*i == *x)
      {
        keyword.erase(x);
        i--;
        x--;
      }
    }
  }
  if (keyword.length() > 26)
    keyword = keyword.substr(0,26);
}

// Convert string to lowercase, remove spaces and punctuation
void cleanMessage(string &message)
{
  auto x = message.begin();
  while (x !=  message.end())
  {
    // std::cout << *x << " " << int(*x) <<  std::endl;
    if (*x >= 65 && *x <= 90)
      *x += 32;
    if (*x < 97 || *x > 122)
      {x = message.erase(x);
        x--;}
    if (x == message.end())
      break;
    x++;
  }
  return;
}

