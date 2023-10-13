#include <iostream>
#include <cstring>

struct Vec {
  int* n;
  int size;
  int phys;

  Vec(int init)
  {
    phys = init;
    size = 0;
    n = new int[phys];
  }

  void vector_delete()
  {
    delete[] n;
  }

  void vector_push_back(int i)
  {
    int* p;

    if (size == phys) {
      phys *= 2;
      p = new int[phys];
      std::memcpy(p, n, size * sizeof(int));
      this->vector_delete();
      n = p;
    }

    n[size++] = i;
  }

  void vector_pop_back()
  {
    size--;
  }

  int& vector_front()
  {
    return n[0];
  }

  int& vector_back()
  {
    return n[size == 0 ? 0 : size - 1];
  }

  int& vector_size()
  {
    return size;
  }
};

int main()
{
  Vec v(3);

  v.vector_push_back(30);
  v.vector_pop_back();
  v.vector_push_back(10);
  v.vector_push_back(168);
  v.vector_push_back(140);
  v.vector_push_back(20);
  v.vector_push_back(93);
  v.vector_push_back(43);
  v.vector_push_back(84);
  v.vector_push_back(84);
  v.vector_push_back(84);

  std::cout << "front: " << v.vector_front() << std::endl;
  std::cout << "back: " << v.vector_back() << std::endl;
  std::cout << "size: " << v.vector_size() << std::endl;
  std::cout << v.phys << std::endl;
  for (int i = 0; i < v.size; i++) {
    std::cout << v.n[i] << std::endl;
  }

  v.vector_delete();
  return 0;
}
