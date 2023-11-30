#include <string>

class Food {
public:
  static void eat();
  void print();
  friend int& get_counter();
private:
  static int counter;
};

class VirtualPet {
public:
  std::string name;
  int type = 1;
  int points = 3;
  int status = 0;
  int hunger = 5;
  int happiness = 10;

  VirtualPet(std::string name, int type, int happiness) :
    name{name},
    type{type},
    happiness{happiness} {}

  bool operator==(VirtualPet& v);
  bool operator!=(VirtualPet& v);
  void operator=(VirtualPet& v);
  void operator++();
  bool operator<(VirtualPet& v);
  bool operator>(VirtualPet& v);
  bool operator<=(VirtualPet& v);
  bool operator>=(VirtualPet& v);
};
