//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 16:13:55 2013 louis brunner
// Last update Sat Jan 17 04:15:47 2015 Maxime Fischer
//

#include <iostream>
#include "Ice.hh"
#include "Cure.hh"
#include "Character.hh"
#include "MateriaSource.hh"
#include "ICharacter.hh"

int main()
{
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* zaz = new Character("zaz");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  zaz->equip(tmp);
  tmp = src->createMateria("cure");
  zaz->equip(tmp);

  ICharacter* bob = new Character("bob");

  zaz->use(0, *bob);
  zaz->use(1, *bob);

  delete bob;
  delete zaz;
  delete src;

  return 0;
}
