#include <iostream>

#define LEN 10

void minmax(int* d, size_t n, int& min, int& max)
{
  min = max = d[0];
  for (size_t i = 0; i < n; i++) {
    if (d[i] > max)
      max = d[i];
    if (d[i] < min)
      min = d[i];
  }
}

int main()
{
  int* d = new int[LEN] { 8, 4, 13, 9, 5, 21, 33, 85, 154, 20 };
  int min, max;

  minmax(d, LEN, min, max);
  std::cout << min << std::endl;
  std::cout << max << std::endl;
  delete[] d;
  return 0;
}
