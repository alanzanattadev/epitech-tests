//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07m
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 12:53:43 2013 louis brunner
// Last update Tue Jan 15 14:27:56 2013 louis brunner
//

#include "Federation.hh"
#include "Borg.hh"
#include <iostream>

void	test(int valid, int toTest)
{
  std::cout << valid << " == " << toTest << ": ";
  if (valid == toTest)
    std::cout << "OK";
  else
    std::cout << "BAD";
  std::cout << std::endl;
}


void	test(void *valid, void *toTest)
{
  if (valid == toTest)
    std::cout << "Matching addresses: OK";
  else
    std::cout << "Matching addresses: BAD";
  std::cout << std::endl;
}

int	main()
{
  Federation::Starfleet::Ship	Entreprise;
  Federation::Starfleet::Ship	Spoutnik(50, 50, "Spoutnik", 9, 50);
  Federation::Ship		Falcon(20, 30, "Millenium Falcon");
  Borg::Ship			Twin1(15);
  Federation::Starfleet::Captain	Kirk("Kirk Hammet");
  Borg::Ship			Twin2(15, 5);
  WarpSystem::QuantumReactor	Q;
  WarpSystem::Core		C(&Q);

  Falcon.setupCore(&C);

  test(100, Entreprise.getShield());
  Entreprise.setShield(150);
  test(150, Entreprise.getShield());

  test(50, Spoutnik.getTorpedo());
  Spoutnik.setTorpedo(200);
  test(200, Spoutnik.getTorpedo());

  Entreprise.promote(&Kirk);

  test(15, Twin1.getWeaponFrequency());
  Twin1.setWeaponFrequency(20);
  test(20, Twin1.getWeaponFrequency());

  test(100, Twin2.getShield());
  Twin2.setShield(20);
  test(20, Twin2.getShield());

  test(3, Twin1.getRepair());
  Twin1.setRepair(6);
  test(6, Twin1.getRepair());

  test(&C, Falcon.getCore());

  Falcon.checkCore();
  Twin1.fire(&Falcon);
  Falcon.checkCore();

  test(150, Entreprise.getShield());
  Twin1.fire(&Entreprise);
  test(130, Entreprise.getShield());

  test(20, Twin2.getShield());
  Spoutnik.fire(&Twin2);
  Entreprise.fire(19, &Twin2);
  test(-980, Twin2.getShield());

  test(5, Twin2.getRepair());
  Twin2.repair();
  test(100, Twin2.getShield());
  test(4, Twin2.getRepair());
  Twin2.repair();
  test(3, Twin2.getRepair());
  Twin2.repair();
  test(2, Twin2.getRepair());
  Twin2.repair();
  test(1, Twin2.getRepair());
  Twin2.repair();
  test(0, Twin2.getRepair());

  test(100, Twin2.getShield());
  Entreprise.fire(2, &Twin2);
  test(100, Twin2.getShield());
  Entreprise.fire(1, &Twin2);
  test(50, Twin2.getShield());
  Entreprise.fire(1, &Twin2);
  test(50, Twin2.getShield());
  test(0, Twin2.getRepair());
  Twin2.repair();
  test(0, Twin2.getRepair());
  test(50, Twin2.getShield());

  return (0);
}
