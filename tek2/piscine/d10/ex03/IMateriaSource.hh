//
// IMateriaSource.hh for piscine in /home/brunne_l/dev/rendu/piscine/tests
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 16:19:41 2013 louis brunner
// Last update Fri Jan 18 16:19:42 2013 louis brunner
//

#ifndef IMATERIASOURCE_HH_
# define IMATERIASOURCE_HH_

class IMateriaSource
{
public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria*) = 0;
  virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /* !IMATERIASOURCE_HH_ */
