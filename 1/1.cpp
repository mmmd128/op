#include <iostream>
#include <iomanip>

int main()
{
  int c;
  std::cin >> c;
  std::cout << std::showbase << std::hex;

  std::cout << std::uppercase << c << std::endl;

  int a = 255;
  std::cout << "hex " << std::hex << a << std::endl;
  std::cout << "dec " << std::dec << a << std::endl;
  std::cout << "oct " << std::oct << a << std::endl;

  double pi = 3.141592;
  std::cout << "pi = " << std::scientific << std::uppercase;
  std::cout << std::setprecision(7) << std::setw(20) << std::setfill('0');
  std::cout << pi << std::endl;

  return 0;
}
