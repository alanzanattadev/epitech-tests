//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Tue Jan 13 22:34:26 2015 matthieu kern
//

#include "KreogCom.h"
#include <iostream>
#include <cstdlib>

static int	error = 0;
static bool	quitOnFail = false;

void	mustPrint(std::string);
void	test(int, int);
void	test(void *, void *);
void	testd(void *, void *);
int	res();

int	main(int ac, char **av)
{
  (void) av;
  if (ac > 1)
    quitOnFail = true;

  {
    mustPrint("KreogCom 1 initialised"); KreogCom		first(1, 2, 0x000001);
    mustPrint("KreogCom 1048576 initialised"); KreogCom const	MCHammer(-4, -5, 0x100000);

    mustPrint("KreogCom 1048576 currently at -4 -5"); MCHammer.ping();
    mustPrint("KreogCom 1048576 currently at -4 -5"); MCHammer.locateSquad();

    mustPrint("KreogCom 1 currently at 1 2"); first.ping();
    test(NULL, first.getCom());

    mustPrint("KreogCom 1 currently at 1 2"); first.locateSquad();
    mustPrint("KreogCom 16 initialised"); first.addCom(4, 5, 0x000010);
    testd(NULL, first.getCom());
    mustPrint("KreogCom 16 currently at 4 5\nKreogCom 1 currently at 1 2"); first.locateSquad();
    mustPrint("KreogCom 256 initialised"); first.addCom(7, 6, 0x000100);
    mustPrint("KreogCom 256 currently at 7 6\nKreogCom 16 currently at 4 5\nKreogCom 1 currently at 1 2"); first.locateSquad();
    mustPrint("KreogCom 4096 initialised"); first.addCom(8, 19, 0x001000);
    mustPrint("KreogCom 4096 currently at 8 19\nKreogCom 256 currently at 7 6\nKreogCom 16 currently at 4 5\nKreogCom 1 currently at 1 2"); first.locateSquad();
    mustPrint("KreogCom 4096 shutting down"); first.removeCom();
    mustPrint("KreogCom 256 currently at 7 6\nKreogCom 16 currently at 4 5\nKreogCom 1 currently at 1 2"); first.locateSquad();
    mustPrint("KreogCom 256 shutting down"); first.removeCom();
    mustPrint("KreogCom 16 currently at 4 5\nKreogCom 1 currently at 1 2"); first.locateSquad();
    mustPrint("KreogCom 16 shutting down"); first.removeCom();
    mustPrint("KreogCom 1 currently at 1 2"); first.locateSquad();

    test(NULL, first.getCom());

    mustPrint("KreogCom 1048576 shutting down\nKreogCom 1 shutting down");
  }

  return (res());
}

int	res()
{
  std::cout << std::endl;
  if (error > 0)
    std::cout << "Fail." << std::endl;
  else
    std::cout << "OK !" << std::endl;
  return (error != 0);
}

void	test(bool b)
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

void	test(int a, int b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	test(std::string a, std::string b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	test(void *a, void *b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	testd(void *a, void *b)
{
  std::cout << "elem != " << a << ": ";
  test(a != b);
}

void	mustPrint(std::string p)
{
  std::cout << "Expected : " << p << std::endl;
  std::cout << "Your     : ";
}
