#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void revsort()
{
  std::string s;
  std::vector<std::string> v;

  while (std::getline(std::cin, s)) {
    std::reverse(s.begin(), s.end());
    v.push_back(s);
  }

  std::sort(v.begin(), v.end(), std::less<std::string>());
  for (std::string s : v)
    std::cout << s << std::endl;
}

int main()
{
  revsort();
  return 0;
}
