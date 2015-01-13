//
// Federation.hh for piscine in /home/brunne_l/dev/rendu/piscine/piscine_cpp_d07m-2016-brunne_l/ex00
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 09:27:29 2013 louis brunner
// Last update Tue Jan 15 13:28:42 2013 louis brunner
//

#ifndef FEDERATION_HH_
# define FEDERATION_HH_

# include <string>
# include "Destination.hh"
# include "Warpsystem.hh"

namespace Borg
{
  class Ship;
};

namespace Federation
{
  namespace Starfleet
  {
    class Captain
    {
      std::string	_name;
      int		_age;

    public:
      Captain(std::string);
      ~Captain();

      std::string	getName();
      int		getAge();
      void		setAge(int);
    };

    class Ensign
    {
      std::string	_name;

    public:
      explicit	Ensign(std::string);
      ~Ensign();
    };

    class Ship
    {
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_core;
      Captain		*_captain;
      Destination	_location;
      Destination	_home;
      int		_shield;
      int		_photonTorpedo;

    public:
      Ship();
      Ship(int, int, std::string, short, int);
      ~Ship();

      void	setupCore(WarpSystem::Core *);
      void	checkCore();
      void	promote(Captain *);
      bool	move(int warp, Destination d);
      bool	move(int warp);
      bool	move(Destination d);
      bool	move();
      int	getShield();
      void	setShield(int);
      int	getTorpedo();
      void	setTorpedo(int);
      void	fire(Borg::Ship *);
      void	fire(int, Borg::Ship *);
    };
  };

  class Ship
  {
    int			_length;
    int			_width;
    std::string		_name;
    short		_maxWarp;
    WarpSystem::Core	*_core;
    Destination		_location;
    Destination		_home;

  public:
    Ship(int length, int width, std::string name);
    ~Ship();

    void		setupCore(WarpSystem::Core *);
    void		checkCore();
    bool		move(int warp, Destination d);
    bool		move(int warp);
    bool		move(Destination d);
    bool		move();
    WarpSystem::Core	*getCore();
  };
};

#endif /* !FEDERATION_HH_ */
