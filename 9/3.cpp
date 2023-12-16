#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>

bool cmp(char a, char b)
{
  return std::tolower(a) < std::tolower(b);
}

template<typename T>
void sort(std::vector<T>& v)
{
  std::sort(v.begin(), v.end());
}

void sort(std::vector<char>& v)
{
  std::sort(v.begin(), v.end(), &cmp);
}

int main()
{
  std::vector<int> v = { 3, 8, 1, 5 };
  std::vector<char> cv = { 'a', 'B', 'c', 'Q', 'e', 'f', 'q' };

  sort(v);
  sort(cv);
  for (auto i : v)
    std::cout << i << std::endl;
  for (auto i : cv)
    std::cout << i << std::endl;

  return 0;
}
