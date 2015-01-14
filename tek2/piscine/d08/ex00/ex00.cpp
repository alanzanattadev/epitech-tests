//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Wed Jan 16 16:14:05 2013 louis brunner
//

#include "droid.hh"
#include <iostream>
#include <sstream>
#include <cstdlib>

static int	nbErrors = 0;
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
    redirectOutput();
    Droid	basic;
    mustPrint("Droid '' Activated\n");

    redirectOutput();
    Droid	r2d2("R2D2");
    mustPrint("Droid 'R2D2' Activated\n");

    redirectOutput();
    Droid	dupli = r2d2;
    mustPrint("Droid 'R2D2' Activated, Memory Dumped\n");

    redirectOutput();
    Droid const	Wally("Wally");
    mustPrint("Droid 'Wally' Activated\n");
    size_t	uranium = 43;
    size_t	plutonium = 250;

    redirectOutput();
    std::cout << basic << std::endl;
    mustPrint("Droid '', Standing by, 50\n");

    redirectOutput();
    std::cout << r2d2 << std::endl;
    mustPrint("Droid 'R2D2', Standing by, 50\n");

    redirectOutput();
    std::cout << dupli << std::endl;
    mustPrint("Droid 'R2D2', Standing by, 50\n");

    test(true, r2d2 == dupli);
    test(false, basic == dupli);

    test("Standing by", *r2d2.getStatus());
    r2d2.setStatus(new std::string("BIP BIP"));
    test("BIP BIP", *r2d2.getStatus());
    test("Standing by", *dupli.getStatus());

    dupli = basic;
    test(false, basic != dupli);
    test(true, r2d2 != dupli);

    test(50, basic.getEnergy());
    test(50, r2d2.getEnergy());
    test(43, uranium);
    test(250, plutonium);
    basic << uranium << plutonium;
    test(0, uranium);
    test(243, plutonium);
    test(100, basic.getEnergy());
    r2d2 << plutonium;
    test(100, r2d2.getEnergy());
    test(193, plutonium);

    test(25, dupli.getAttack());
    test(15, dupli.getToughness());
    test("Standing by", *dupli.getStatus());
    dupli.setStatus(new std::string("SLAY THE ORCS"));
    test("SLAY THE ORCS", *dupli.getStatus());
    test("Standing by", *basic.getStatus());
    r2d2.setEnergy(42);
    test(42, r2d2.getEnergy());
    test("R2D2", r2d2.getId());
    r2d2.setId("r2d2 v2.0");
    test("r2d2 v2.0", r2d2.getId());

    dupli = dupli;
    test("SLAY THE ORCS", *dupli.getStatus());

    test("Wally", Wally.getId());
    test(50, Wally.getEnergy());
    test(25, Wally.getAttack());
    test(15, Wally.getToughness());
    test("Standing by", *Wally.getStatus());
    redirectOutput();
    std::cout << Wally << std::endl;
    mustPrint("Droid 'Wally', Standing by, 50\n");

    redirectOutput();
    std::cout << basic << std::endl;
    mustPrint("Droid '', Standing by, 100\n");

    redirectOutput();
    std::cout << r2d2 << std::endl;
    mustPrint("Droid 'r2d2 v2.0', BIP BIP, 42\n");

    redirectOutput();
    std::cout << dupli << std::endl;
    mustPrint("Droid '', SLAY THE ORCS, 50\n");

    dupli = Wally;
    test(true, r2d2 != Wally);
    test(true, dupli == Wally);
    test(false, Wally == r2d2);
    test(false, Wally != dupli);

    redirectOutput();
    std::cout << dupli << std::endl;
    mustPrint("Droid 'Wally', Standing by, 50\n");

    redirectOutput();
    Droid useless(Wally);
    mustPrint("Droid 'Wally' Activated, Memory Dumped\n");
    test(true, useless == Wally);

    redirectOutput();
    std::cout << useless << std::endl;
    mustPrint("Droid 'Wally', Standing by, 50\n");

    test(50, dupli.getEnergy());
    dupli.setEnergy(3454345345534);
    test(100, dupli.getEnergy());

    redirectOutput();
  }
  mustPrint(true, "Droid 'Wally' Destroyed\nDroid 'Wally' Destroyed\nDroid 'Wally' Destroyed\nDroid 'r2d2 v2.0' Destroyed\nDroid '' Destroyed\n");

  return (res());
}

static std::streambuf		*cout_old = NULL;
static std::stringstream	output;

static void	padding()
{
  if (paddingEnabled)
    std::cout << std::endl;
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
  std::cout << std::boolalpha << a << " == " << b << ": " << std::noboolalpha;
  test(a == b);
}

void	test(int const a, int const b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	test(std::string const & a, std::string const & b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	test(void const *a, void const *b)
{
  std::cout << a << " == " << b << ": ";
  test(a == b);
}

void	testd(void const *a, void const *b)
{
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
	    || (!p.empty() && p.at(p.length() - 1) != '\n'));

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
  output.str("");
  cout_old = std::cout.rdbuf(output.rdbuf());
}
