//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Fri Jan 18 10:33:47 2013 louis brunner
// Last update Fri Jan 18 11:52:11 2013 louis brunner
//

#include "Character.hh"
#include "PlasmaRifle.hh"
#include "PowerFist.hh"
#include "RadScorpion.hh"
#include "SuperMutant.hh"
#include <iostream>

int main()
{
  Character* zaz = new Character("zaz");

  std::cout << *zaz;

  AEnemy* b = new RadScorpion();

  std::cout << b->getType() << std::endl;

  AWeapon* pr = new PlasmaRifle();
  AWeapon* pf = new PowerFist();

  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->equip(pr);
  std::cout << *zaz;
  zaz->equip(pf);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->equip(pr);
  std::cout << *zaz;
  std::cout << b->getHP() << std::endl;
  zaz->attack(b);
  std::cout << *zaz;
  std::cout << b->getHP() << std::endl;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->recoverAP();
  std::cout << *zaz;
  zaz->recoverAP();
  std::cout << *zaz;
  zaz->recoverAP();
  std::cout << *zaz;

  b = new SuperMutant();

  std::cout << b->getType() << std::endl;

  std::cout << *zaz;
  zaz->equip(pr);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  std::cout << b->getHP() << std::endl;
  zaz->attack(b);
  std::cout << *zaz;
  std::cout << b->getHP() << std::endl;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;
  std::cout << b->getHP() << std::endl;
  zaz->recoverAP();
  std::cout << *zaz;
  zaz->equip(pf);
  std::cout << *zaz;
  zaz->attack(b);
  std::cout << *zaz;

  return 0;
}
