//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j13
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Mon Jan 21 09:06:19 2013 louis brunner
// Last update Mon Jan 21 10:33:05 2013 louis brunner
//

#include "Buzz.h"
#include "Woody.h"
#include <iostream>

int	main()
{
  Buzz	b1("L'ECLAIR");
  Buzz	b2("THE DARK KNIGHT", "batman.txt");
  Woody	w1("LE COWBOY");
  Woody	w2("L'ALIEN", "alien.txt");

  std::cout << b1.getType() << std::endl;
  std::cout << b2.getType() << std::endl;
  std::cout << w1.getType() << std::endl;
  std::cout << w2.getType() << std::endl << std::endl;

  std::cout << "1: " << b1.getName() << std::endl << b1.getAscii() << std::endl;
  std::cout << "2: " << b2.getName() << std::endl << b2.getAscii() << std::endl;
  std::cout << "3: " << w1.getName() << std::endl << w1.getAscii() << std::endl;
  std::cout << "4: " << w2.getName() << std::endl << w2.getAscii() << std::endl;
  return 0;
}
