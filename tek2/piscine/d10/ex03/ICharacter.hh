//
// ICharacter.hh for piscine in /home/brunne_l/dev/rendu/piscine/tests
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 16:18:23 2013 louis brunner
// Last update Fri Jan 18 16:18:23 2013 louis brunner
//

#ifndef ICHARACTER_HH_
# define ICHARACTER_HH_

class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};

#endif /* !ICHARACTER_HH_ */
