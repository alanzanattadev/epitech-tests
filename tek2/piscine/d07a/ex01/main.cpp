//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Tue Jan 15 19:38:06 2013 louis brunner
//

#include "KoalaBot.h"
#include "Parts.h"
#include <iostream>
#include <cstdlib>

static int	error = 0;
static bool	quitOnFail = false;

static int	res()
{
  std::cout << std::endl;
  if (error > 0)
    std::cout << "Fail." << std::endl;
  else
    std::cout << "OK !" << std::endl;
  return (error != 0);
}

static void	test(bool b)
{
  if (b)
    std::cout << "OK";
  else
    {
      std::cout << "BAD";
      if (quitOnFail)
	exit(res());
      else
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

static void	mustPrint(std::string p)
{
  std::cout << "Expected : " << p << std::endl;
  std::cout << "Your     : ";
}

int	main(int ac, char **av)
{
  (void) av;
  if (ac > 1)
    quitOnFail = true;

  Arms		a1;
  Arms		a2("Armstrong");
  Arms const	a3("Mark1-5", false);

  test(true, a1.isFunctionnal());
  test(true, a2.isFunctionnal());
  test(false, a3.isFunctionnal());

  test("A-01", a1.serial());
  test("Armstrong", a2.serial());
  test("Mark1-5", a3.serial());

  mustPrint("\t[Parts] Arms A-01 status : OK"); a1.informations();
  mustPrint("\t[Parts] Arms Armstrong status : OK"); a2.informations();
  mustPrint("\t[Parts] Arms Mark1-5 status : KO"); a3.informations();

  Legs		l1;
  Legs		l2("Strongleg");
  Legs		l3("Mark1-3", false);

  test(true, l1.isFunctionnal());
  test(true, l2.isFunctionnal());
  test(false, l3.isFunctionnal());

  test("L-01", l1.serial());
  test("Strongleg", l2.serial());
  test("Mark1-3", l3.serial());

  mustPrint("\t[Parts] Legs L-01 status : OK"); l1.informations();
  mustPrint("\t[Parts] Legs Strongleg status : OK"); l2.informations();
  mustPrint("\t[Parts] Legs Mark1-3 status : KO"); l3.informations();

  Head		h1;
  Head		h2("Header");
  Head		h3("Mark1-1", false);

  test(true, h1.isFunctionnal());
  test(true, h2.isFunctionnal());
  test(false, h3.isFunctionnal());

  test("H-01", h1.serial());
  test("Header", h2.serial());
  test("Mark1-1", h3.serial());

  mustPrint("\t[Parts] Head H-01 status : OK"); h1.informations();
  mustPrint("\t[Parts] Head Header status : OK"); h2.informations();
  mustPrint("\t[Parts] Head Mark1-1 status : KO"); h3.informations();

  KoalaBot	kb;
  KoalaBot	kb2("Terminator");

  kb.setParts(a1);
  kb.setParts(l1);
  kb.setParts(h1);

  test(true, kb.status());
  mustPrint("[KoalaBot] Bob-01\n\t[Parts] Arms A-01 status : OK\n\t[Parts] Legs L-01 status : OK\n\t[Parts] Head H-01 status : OK"); kb.informations();

  kb2.setParts(a2);
  kb2.setParts(l2);
  kb2.setParts(h2);

  test(true, kb2.status());
  mustPrint("[KoalaBot] Terminator\n\t[Parts] Arms Armstrong status : OK\n\t[Parts] Legs Strongleg status : OK\n\t[Parts] Head Header status : OK"); kb2.informations();

  kb2.setParts(l3);

  test(false, kb2.status());
  mustPrint("[KoalaBot] Terminator\n\t[Parts] Arms Armstrong status : OK\n\t[Parts] Legs Mark1-3 status : KO\n\t[Parts] Head Header status : OK"); kb2.informations();

  kb2.swapParts(a1);
  kb2.swapParts(l1);
  kb2.swapParts(h1);

  test(true, kb2.status());
  mustPrint("[KoalaBot] Terminator\n\t[Parts] Arms A-01 status : OK\n\t[Parts] Legs L-01 status : OK\n\t[Parts] Head H-01 status : OK"); kb2.informations();

  test(true, a1.isFunctionnal());
  test(false, l1.isFunctionnal());
  test(true, h1.isFunctionnal());

  test("Armstrong", a1.serial());
  test("Mark1-3", l1.serial());
  test("Header", h1.serial());

  mustPrint("\t[Parts] Arms Armstrong status : OK"); a1.informations();
  mustPrint("\t[Parts] Legs Mark1-3 status : KO"); l1.informations();
  mustPrint("\t[Parts] Head Header status : OK"); h1.informations();

  return (res());
}
