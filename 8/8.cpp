#include <iostream>
#include <stdexcept>
#include <vector>

#include "8.hpp"

void Boss::attack() {
  std::cout << this->name << " attacks with " << this->ammo << std::endl;
  std::cout << this->name << " deals " << this->damage << " damage points" << std::endl;
}

void Boss::displayInfo() {
  std::cout << "name: " << this->name << std::endl;
  std::cout << "hp: " << this->health << std::endl;
  std::cout << "dmg: " << this->damage << std::endl;
  std::cout << "ammo: " << this->ammo << std::endl;
}

void Monster::attack() {
  std::cout << this->name << " attacks with " << this->abilities << std::endl;
  std::cout << this->name << " deals " << this->damage << " damage points" << std::endl;
}

void Monster::displayInfo() {
  std::cout << "name: " << this->name << std::endl;
  std::cout << "hp: " << this->health << std::endl;
  std::cout << "dmg: " << this->damage << std::endl;
  std::cout << "abilities: " << this->abilities << std::endl;
}

int main()
{
  std::vector<Enemy*> enemies = {
    new Boss("abc", 50, 500, "20x"),
    new Monster("wcq", 20, 15, "Fire"),
    new Monster("qcc", 15, 3, "Ice")
  };

  for (auto e : enemies) {
    e->attack();
    e->displayInfo();
  }
}
