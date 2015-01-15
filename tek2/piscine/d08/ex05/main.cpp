//
// ex00.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07a
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 17:38:55 2013 louis brunner
// Last update Thu Jan 15 04:41:42 2015 matthieu kern
//

#include "droidfactory.hh"
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

  }

  {
    DroidFactory factory(3);
    Droid **w;
    Droid *newbie = NULL;
    //    Droid *newbie2 = NULL;
    w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i)
      {
	w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
	*(w[i]->getBattleData()) += (i * 100);
      }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    /*Supply s4(Supply::Silicon, 4566);
      Supply s5(Supply::Iron, 4535);*/

    factory >> newbie;

    std::cout << newbie << std::endl;

    factory << s1 << s2;
    std::cout << factory << std::endl;
    s3 >> factory >> newbie;
    std::cout << factory << std::endl;
    factory++ >> newbie;
    std::cout << *newbie->getBattleData() << std::endl;
    --factory >> newbie;
    std::cout << *newbie->getBattleData() << std::endl;
    return 0;
    /*    std::cout << "----------" << std::endl;
    std::cout << factory << std::endl;
    newbie2 << factory << s4 << s5;
    std::cout << factory << std::endl;
    std::cout << *newbie2 << std::endl;
    std::cout << *newbie2->getBattleData() << std::endl;*/
  }

  //  return (res());
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
