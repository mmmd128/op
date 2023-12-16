#include <algorithm>
#include <iostream>
#include <vector>

template<class T>
class Set {
public:
  bool exists(T v) {
    return std::find(this->set.begin(), this->set.end(), v) != this->set.end();
  }

  void insert(T v) {
    if (!this->exists(v))
      set.push_back(v);
  }

  void remove(T v) {
    auto it = find(this->set.begin(), this->set.end(), v);
    
    if (it != this->set.end())
      this->set.erase(it);
  }
private:
  std::vector<T> set;
};

int main()
{
  Set<int> t;

  t.insert(3);
  t.insert(3);
  t.insert(3);
  t.insert(8);
  t.remove(3);

  std::cout << t.exists(3) << std::endl;
  std::cout << t.exists(8) << std::endl;

  return 0;
}
