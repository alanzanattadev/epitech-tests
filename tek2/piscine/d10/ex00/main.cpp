//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j10/ex00
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 09:10:12 2013 louis brunner
// Last update Fri Jan 18 09:24:43 2013 louis brunner
//

#include "Sorcerer.hh"
#include "Peon.hh"

int	main()
{
  Sorcerer robert("Robert", "the Magnificent");

  Victim jim("Jimmy");
  Peon joe("Joe");

  std::cout << robert << jim << joe;

  robert.polymorph(jim);
  robert.polymorph(joe);

  return 0;
}
