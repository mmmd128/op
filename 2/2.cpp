#include <iostream>

int& ref(int d[], int n)
{
  return d[n];
}

int main()
{
  int n[] = { 3, 2, 1, 5, 6, 51, 24 };

  ref(n, 4)++;
  std::cout << n[4] << std::endl;
  return 0;
}
