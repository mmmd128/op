#include <algorithm>
#include <iostream>
#include <vector>

#include "1.hpp"

int main()
{
  std::vector<int> v;

  vec_read(v, 4);
  std::sort(v.begin(), v.end(), std::less<int>());
  v.insert(v.begin() + 1, 0);
  vec_print(v);

  int sum = 0;
  for (int i = v.size() - 2; i >= 0; i--)
    sum += v[i];
  std::cout << sum << std::endl;
}
