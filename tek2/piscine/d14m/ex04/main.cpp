//
// main.cpp for piscine in /home/lachka_s/dev
//
// Made by sacha lachkar
// Login   <lachka_s@epitech.net>
//
// Started on  Tue Jan 22 15:23:22 2013 sacha lachkar
// Last update Tue Jan 22 15:23:23 2013 sacha lachkar
//

#include "LittleHand.h"
#include "Coconut.h"
#include "Lemon.h"
#include <iostream>

int	main()
{
  Lemon		l;
  Coconut	c;

  std::cout << l.getVitamins() << std::endl;
  LittleHand::injectVitamin(l, 42);
  std::cout << l.getVitamins() << std::endl;

  std::cout << c.getVitamins() << std::endl;
  LittleHand::injectVitamin(c, 2);
  std::cout << c.getVitamins() << std::endl;
  return 0;
}
