//
// Borg.cpp for piscine in /home/brunne_l/dev/rendu/piscine/piscine_cpp_d07m-2016-brunne_l/ex01
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 10:11:52 2013 louis brunner
// Last update Tue Jan 15 13:46:49 2013 louis brunner
//

#include <iostream>
#include "Borg.hh"
#include "Federation.hh"

Borg::Ship::Ship(int wF, short repair)
{
  _side = 300;
  _maxWarp = 9;
  _core = NULL;
  _home = UNICOMPLEX;
  _location = _home;
  _shield = 100;
  _weaponFrequency = wF;
  _repair = repair;
  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally."
	    << std::endl
	    << "Your biological characteristics and technologies will be assimilated." << std::endl
	    << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void	Borg::Ship::setupCore(WarpSystem::Core *reactor)
{
  _core = reactor;
}

void	Borg::Ship::checkCore()
{
  if (_core != NULL && _core->checkReactor() != NULL)
    {
      if (_core->checkReactor()->isStable())
	std::cout << "Everything is in order." << std::endl;
      else
	std::cout << "Critical failure imminent." << std::endl;
    }
}

bool	Borg::Ship::move(int warp, Destination d)
{
  if (warp <= _maxWarp)
    return (move(d));
  return (false);
}

bool	Borg::Ship::move(int warp)
{
  return move(warp, _home);
}

bool	Borg::Ship::move(Destination d)
{
  if (d != _location)
    if (_core != NULL && _core->checkReactor() != NULL && _core->checkReactor()->isStable())
      {
	_location = d;
	return (true);
      }
  return (false);
}

bool	Borg::Ship::move()
{
  return (move(_home));
}

int	Borg::Ship::getShield()
{
  return (_shield);
}

void	Borg::Ship::setShield(int shield)
{
  _shield = shield;
}

int	Borg::Ship::getWeaponFrequency()
{
  return (_weaponFrequency);
}

void	Borg::Ship::setWeaponFrequency(int wF)
{
  _weaponFrequency = wF;
}

short	Borg::Ship::getRepair()
{
  return (_repair);
}

void	Borg::Ship::setRepair(short r)
{
  _repair = r;
}

void	Borg::Ship::fire(Federation::Starfleet::Ship *foe)
{
  if (foe == NULL)
    return;
  foe->setShield(foe->getShield() - _weaponFrequency);
  std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
}

void			Borg::Ship::fire(Federation::Ship *foe)
{
  WarpSystem::Core	*core;

  if (foe == NULL)
    return;
  core = foe->getCore();
  if (core != NULL && core->checkReactor() != NULL)
    {
      core->checkReactor()->setStability(false);
      std::cout << "Firing on target with " << _weaponFrequency << "GW frequency." << std::endl;
    }
}

void	Borg::Ship::repair()
{
  if (_repair > 0)
    {
      _shield = 100;
      _repair--;
      std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    }
  else
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
}
