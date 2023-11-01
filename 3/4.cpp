#include <iostream>
#include <vector>

#include "1.hpp"

void vec_remove(std::vector<int>& v, int n) 
{
  v.erase(v.begin() + n);
}

int main()
{
  std::vector<int> v;

  vec_read(v, 4);
  vec_remove(v, 2);
  vec_remove(v, 1);
  vec_print(v);
}
