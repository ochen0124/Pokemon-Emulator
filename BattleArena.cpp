#include "BattleArena.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

BattleArena::BattleArena() : Building('A')
{
  pokemon_count = 0;
  num_rivals = 3;
  num_rivals_remaining = num_rivals;
  dollar_cost_per_fight = 4;
  stamina_cost_per_fight = 3;
  state = RIVALS_AVAILABLE;
  cout << "BattleArena default constructed" << endl;
}

BattleArena( unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int
in_Id, Point2D in_loc): Building('A', in_id, point2d)
{
  id_num = in_id;
  location = in_loc;
  pokemon_count = 0;
  num_rivals = 3;
  num_rivals_remaining = num_rivals;
  dollar_cost_per_fight = 4;
  stamina_cost_per_fight = 3;
  state = RIVALS_AVAILABLE;
  cout << "BattleArena default constructed" << endl;
}

unsigned int GetNumRivalsRemaining()
{
  return num_rivals_remaining;
}

bool HasEnoughRivals()
{
  if (BattleArena -> num_rivals > 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

double GetDollarCost()
{
  return dollar_cost_per_fight;
}

unsigned int GetStaminaCost()
{
  return stamina_cost_per_fight;
}

bool IsAbleToFight(double budget, unsigned int stamina)
{
  if (Pokemon -> budget >= dollar_cost_per_fight && Pokemon -> stamina >= stamina_cost_per_fight)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Update()
{
  if (BattleArena -> num_rivals_remaining == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool IsBeaten()
{
  if (num_rivals_remaining == 0)
  {
    return true;
  }
}

void ShowStatus()
{
  Building::ShowStatus();
}
