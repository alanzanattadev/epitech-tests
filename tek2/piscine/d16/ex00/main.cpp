
#include "Parser.h"
#include <iostream>

int	main()
{
  Parser	p;

  p.feed("((12*2)+14)");
  std::cout << p.result() << std::endl;

  p.feed("((17 % 9) / 4)");
  std::cout << p.result() << std::endl;

  p.reset();
  p.feed("(17 - 4) * 13");
  std::cout << p.result() << std::endl;

  p.reset();
  std::cout << p.result() << std::endl;

  p.feed(" (	  	  ( (	( 17 / 9 )  *       3 )   +   32  )   %   4)    -  67 ");
  std::cout << p.result() << std::endl;

  Parser const p2 = p;
  std::cout << p2.result() << std::endl;

  Parser p3;
  p3 = p;
  std::cout << p3.result() << std::endl;

  p.reset();
  p.feed("17 - (4 * 13)");
  std::cout << p.result() << std::endl;

  p.reset();
  p.feed("(5 + ((3 + 2) / (4 * 2))) + 2");
  std::cout << p.result() << std::endl;

  return (0);
}
