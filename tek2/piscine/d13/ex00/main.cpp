//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j13
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Mon Jan 21 09:06:19 2013 louis brunner
// Last update Mon Jan 21 09:49:19 2013 louis brunner
//

#include "Toy.h"
#include <iostream>

std::string getToyTypeStr(Toy::ToyType type) {
  switch(type) {
    case Toy::BASIC_TOY:
      return "basic toy";
    case Toy::ALIEN:
      return "alien toy";
    default:
      return "broken toy";
  }
}

void showToy(const Toy& toy) {
  std::cout << "The toy named \"" << toy.getName() << "\" is of type \"" << getToyTypeStr(toy.getType()) << "\" and looks like this:" << std::endl
            << toy.getAscii() << std::endl;
}

int	main()
{
  Toy alien(Toy::ALIEN, "Alien plushy", "/tmp/epitech-tests/ex00/alien.txt");
  showToy(alien);

  Toy basic;
  showToy(basic);

  Toy alienClone(alien);
  alienClone.setName(alienClone.getName() + " clone");
  showToy(alienClone);

  alien.setName("Mutated alien plushy");
  alien.setAscii("/tmp/epitech-tests/ex00/xenomorph.txt");
  showToy(alien);

  Toy missingNo((Toy::ToyType) 424242, "MISSINGNO", "INVALID_FILE ");
  showToy(missingNo);
}
