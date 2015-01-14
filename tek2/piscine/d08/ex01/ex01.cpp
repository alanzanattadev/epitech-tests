//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Wed Jan 14 16:11:04 2015 Maxime Fischer
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
    (d2 += 120) += 3;
    DroidMemory	d3 = d2;

    CATCH(std::cout << d1 << std::endl, "DroidMemory '292616681', 0\n");
    CATCH(std::cout << d2 << std::endl, "DroidMemory '1638893237', 123\n");
    CATCH(std::cout << d3 << std::endl, "DroidMemory '1638893237', 123\n");

    test(0, d1.getExp());
    test(123, d2.getExp());
    test(123, d3.getExp());
    d3.setExp(321);
    test(321, d3.getExp());

    test(292616681, d1.getFingerPrint());
    test(1638893237, d2.getFingerPrint());
    test(1638893237, d3.getFingerPrint());
    d3.setFingerPrint(0x4242);
    test(0x4242, d3.getFingerPrint());

    CATCH(std::cout << d1 << std::endl, "DroidMemory '292616681', 0\n");
    CATCH(std::cout << d2 << std::endl, "DroidMemory '1638893237', 123\n");
    CATCH(std::cout << d3 << std::endl, "DroidMemory '16962', 321\n");

    d3 << d1 << d2;

    CATCH(std::cout << d1 << std::endl, "DroidMemory '292616681', 0\n");
    CATCH(std::cout << d2 << std::endl, "DroidMemory '1638893237', 123\n");
    CATCH(std::cout << d3 << std::endl, "DroidMemory '1893678366', 444\n");

    d1 >> d3 >> d2;

    CATCH(std::cout << d1 << std::endl, "DroidMemory '292616681', 0\n");
    CATCH(std::cout << d2 << std::endl, "DroidMemory '16962', 567\n");
    CATCH(std::cout << d3 << std::endl, "DroidMemory '1638909175', 444\n");

    (d3 += d1) += d2;

    CATCH(std::cout << d1 << std::endl, "DroidMemory '292616681', 0\n");
    CATCH(std::cout << d2 << std::endl, "DroidMemory '16962', 567\n");
    CATCH(std::cout << d3 << std::endl, "DroidMemory '1893695324', 1011\n");

    d3 = d1 + 50 + 43;

    CATCH(std::cout << d1 << std::endl, "DroidMemory '292616681', 0\n");
    CATCH(std::cout << d2 << std::endl, "DroidMemory '16962', 567\n");
    CATCH(std::cout << d3 << std::endl, "DroidMemory '292616688', 93\n");

    DroidMemory d4;
    d4 = d2 + d1 + d3;

    CATCH(std::cout << d1 << std::endl, "DroidMemory '292616681', 0\n");
    CATCH(std::cout << d2 << std::endl, "DroidMemory '16962', 567\n");
    CATCH(std::cout << d3 << std::endl, "DroidMemory '292616688', 93\n");
    CATCH(std::cout << d4 << std::endl, "DroidMemory '16987', 660\n");

    CATCH(Droid	r2d2("R2D2"), "Droid 'R2D2' Activated\n");
    CATCH(Droid const	Wally("Wally"), "Droid 'Wally' Activated\n");

    CATCH(std::cout << r2d2 << std::endl, "Droid 'R2D2', Standing by, 50\n");
    CATCH(std::cout << Wally << std::endl, "Droid 'Wally', Standing by, 50\n");

    test(true, r2d2 == Wally);
    test("Standing by", *r2d2.getStatus());
    r2d2.setStatus(new std::string("BIP BIP"));
    test("BIP BIP", *r2d2.getStatus());
    test("Standing by", *Wally.getStatus());
    test(false, r2d2 == Wally);

    DroidMemory	*dptr = new DroidMemory();
    test(false, Wally.getBattleData() == NULL);
    r2d2.setBattleData(dptr);
    test(true, r2d2.getBattleData() == dptr);

    redirectOutput();
  }
  mustPrint(true, "Droid 'Wally' Destroyed\nDroid 'R2D2' Destroyed\n");

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
