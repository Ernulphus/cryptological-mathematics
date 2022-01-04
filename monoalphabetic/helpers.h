#include <string>

using std::string;

int inverse(int n, int modulus);
int gcd(int n, int m);
char multiply(char c, int offset);
void cleanMessage(string &message);
char shift(char c, int offset);

int inverse(int n, int modulus)
{
  for (int i = modulus; i > 0; i--)
  {
    if ((n*i) % modulus == 1)
      return i;
  }
  return -1;
}

int gcd(int n, int m)
{
  for (int i = (n < m ? n : m); i > 0; i--)
  {
    if ((n % i == 0) && (m % i == 0))
      return i;
  }
  return 0;
}

char multiply(char c, int offset)
{
  char s = ((c - 96) * offset) % 26;
  if (s == 0) s += 26;
  return s + 96;
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
  char s = ((c - 97) + offset) % 26;
  if (s < 0)
    s = 26 + s;
  return s + 97;
}