#include "ISpaceMarine.hh"
#include "TacticalMarine.hh"
#include "AssaultTerminator.hh"
#include "ISquad.hh"
#include "Squad.hh"

int main()
{
  ISpaceMarine* bob = new TacticalMarine;
  ISpaceMarine* jim = new AssaultTerminator;

  ISquad* vlc = new Squad;
  vlc->push(bob);
  vlc->push(jim);
  for (int i = 0; i < vlc->getCount(); ++i)
    {
      ISpaceMarine* cur = vlc->getUnit(i);
      cur->battleCry();
      cur->rangedAttack();
      cur->meleeAttack();
    }
  delete vlc;

  return 0;
}
