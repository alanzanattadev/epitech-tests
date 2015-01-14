//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Wed Jan 14 03:04:10 2015 matthieu kern
//

#include "Phaser.h"
#include "Sounds.h"
#include "Squad.h"
#include <iostream>
#include <cstdlib>

static int	error = 0;
static bool	quitOnFail = false;

/*
** Definition des sons ICI
*/
//LOOOOL

void	mustPrint(std::string);
void	test(int, int);
void	test(void *, void *);
void	testd(void *, void *);
int	res();

int	main(int ac, char **av)
{
  // (void) av;
  // if (ac > 1)
  //   quitOnFail = true;

  // {
    
  // }

  // return (res());

  (void)ac;
  (void)av;
  Squad s(0, 0, Phaser::REGULAR);

  s.fire();

  return 0;
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
  std::cout << a << " != " << b << ": ";
  test(a != b);
}

void	mustPrint(std::string p)
{
  std::cout << "Expected : " << p << std::endl;
  std::cout << "Your     : ";
}
