#include <iostream>

template<typename T>
T min(T a, T b)
{
  return a < b ? a : b;
}

int main()
{
  std::cout << min(3, 4) << std::endl;
  std::cout << min("bc", "zz") << std::endl;
  return 0;
}
