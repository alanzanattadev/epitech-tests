//
// Warpsystem.hh for piscine in /home/brunne_l/dev/rendu/piscine/piscine_cpp_d07m-2016-brunne_l/ex00
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 09:39:12 2013 louis brunner
// Last update Tue Jan 15 09:53:45 2013 louis brunner
//

#ifndef WARPSYSTEM_HH_
# define WARPSYSTEM_HH_

namespace WarpSystem
{
  class QuantumReactor
  {
    bool	_stability;

  public:
    QuantumReactor();
    ~QuantumReactor();

    bool	isStable();
    void	setStability(bool);
  };

  class Core
  {
    QuantumReactor	*_coreReactor;

  public:
    Core(QuantumReactor *);
    ~Core();

    QuantumReactor	*checkReactor();
  };
};

#endif /* !WARPSYSTEM_HH_ */
