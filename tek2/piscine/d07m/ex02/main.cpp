//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07m
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 11:14:10 2013 louis brunner
// Last update Tue Jan 13 14:42:59 2015 Maxime Fischer
//

#include "Borg.hh"
#include "Federation.hh"

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

int	main(int ac, char **av)
{
  Federation::Starfleet::Ship	Sf(200, 150, "Enterprise", 4);
  Federation::Ship		Id(56, 23, "Mini Cooper");
  Borg::Ship			Bg;
  WarpSystem::QuantumReactor	QR1;
  WarpSystem::QuantumReactor	QR2;
  WarpSystem::QuantumReactor	QR3;
  WarpSystem::Core		C1(&QR1);
  WarpSystem::Core		C2(&QR2);
  WarpSystem::Core		C3(&QR3);
  Sf.setupCore(&C1);
  Id.setupCore(&C2);
  Bg.setupCore(&C3);

  if (ac > 1)
    {
      if (av[1][0] == '1')
	{
	  test(false, Sf.move());
	  test(true, Sf.move(ROMULUS));
	  test(true, Sf.move());
	  test(false, Sf.move(EARTH));
	  test(false, Sf.move(50));
	  test(false, Sf.move(3));
	  test(true, Sf.move(2, ROMULUS));
	  test(false, Sf.move(50, REMUS));
	  test(true, Sf.move(4));
	  test(false, Sf.move(2, EARTH));
	  QR1.setStability(false);
	  test(false, Sf.move(3, BABEL));
	}
      else if (av[1][0] == '2')
	{
	  test(false, Id.move());
	  test(true, Id.move(ROMULUS));
	  test(true, Id.move());
	  test(false, Id.move(VULCAN));
	  test(false, Id.move(50));
	  test(false, Id.move(1));
	  test(true, Id.move(1, ROMULUS));
	  test(false, Id.move(50, REMUS));
	  test(true, Id.move(1));
	  test(false, Id.move(1, VULCAN));
	  QR2.setStability(false);
	  test(false, Id.move(1, BABEL));
	}
      else if (av[1][0] == '3')
	{
	  test(false, Bg.move());
	  test(true, Bg.move(ROMULUS));
	  test(true, Bg.move());
	  test(false, Bg.move(UNICOMPLEX));
	  test(false, Bg.move(50));
	  test(false, Bg.move(7));
	  test(true, Bg.move(6, ROMULUS));
	  test(false, Bg.move(50, REMUS));
	  test(true, Bg.move(4));
	  test(false, Bg.move(5, UNICOMPLEX));
	  QR3.setStability(false);
	  test(false, Bg.move(8, BABEL));
	}
      else if (av[1][0] == '4')
	{
	  Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
	  Federation::Starfleet::Captain James("James T. Kirk");
	  //Federation::Starfleet::Captain James2 = "James T. Kirk";
	  Federation::Starfleet::Ensign Ensign("Pavel Chekov");
	  //Federation::Starfleet::Ensign Ensign2 = "Pavel Chekov";
	  WarpSystem::QuantumReactor QR;
	  WarpSystem::QuantumReactor QR2;
	  WarpSystem::Core core(&QR);
	  WarpSystem::Core core2(&QR2);

	  UssKreog.setupCore(&core);
	  UssKreog.checkCore();
	  UssKreog.promote(&James);
	  James.setAge(42);
	  std::cout << "Age: 42 = " << James.getAge() << std::endl;
	  QR.setStability(false);
	  UssKreog.checkCore();

	  Borg::Ship Cube;
	  Cube.setupCore(&core2);
	  Cube.checkCore();
	  QR2.setStability(false);
	  Cube.checkCore();
	}
    }
  return (0);
}
