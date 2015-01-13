//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07m
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 12:53:43 2013 louis brunner
// Last update Tue Jan 15 15:28:07 2013 louis brunner
//

#include "BorgQueen.hh"
#include "Admiral.hh"
#include "Federation.hh"
#include "Borg.hh"
#include <iostream>

static void	test(bool real, bool toTest)
{
  std::cout << std::boolalpha;
  std::cout << real << " == " << std::boolalpha << toTest << " : ";
  if (real == toTest)
    std::cout << "OK";
  else
    std::cout << "BAD";
  std::cout << std::endl;
  std::cout << std::noboolalpha;
}

static void	test(int valid, int toTest)
{
  std::cout << valid << " == " << toTest << ": ";
  if (valid == toTest)
    std::cout << "OK";
  else
    std::cout << "BAD";
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
  WarpSystem::QuantumReactor	QR1;
  WarpSystem::Core		C1(&QR1);
  WarpSystem::QuantumReactor	QR2;
  WarpSystem::Core		C2(&QR2);
  Federation::Starfleet::Admiral	Picard("Cmd");
  Borg::BorgQueen		Queen;

  Falcon.setupCore(&C);
  Entreprise.promote(&Kirk);
  Entreprise.setupCore(&C1);
  Twin1.setupCore(&C2);

  Falcon.checkCore();
  Queen.destroy(&Twin1, &Falcon);
  Falcon.checkCore();

  test(100, Entreprise.getShield());
  Queen.fire(&Twin1, &Entreprise);
  test(85, Entreprise.getShield());

  test(100, Twin2.getShield());
  Picard.fire(&Spoutnik, &Twin2);
  Picard.fire(&Entreprise, &Twin2);
  test(0, Twin2.getShield());

  test(false, Picard.move(&Entreprise, EARTH));
  test(true, Picard.move(&Entreprise, ROMULUS));
  test(true, Picard.move(&Entreprise, EARTH));
  test(false, Picard.move(&Entreprise, EARTH));
  test(false, Picard.move(&Entreprise, EARTH));
  test(false, Picard.move(&Entreprise, EARTH));
  test(true, Picard.move(&Entreprise, ROMULUS));
  test(true, Picard.move(&Entreprise, EARTH));
  test(false, Picard.move(&Entreprise, EARTH));
  QR1.setStability(false);
  test(false, Picard.move(&Entreprise, BABEL));

  test(false, Queen.move(&Twin1, UNICOMPLEX));
  test(true, Queen.move(&Twin1, ROMULUS));
  test(true, Queen.move(&Twin1, UNICOMPLEX));
  test(false, Queen.move(&Twin1, UNICOMPLEX));
  test(false, Queen.move(&Twin1, UNICOMPLEX));
  test(false, Queen.move(&Twin1, UNICOMPLEX));
  test(true, Queen.move(&Twin1, ROMULUS));
  test(true, Queen.move(&Twin1, UNICOMPLEX));
  test(false, Queen.move(&Twin1, UNICOMPLEX));
  QR2.setStability(false);
  test(false, Queen.move(&Twin1, BABEL));

  return (0);
}
