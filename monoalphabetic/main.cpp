#include <iostream>
#include "additive.h"

int main()
{
  std::cout << shift('a',3) << std::endl;
  std::string m = "This is a message!";
  cleanMessage(m);
  std::cout << m << std::endl;

  return 0;
}