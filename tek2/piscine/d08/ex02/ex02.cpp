//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Wed Jan 16 16:59:23 2013 louis brunner
//

#include "droidmemory.hh"
#include "droid.hh"
#include <iostream>
#include <sstream>
#include <cstdlib>

#define CATCH(expr, print)	\
  redirectOutput();		\
  expr;				\
  mustPrint(print);

static int	nbErrors = 0;
static int	nbTests = 1;
static bool	quitOnFail = false;
static bool	paddingEnabled = true;

void	mustPrint(const std::string);
void	mustPrint(bool const, const std::string);
void	redirectOutput();
void	test(const bool, const bool);
void	test(const int, const int);
void	test(const std::string &, const std::string &);
void	test(const void *, const void *);
void	testd(const void *, const void *);
int	res();

int	main(int ac, char **av)
{
  (void) av;
  if (ac > 1)
    quitOnFail = true;
  if (ac > 2)
    paddingEnabled = false;

  {
    srandom(1337);

    DroidMemory const	d1;
    DroidMemory	d2;
    d2 += 120;
    DroidMemory		d3 = d1;
    DroidMemory		d4;

    test(true, d1 == d3);
    test(false, d1 == d2);
    test(true, d1 != d4);
    test(false, d1 != d3);

    d4 += 45;

    test(true, d3 >= d1);
    test(false, d1 >= d4);
    test(true, d1 >= 0);
    test(false, d3 >= 4534);

    test(true, d1 <= d3);
    test(false, d4 <= d1);
    test(true, d1 <= 4543);
    test(false, d2 <= 1);

    test(true, d2 > d3);
    test(false, d1 > d4);
    test(true, d4 > 43);
    test(false, d3 > 1);

    test(true, d1 < d2);
    test(false, d4 < d1);
    test(true, d1 < 4543);
    test(false, d2 < 1);

    Droid	dr1("D1");
    dr1.setEnergy(95);
    Droid const	dr2("D2");
    Droid	dr3(dr1);
    Droid	dr4("D4");
    dr4 = dr1;

    test(50, dr2.getEnergy());
    test(50, dr3.getEnergy());
    test(50, dr4.getEnergy());

    test(95, dr1.getEnergy());
    test(0, dr1.getBattleData()->getExp());
    test("Standing by", *dr1.getStatus());

    std::string const co("HELP ME");
    test(false, dr1(&co, 120));

    test(85, dr1.getEnergy());
    test(120, dr1.getBattleData()->getExp());
    test("HELP ME - Failed!", *dr1.getStatus());

    std::string order;
    order = "DESTROY THE ORCS";
    test(true, dr1(&order, 60));

    test(75, dr1.getEnergy());
    test(150, dr1.getBattleData()->getExp());
    test("DESTROY THE ORCS - Completed!", *dr1.getStatus());

    test(true, dr1(&order, 3));
    test(true, dr1(&order, 3));
    test(true, dr1(&order, 3));
    test(true, dr1(&order, 3));
    test(true, dr1(&order, 3));
    test(true, dr1(&order, 3));
    test(true, dr1(&order, 3));

    test(5, dr1.getEnergy());
    test(157, dr1.getBattleData()->getExp());
    test("DESTROY THE ORCS - Completed!", *dr1.getStatus());

    test(false, dr1(&order, 3));

    test(0, dr1.getEnergy());
    test(157, dr1.getBattleData()->getExp());
    test("Battery Low", *dr1.getStatus());
    dr1.setEnergy(10);
    test(10, dr1.getEnergy());

    test(false, dr1(&order, 3));

    test(0, dr1.getEnergy());
    test(157, dr1.getBattleData()->getExp());
    test("Battery Low", *dr1.getStatus());

    Droid d("rudolf");
    Droid d23("gaston");
    size_t DuraSell = 40;
    d << DuraSell;
    d.setStatus(new std::string("having some reset"));
    d23.setStatus(new std::string("having some reset"));
    if (d23 != d && !(d == d23))
      std::cout << "a droid is a droid, all its matter is what it’s doing" << std::endl;
    d(new std::string("take a coffee"), 20);
    std::cout << d << std::endl;
    while (d(new std::string("Patrol around"), 20))
      {
	if (!d(new std::string("Shoot some ennemies"), 50))
	  d(new std::string("Run Away"), 20);
	std::cout << d << std::endl;
      }
    std::cout << d << std::endl;
  }

  return (res());
}

static std::streambuf		*cout_old = NULL;
static std::stringstream	output;

static void	padding()
{
  if (paddingEnabled)
    std::cout << std::endl;
}

static void	printTest()
{
  std::cout << "Test " << nbTests++ << ":" << std::endl;
}

int	res()
{
  std::cout << std::endl;
  if (nbErrors > 0)
    std::cout << "Fail." << std::endl;
  else
    std::cout << "OK !" << std::endl;
  return (nbErrors != 0);
}

void	test(bool b)
{
  if (b)
    std::cout << "OK";
  else
    {
      std::cout << "BAD";
      nbErrors++;
    }
  std::cout << std::endl;
  padding();
  if (nbErrors > 0 && quitOnFail)
    exit(res());
}

void	test(bool const a, bool const b)
{
  printTest();
  std::cout << std::boolalpha << a << " == " << b << ": " << std::noboolalpha;
  test(a == b);
}

void	test(int const a, int const b)
{
  printTest();
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	test(std::string const & a, std::string const & b)
{
  printTest();
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	test(void const *a, void const *b)
{
  printTest();
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	testd(void const *a, void const *b)
{
  printTest();
  std::cout << a << " != " << b << ": ";
  test(a != b);
}

void	mustPrint(std::string const p)
{
  mustPrint(false, p);
}

void		mustPrint(bool const b, std::string const p)
{
  std::string	buffer;
  bool		noendl = false;

  if (cout_old == NULL)
    return;
  buffer = output.str();
  std::cout.rdbuf(cout_old);
  cout_old = NULL;
  noendl = ((!buffer.empty() && buffer.at(buffer.length() - 1) != '\n')
	    || (!p.empty() && p.at(p.length() - 1) != '\n')
	    || buffer.empty() || p.empty());

  std::cout << "Expected : ";
  if (b)
    std::cout << std::endl;
  std::cout << p;
  if (noendl)
    std::cout << std::endl;
  std::cout << "Your     : ";
  if (b)
    std::cout << std::endl;
  std::cout << buffer;
  if (noendl)
    std::cout << std::endl;
  std::cout << "Result   : ";
  test(p == buffer);
}

void	redirectOutput()
{
  printTest();
  output.str("");
  cout_old = std::cout.rdbuf(output.rdbuf());
}
