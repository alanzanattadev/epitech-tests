//
// ISpaceMarine.hh for piscine in /home/brunne_l/dev/rendu/piscine/tests
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 13:26:12 2013 louis brunner
// Last update Fri Jan 18 13:26:35 2013 louis brunner
//

#ifndef SPACEMARINE_HH_
# define SPACEMARINE_HH_

class ISpaceMarine
{
public:
  virtual ~ISpaceMarine() {}
  virtual ISpaceMarine* clone() const = 0;
  virtual void battleCry() const = 0;
  virtual void rangedAttack() const = 0;
  virtual void meleeAttack() const = 0;
};

#endif /* !SPACEMARINE_HH_ */
