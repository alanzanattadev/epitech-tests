//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j13
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Mon Jan 21 09:06:19 2013 louis brunner
// Last update Mon Jan 21 19:20:51 2013 louis brunner
//

#include "Buzz.h"
#include "Woody.h"
#include <iostream>

int	main()
{
  Toy const	t(Toy::BASIC_TOY, "Batman", "batman.txt");
  Toy	a(Toy::ALIEN, "Alien", "alien.txt");
  Buzz	b("Lightyear");
  Woody	w("Cowboy");

  std::cout << t;
  std::cout << a;
  std::cout << b;
  std::cout << w;
  t << "NANANANANANANANANA BATMAN !!!!\n";
  b << "*PIOU PIOU*\n";
  std::cout << t;
  std::cout << a;
  std::cout << b;
  std::cout << w;
  return 0;
}
