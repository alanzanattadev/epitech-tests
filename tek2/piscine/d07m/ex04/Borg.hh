//
// Borg.hh for piscine in /home/brunne_l/dev/rendu/piscine/piscine_cpp_d07m-2016-brunne_l/ex01
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 10:11:55 2013 louis brunner
// Last update Tue Jan 15 14:42:36 2013 louis brunner
//

#ifndef BORG_HH_
# define BORG_HH_

# include "Destination.hh"
# include "Warpsystem.hh"

namespace Federation
{
  namespace Starfleet
  {
    class Ship;
  };

  class Ship;
};

namespace Borg
{
  class Ship
  {
    int			_side;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_location;
    Destination		_home;
    int			_shield;
    int			_weaponFrequency;
    short		_repair;

  public:
    Ship(int, short = 3);
    ~Ship();

    void	setupCore(WarpSystem::Core *);
    void	checkCore();
    bool	move(int warp, Destination d);
    bool	move(int warp);
    bool	move(Destination d);
    bool	move();
    int		getShield();
    void	setShield(int);
    int		getWeaponFrequency();
    void	setWeaponFrequency(int);
    short	getRepair();
    void	setRepair(short);
    void	fire(Federation::Starfleet::Ship *);
    void	fire(Federation::Ship *);
    void	repair();
  };
};

#endif /* !BORG_HH_ */
