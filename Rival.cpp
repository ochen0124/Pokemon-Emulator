#include "Rival.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

Rival::Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc): GameObject('R', id, in_loc)
{
  this->name = "Pokemon";
  this->speed = 5.0;
  health = 20;
  physical_damage = 5;
  magical_damage = 4;
  defense = 15;
}

void TakeHit(int physical_damage, int magical_damage, int defense)
{
  while (Pokemon -> health > 0 && Rival -> health > 0)
  {
    if ((rand() % 2+1) == 1)
    {
      double damage = (100.0 - defense)/100 * physical_damage;
      this -> health =- damage;
    }
    else
    {
      double damage = (100.0 - defense)/100 * magical_damage;
      this -> health =- damage;
    }
  }
}

double get_phys_dmg()
{
  return physical_dmg;
}

double get_magic_dmg()
{
  return magical_dmg;
}

double get_defense()
{
  return defense;
}

double get_health()
{
  return health;
}

bool Update()
{
  if (Rival -> health <= 0)
  {
    state = FAINTED_RIVAL;
  }
  else
  {
    state = ALIVE_RIVAL
    return false;
  }
}

void ShowStatus()
{

}

bool IsAlive()
{
  if (Rival -> health > 0)
  {
    return true;
  }
}
