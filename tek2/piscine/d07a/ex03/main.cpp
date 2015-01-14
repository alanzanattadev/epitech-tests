//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Wed Jan 14 01:11:00 2015 matthieu kern
//

#include "Phaser.h"
#include "Sounds.h"
#include <iostream>
#include <cstdlib>

static int	error = 0;
static bool	quitOnFail = false;

/*
** Definition des sons ICI
*/
//LOOOOL
const std::string	Sounds::Regular = "PAN.";
const std::string	Sounds::Plasma = "BzzZZzZZZzZ...";
const std::string	Sounds::Rocket = "BOOOOOOM !";

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
    Phaser	p1;
    Phaser	p2(50);
    const Phaser	p3(3, Phaser::ROCKET);
    test(3, p3.getCurrentAmmos());

    Phaser p(5, Phaser::ROCKET);
    test(5, p.getCurrentAmmos());
    p.changeType(Phaser::REGULAR);
    p.changeType(Phaser::PLASMA);
    p.addAmmo(Phaser::REGULAR);
    p.fire();
    test(4, p.getCurrentAmmos());
    p.addAmmo(Phaser::REGULAR);
    test(5, p.getCurrentAmmos());
    std::cout << "Firing all ammunitions" << std::endl;
    while (p.getCurrentAmmos() > 0)
      p.fire();
    p.addAmmo(Phaser::REGULAR);
    p.addAmmo(Phaser::REGULAR);
    p.addAmmo(Phaser::REGULAR);
    test(3, p.getCurrentAmmos());
    p.fire();
    p.fire();
    test(1, p.getCurrentAmmos());
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    p.addAmmo(Phaser::ROCKET);
    test(5, p.getCurrentAmmos());
    std::cout << "Firing all ammunitions" << std::endl;
    while (p.getCurrentAmmos() > 0)
      p.fire();
    test(0, p.getCurrentAmmos());
    p.reload();
    test(5, p.getCurrentAmmos());
    std::cout << "Firing all ammunitions" << std::endl;
    while (p.getCurrentAmmos() > 0)
      p.fire();
    p.fire();
    test(0, p.getCurrentAmmos());
    p.reload();
    test(5, p.getCurrentAmmos());
    p.ejectClip();
    test(0, p.getCurrentAmmos());
    p.addAmmo(Phaser::REGULAR);
    p.addAmmo(Phaser::REGULAR);
    p.addAmmo(Phaser::REGULAR);
    test(3, p.getCurrentAmmos());
    std::cout << "Firing all ammunitions" << std::endl;
    while (p.getCurrentAmmos() > 0)
      p.fire();
    test(0, p.getCurrentAmmos());
    p.reload();
    test(5, p.getCurrentAmmos());
    std::cout << "Firing all ammunitions" << std::endl;
    while (p.getCurrentAmmos() > 0)
      p.fire();
    test(0, p.getCurrentAmmos());
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
      error++;
      if (quitOnFail)
	exit(res());
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
