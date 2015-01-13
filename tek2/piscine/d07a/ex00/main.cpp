//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Tue Jan 15 18:04:49 2013 louis brunner
//

#include "Skat.h"
#include <iostream>

static int	error = 0;

static void	test(bool b)
{
  if (b)
    std::cout << "OK";
  else
    {
      std::cout << "BAD";
      error++;
    }
  std::cout << std::endl;
}

static void	test(int a, int b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

static void	test(std::string a, std::string b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

static int	res()
{
  std::cout << std::endl;
  if (error > 0)
    std::cout << "Fail." << std::endl;
  else
    std::cout << "OK !" << std::endl;
  return (error != 0);
}

static void	mustPrint(std::string p)
{
  std::cout << "Expected : " << p << std::endl;
  std::cout << "Your     : ";
}

int	main()
{
  Skat		bob;
  Skat		Gab("Gabriel Angelo", 2);
  Skat const	Wally("Wo-Lit");

  mustPrint("Soldier bob reporting 15 stimpaks remaining sir !"); bob.status();
  mustPrint("Soldier Gabriel Angelo reporting 2 stimpaks remaining sir !"); Gab.status();
  mustPrint("Soldier Wo-Lit reporting 15 stimpaks remaining sir !"); Wally.status();

  int& ref1 = bob.stimPaks();
  test(15, ref1);
  ref1 = 20;
  test(20, bob.stimPaks());

  test("Wo-Lit", Wally.name());

  test(2, Gab.stimPaks());
  test(20, bob.stimPaks());
  mustPrint("Don't be greedy"); Gab.shareStimPaks(50, bob.stimPaks());
  test(20, bob.stimPaks());
  test(2, Gab.stimPaks());
  mustPrint("Keep the change."); Gab.shareStimPaks(1, bob.stimPaks());
  test(21, bob.stimPaks());

  test(1, Gab.stimPaks());

  mustPrint("Hey boya, did you forget something ?"); Gab.addStimPaks(0);

  test(1, Gab.stimPaks());

  Gab.addStimPaks(1);

  test(2, Gab.stimPaks());

  mustPrint("Time to kick some ass and chew bubble gum."); Gab.useStimPaks();
  test(1, Gab.stimPaks());
  mustPrint("Time to kick some ass and chew bubble gum."); Gab.useStimPaks();
  test(0, Gab.stimPaks());
  mustPrint("Mediiiiiic"); Gab.useStimPaks();
  test(0, Gab.stimPaks());

  mustPrint("Soldier bob reporting 21 stimpaks remaining sir !"); bob.status();
  mustPrint("Soldier Gabriel Angelo reporting 0 stimpaks remaining sir !"); Gab.status();
  mustPrint("Soldier Wo-Lit reporting 15 stimpaks remaining sir !"); Wally.status();

  return (res());
}
