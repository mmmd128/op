#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "pet.hpp"

void VirtualPet::eat()
{
  if (hunger == 0) {
    awake = false;
  } else {
    hunger--;
    happiness++;
  }
}

void VirtualPet::play()
{
  hunger++;
  happiness++;
}

bool VirtualPet::asleep()
{
  if (!awake) {
    hunger++;
    happiness++;
  }

  return !awake;
}

std::mt19937& Owner::gen()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  return gen;
}

void Owner::adopt(std::string name, PetType type)
{
  pets.push_back(VirtualPet(name, type));
}

void Owner::interact()
{
  static std::mt19937 g = gen();
  std::uniform_int_distribution<int> action_dist(0, 1);

  for (VirtualPet& pet : pets)
    for (size_t i = 0; i < actions; i++) {
      if (pet.asleep())
        continue;
      if (action_dist(g) == 0) 
        pet.eat();
      else
        pet.play();
    }
}

int main()
{
  std::vector<Owner> owners;
  size_t oc, pc, ac;
 
  std::cout << "no. of owners: " << std::endl;
  std::cin >> oc;
  std::cout << "no. of pets: " << std::endl;
  std::cin >> pc;
  std::cout << "actions: " << std::endl;
  std::cin >> ac;

  while (oc--) {
    std::string name;
    std::cout << "owner name: " << std::endl;
    std::cin >> name;

    Owner owner(name, ac);
    for (size_t i = 0; i < pc; i++) {
      std::string name;
      int type;

      std::cout << "name: " << std::endl;
      std::cin >> name;
      std::cout << "type (cat, dog, hamster, snake) (0-3): " << std::endl;
      std::cin >> type;

      if (type > PetTypes)
        return 0;
      owner.adopt(name, (PetType) type);
    }

    owner.interact();
    owners.push_back(owner);
  }

  Owner* h_owner = &owners[0];
  VirtualPet* h_pet = &h_owner->pets[0];
  int h = 0;

  for (Owner& owner : owners)
    for (VirtualPet& pet : owner.pets)
      if (pet.happiness > h) {
        h = pet.happiness;
        h_owner = &owner;
        h_pet = &pet;
      }

  std::string type;

  switch (h_pet->type) {
  case Cat:
    type = "cat";
    break;
  case Dog:
    type = "dog";
    break;
  case Hamster:
    type = "hamster";
    break;
  case Snake:
    type = "snake";
    break;
  default:
    break;
  }

  std::cout << "owner: " << h_owner->name << std::endl;
  std::cout << "pet: " << h_pet->name << std::endl;
  std::cout << "type: " << type << std::endl;
  std::cout << "happiness: " << h_pet->happiness << std::endl;
  return 0;
}
