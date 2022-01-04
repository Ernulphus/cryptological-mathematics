#include <string>

void cleanMessage(string &message);
char shift(char c, int offset);

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