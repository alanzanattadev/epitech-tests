//
// Federation.cpp for piscine in /home/brunne_l/dev/rendu/piscine/piscine_cpp_d07m-2016-brunne_l/ex00
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 09:27:32 2013 louis brunner
// Last update Tue Jan 15 14:24:10 2013 louis brunner
//

#include <iostream>
#include "Federation.hh"
#include "Borg.hh"

Federation::Starfleet::Captain::Captain(std::string name)
{
  _name = name;
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string	Federation::Starfleet::Captain::getName()
{
  return (_name);
}

int	Federation::Starfleet::Captain::getAge()
{
  return (_age);
}

void	Federation::Starfleet::Captain::setAge(int age)
{
  _age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  _name = name;
  std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

Federation::Starfleet::Ship::Ship()
{
  _length = 289;
  _width = 132;
  _name = "Entreprise";
  _maxWarp = 6;
  _core = NULL;
  _captain = NULL;
  _home = EARTH;
  _location = _home;
  _shield = 100;
  _photonTorpedo = 20;
  std::cout << "The ship USS " << _name << " has been finished. It is " << _length
	    << " m in length and " << _width << " m in width. It can go to Warp "
	    << _maxWarp << "! Weapons are set: " << _photonTorpedo
	    << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
  _length = length;
  _width = width;
  _name = name;
  _maxWarp = maxWarp;
  _core = NULL;
  _captain = NULL;
  _home = EARTH;
  _location = _home;
  _shield = 100;
  _photonTorpedo = torpedo;
  std::cout << "The ship USS " << _name << " has been finished. It is " << _length
	    << " m in length and " << _width << " m in width. It can go to Warp "
	    << _maxWarp << "! Weapons are set: " << _photonTorpedo
	    << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void	Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
  _core = core;
  std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void	Federation::Starfleet::Ship::checkCore()
{
  if (_core != NULL && _core->checkReactor() != NULL)
    std::cout << "USS " << _name << ": The core is "
	      << ((_core->checkReactor()->isStable()) ? ("stable") : ("unstable"))
	      << " at the time." << std::endl;
}

void	Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
  _captain = captain;
  if (_captain != NULL)
    std::cout << _captain->getName() << ": I'm glad to be the captain of the USS "
	      << _name << "." << std::endl;
}

bool	Federation::Starfleet::Ship::move(int warp, Destination d)
{
  if (warp <= _maxWarp)
    return (move(d));
  return (false);
}

bool	Federation::Starfleet::Ship::move(int warp)
{
  return move(warp, _home);
}

bool	Federation::Starfleet::Ship::move(Destination d)
{
  if (d != _location)
    if (_core != NULL && _core->checkReactor() != NULL && _core->checkReactor()->isStable())
      {
	_location = d;
	return (true);
      }
  return (false);
}

bool	Federation::Starfleet::Ship::move()
{
  return (move(_home));
}

int	Federation::Starfleet::Ship::getShield()
{
  return (_shield);
}

void	Federation::Starfleet::Ship::setShield(int shield)
{
  _shield = shield;
}

int	Federation::Starfleet::Ship::getTorpedo()
{
  return (_photonTorpedo);
}

void	Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
  _photonTorpedo = torpedo;
}

void	Federation::Starfleet::Ship::fire(Borg::Ship *foe)
{
  fire(1, foe);
}

void	Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *foe)
{
  if (foe == NULL)
    return;
  if (_photonTorpedo == 0)
    {
      if (_captain != NULL)
	std::cout << _name << ": No more torpedo to fire, "
		  << _captain->getName() << "!" << std::endl;
    }
  else if (torpedoes > _photonTorpedo)
    {
      if (_captain != NULL)
	std::cout << _name << ": No enough torpedoes to fire, "
		  <<  _captain->getName() << "!" << std::endl;
    }
  else
    {
      foe->setShield(foe->getShield() - (torpedoes * 50));
      _photonTorpedo -= torpedoes;
      std::cout << _name << ": Firing on target. "
		<< _photonTorpedo << " torpedoes remaining." << std::endl;
    }
}

Federation::Ship::Ship(int length, int width, std::string name)
{
  _length = length;
  _width = width;
  _name = name;
  _maxWarp = 1;
  _core = NULL;
  _home = VULCAN;
  _location = _home;
  std::cout << "The independant ship " << _name << " just finished its construction. It is "
	    << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void	Federation::Ship::setupCore(WarpSystem::Core *core)
{
  _core = core;
  std::cout << _name << ": The core is set." << std::endl;
}

void	Federation::Ship::checkCore()
{
  if (_core != NULL && _core->checkReactor() != NULL)
    std::cout << _name << ": The core is "
	      << ((_core->checkReactor()->isStable()) ? ("stable") : ("unstable"))
	      << " at the time." << std::endl;
}

bool	Federation::Ship::move(int warp, Destination d)
{
  if (warp <= _maxWarp)
    return (move(d));
  return (false);
}

bool	Federation::Ship::move(int warp)
{
  return move(warp, _home);
}

bool	Federation::Ship::move(Destination d)
{
  if (d != _location)
    if (_core != NULL && _core->checkReactor() != NULL && _core->checkReactor()->isStable())
      {
	_location = d;
	return (true);
      }
  return (false);
}

bool	Federation::Ship::move()
{
  return (move(_home));
}

WarpSystem::Core	*Federation::Ship::getCore()
{
  return (_core);
}
