#include <iostream>
#include <string>

size_t strcount(std::string s, std::string t)
{
  size_t n;
  size_t last;
  
  n = last = 0;
  while ((last = s.find(t, last)) != std::string::npos)
    n += 1, last += 1;
  return n;
}

int main()
{
  std::string s = "a b cde ef cde 123 ab c";

  std::cout << strcount(s, "cde") << std::endl;
  std::cout << strcount(s, "ef") << std::endl;
  std::cout << strcount(s, "r") << std::endl;
  return 0;
}
