#include <iostream>
#include <vector>

#include "1.hpp"

bool find(std::vector<int>& v, int n)
{
  for (int i : v)
    if (i == n)
      return true;
  return false;
}

int main()
{
  std::vector<int> v1, v2, v3;
  
  vec_read(v1, 4);
  vec_read(v2, 4);

  for (int i : v1)
    if (!find(v2, i))
      v3.push_back(i);
  vec_print(v3);
}
