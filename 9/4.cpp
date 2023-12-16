#include <iostream>
#include <cmath>

template<class T>
class point {
public:
  point(int x, int y) : x{x}, y{y} {}

  float operator-(point& p) {
    return std::sqrt(std::pow(p.x - this->x, 2) + std::pow(p.y - this->y, 2) * 1.0);
  }

  friend std::ostream& operator<<(std::ostream& os, point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
  }
private:
  int x;
  int y;
};

int main()
{
  point<int> p1(2, 3), p2(3, 4);
  std::cout << "udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << std::endl;
}
