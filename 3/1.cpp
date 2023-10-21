#include <iostream>
#include <vector>

#include "1.hpp"

void vec_read(std::vector<int>& v, int n)
{
  while (n--) {
    int i = 0;
    std::cin >> i;
    v.push_back(i);
  }
}

void vec_read(std::vector<int>& v, int a, int b)
{
  int i = 0;

  do {
    std::cin >> i;
    v.push_back(i);
  } while (i >= a && i <= b);

  v.pop_back();
}

void vec_print(std::vector<int>& v)
{
  for (int i : v)
    std::cout << i << std::endl;
}
