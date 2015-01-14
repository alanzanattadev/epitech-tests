//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Wed Jan 16 21:03:07 2013 louis brunner
//

#include "carrier.hh"
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
    Carrier		c("Yellow submarine");
    Carrier const	c2;
    //Carrier		c3 = c;
    Droid	*d1 = new Droid("Captain");
    Droid	*d2 = new Droid("Lieutenant");
    Droid	*d3 = new Droid("Sergeant");
    Droid	*d4 = new Droid("Caporal");
    Droid	*d5 = new Droid("Major");
    size_t	pile1 = 230, pile2 = 150;

    test(false, c(1, 1));

    CATCH(std::cout << c << std::endl, "Carrier 'Yellow submarine' Droid(s) on-board:\n[0] : Free\n[1] : Free\n[2] : Free\n[3] : Free\n[4] : Free\nSpeed : 0, Energy 300\n");
    CATCH(std::cout << c2 << std::endl, "Carrier '' Droid(s) on-board:\n[0] : Free\n[1] : Free\n[2] : Free\n[3] : Free\n[4] : Free\nSpeed : 0, Energy 300\n");

    c << d1 << d2 << d3 << d4 << d5;

    CATCH(std::cout << c2[0] << std::endl, "0\n");
    CATCH(std::cout << c2[1] << std::endl, "0\n");

    test(NULL, d1);
    test(NULL, d2);
    test(NULL, d3);
    test(NULL, d4);
    test(NULL, d5);

    CATCH(std::cout << c << std::endl, "Carrier 'Yellow submarine' Droid(s) on-board:\n[0] : Droid 'Captain', Standing by, 50\n[1] : Droid 'Lieutenant', Standing by, 50\n[2] : Droid 'Sergeant', Standing by, 50\n[3] : Droid 'Caporal', Standing by, 50\n[4] : Droid 'Major', Standing by, 50\nSpeed : 50, Energy 300\n");

    c >> d5 >> d4;

    CATCH(std::cout << *d4 << std::endl, "Droid 'Lieutenant', Standing by, 50\n");
    CATCH(std::cout << *d5 << std::endl, "Droid 'Captain', Standing by, 50\n");

    c << d4;

    CATCH(std::cout << c << std::endl, "Carrier 'Yellow submarine' Droid(s) on-board:\n[0] : Droid 'Lieutenant', Standing by, 50\n[1] : Free\n[2] : Droid 'Sergeant', Standing by, 50\n[3] : Droid 'Caporal', Standing by, 50\n[4] : Droid 'Major', Standing by, 50\nSpeed : 60, Energy 300\n");

    test(60, c.getSpeed());
    c[1] = d5;
    test(60, c.getSpeed());
    test(50, (~c).getSpeed());

    CATCH(std::cout << c << std::endl, "Carrier 'Yellow submarine' Droid(s) on-board:\n[0] : Droid 'Lieutenant', Standing by, 50\n[1] : Droid 'Captain', Standing by, 50\n[2] : Droid 'Sergeant', Standing by, 50\n[3] : Droid 'Caporal', Standing by, 50\n[4] : Droid 'Major', Standing by, 50\nSpeed : 50, Energy 300\n");

    c[5] = d1;

    test("", c2.getId());
    test(300, c2.getEnergy());
    test(100, c2.getAttack());
    test(90, c2.getToughness());
    test(0, c2.getSpeed());

    test("Yellow submarine", c.getId());
    c.setId("USS Enterprise");
    test("USS Enterprise", c.getId());
    test(300, c.getEnergy());
    c.setEnergy(234234);
    test(600, c.getEnergy());
    c.setEnergy(300);
    test(300, c.getEnergy());
    test(230, pile1);
    test(150, pile2);
    c << pile1 << pile2;
    test(600, c.getEnergy());
    test(0, pile1);
    test(80, pile2);

    test(600, c.getEnergy());
    test(false, c(34444, 534543));
    test(600, c.getEnergy());
    test(true, c(1, 2));
    test(558, c.getEnergy());

    test(60, c.getSpeed());
    c.setSpeed(100);
    test(60, c.getSpeed());
    test(60, (~c).getSpeed());
  }

  {
    Carrier c("HellExpress");
    Droid *d1= new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
    c[0] = d1;
    std::cout << (~c).getSpeed() << std::endl;
    c(4, 2);
    std::cout << c << std::endl;
    c(-15, 4);
    std::cout << c << std::endl;
    c[3] = 0;
    c[4] = 0;
    (~c)(-15, 4);
    std::cout << c << std::endl;
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
