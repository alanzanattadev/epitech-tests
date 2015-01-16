//
// ISquad.hh for piscine in /home/brunne_l/dev/rendu/piscine/tests
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 13:22:29 2013 louis brunner
// Last update Fri Jan 18 14:07:40 2013 louis brunner
//

#ifndef ISQUAD_HH_
# define ISQUAD_HH_

#include "ISpaceMarine.hh"

class ISquad
{
public:
  virtual ~ISquad() {}
  virtual int getCount() const = 0;
  virtual ISpaceMarine* getUnit(int) = 0;
  virtual int push(ISpaceMarine*) = 0;
};

#endif /* !ISQUAD_HH_ */
