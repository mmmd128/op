#include <string>
#include <stdexcept>

class Enemy {
public:
  std::string name;
  int health;
  int damage;

  Enemy(std::string name, int health, int damage) : name{name}, health{health}, damage{damage} {
    if (health < 0 || damage < 0)
      throw std::invalid_argument("health and damage must be positive");
  }

  virtual void attack() = 0;
  virtual void displayInfo() = 0;
};

class Boss : public Enemy {
public:
  std::string ammo;

  Boss(std::string name, int health, int damage, std::string ammo) : Enemy(name, health, damage), ammo{ammo} {
    if (ammo.size() == 0)
      throw std::invalid_argument("empty ammo string");
  }

  void attack();
  void displayInfo();
};

class Monster : public Enemy {
public:
  std::string abilities;

  Monster(std::string name, int health, int damage, std::string abilities) : Enemy(name, health, damage), abilities{abilities} {
    if (abilities.size() == 0)
      throw std::invalid_argument("empty abilities string");
  }

  void attack();
  void displayInfo();
};
