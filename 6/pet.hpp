enum PetType {
  Cat,
  Dog,
  Hamster,
  Snake,
  PetTypes,
};

class VirtualPet {
public:
  std::string name;
  PetType type;
  int hunger;
  int happiness;
  bool awake;

  VirtualPet(std::string name, PetType type) :
    name{name},
    type{type},
    hunger{3},
    happiness{0},
    awake{true}
  {}

  void eat();
  void play();
  void sleep();
  bool asleep();
};

class Owner {
  static std::mt19937& gen();
public:
  std::string name;
  std::vector<VirtualPet> pets;
  size_t actions;

  Owner(std::string name, size_t actions) : name{name}, actions{actions} {}
  Owner(const Owner& owner) :
    name{owner.name}, pets{owner.pets}, actions{owner.actions}
  {}

  void adopt(std::string name, PetType type);
  void interact();
};
