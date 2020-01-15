#ifndef RIVAL_H
#define RIVAL_H
#include "GameObject.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include <string>
#include "BattleArena.h"

class Rival : public GameObject {

public:
  Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc);
  void TakeHit(int physical_damage, int magical_damage, int defense);
  double get_phys_dmg();
  double get_magic_dmg();
  double get_defense();
  double get_health();
  bool Update();
  void ShowStatus();
  bool IsAlive();

protected:
  double health;
  double physical_damage;
  double magical_damage;
  double defense;
  bool is_in_arena;
  BattleArena* current_arena;
};
#endif
