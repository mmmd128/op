#include <iostream>

#include "7.hpp"

int Food::counter = 100;

void Food::eat()
{
  Food::counter--;
}

void Food::print()
{
  std::cout << this->counter << std::endl;
}

int& get_counter()
{
  return Food::counter;
}

bool VirtualPet::operator==(VirtualPet& v)
{
  return this->name == v.name && this->type == v.type
      && this->points == v.points && this->status == v.status
      && this->hunger == v.hunger;
}

bool VirtualPet::operator!=(VirtualPet& v)
{
  return !(*this == v);
}

void VirtualPet::operator=(VirtualPet& v)
{
  this->name = v.name;
  this->type = v.type;
  this->points = v.points;
  this->status = v.status;
  this->hunger = v.hunger;
}

void VirtualPet::operator++()
{
  Food::eat();
  this->hunger--;
}

bool VirtualPet::operator>(VirtualPet& v)
{
  return this->happiness > v.happiness;
}

bool VirtualPet::operator<(VirtualPet& v)
{
  return this->happiness < v.happiness;
}

bool VirtualPet::operator<=(VirtualPet& v)
{
  return this->happiness <= v.happiness;
}

bool VirtualPet::operator>=(VirtualPet& v)
{
  return this->happiness >= v.happiness;
}

std::ostream& operator<<(std::ostream& os, VirtualPet const& v)
{
  return os << "name: " << v.name << std::endl
         << "type: " << v.type << std::endl
         << "points: " << v.points << std::endl
         << "status: " << v.status << std::endl
         << "hunger: " << v.hunger << std::endl
         << "happiness: " << v.happiness;
}

int main()
{
  Food f;
  VirtualPet pet1("abc", 2, 2);
  VirtualPet pet2("abc", 2, 2);
  VirtualPet pet3("cde", 3, 5);

  f.print();
  f.eat();
  f.print();

  std::cout << get_counter() << std::endl;
  if (pet1 == pet2)
    std::cout << "1 == 2" << std::endl;
  if (pet1 != pet3)
    std::cout << "1 != 3" << std::endl;
  pet1 = pet3;
  if (pet1 != pet2)
    std::cout << "1 != 2" << std::endl;
  if (pet3 > pet1)
    std::cout << "3 > 1" << std::endl;
  if (pet2 >= pet1)
    std::cout << "2 <= 1" << std::endl;
  std::cout << pet1 << std::endl;
  std::cout << pet2 << std::endl;
  return 0;
}
