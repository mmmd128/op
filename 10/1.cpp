#include <algorithm>
#include <cctype>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

struct Point {
  int x, y;

  bool operator<(const Point& pt) {
    return x < pt.x && y < pt.y;
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& pt) {
    return os << pt.x << " " << pt.y;
  }
};

std::istream& operator>>(std::istream& is, Point& pt)
{
  return is >> pt.x >> pt.y;
}

std::string str_up(std::string s)
{
  for (char& c : s)
    c = std::toupper(c);
  return s;
}

static int sqr(int x)
{
  return x * x;
}

void locate(std::string w, std::string sub)
{
  std::ifstream file("words.txt");
  std::vector<std::string> v(std::istream_iterator<std::string>{file},
                             std::istream_iterator<std::string>{});
  std::vector<int> n;
  
  for (auto it = v.begin(); (it = std::find(it, v.end(), w)) != v.end(); it++)
    n.push_back(std::distance(v.begin(), it));
  int vn = 0;
  v.erase(std::remove_if(v.begin(), v.end(), [&sub, &vn, &n](std::string s) {
    auto it = std::find(n.begin(), n.end(), vn++);
    return it != n.end() && s.find(sub) != std::string::npos;
  }));
  std::transform(v.cbegin(), v.cend(), v.begin(), &str_up);
  std::copy(v.begin(), v.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"));
}

void points(int cx, int cy, int r)
{
  std::ifstream file("points.txt");
  std::vector<Point> v(std::istream_iterator<Point>{file},
                       std::istream_iterator<Point>{});

  std::sort(v.begin(), v.end());
  std::cout << std::count_if(v.begin(), v.end(), [&cx, &cy, &r](Point& pt) {
    return sqr(pt.x - cx) + sqr(pt.y - cy) < sqr(r);
  }) << std::endl;
  std::replace_if(v.begin(), v.end(), [&cx, &cy](Point& pt) {
    return pt.x == cx && pt.y == cy;
  }, Point{0, 0});
  std::reverse(v.begin(), v.end());
  std::copy(v.begin(), v.end(),
            std::ostream_iterator<Point>(std::cout, "\n"));
}

int main()
{
  locate("abc", "b");
  points(4, 4, 8);
  return 0;
}
