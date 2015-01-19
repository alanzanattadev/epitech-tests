//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j13
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Mon Jan 21 09:06:19 2013 louis brunner
// Last update Mon Jan 21 10:55:24 2013 louis brunner
//

#include "Buzz.h"
#include "Woody.h"
#include <iostream>

int	main()
{
  Toy	t(Toy::BASIC_TOY, "Batman", "batman.txt");
  Toy	a(Toy::ALIEN, "Alien", "alien.txt");
  Buzz	b("Lightyear");
  Woody	w("Cowboy");

  std::cout << t.getType() << "= ";
  t.speak("Not Everything. Not Yet");
  std::cout << a.getType() << "= " << std::endl;
  a.speak("A stranger.");
  a.speak("From the outside.");
  a.speak("Oooooooooooooooh.");
  std::cout << b.getType() << "= ";
  b.speak("To infinity, and beyond !");
  std::cout << w.getType() << "= ";
  w.speak("YY-AAAAH !");
  return 0;
}
