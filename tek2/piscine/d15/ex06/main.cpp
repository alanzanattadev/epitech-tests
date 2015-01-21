
#include "ex06.hpp"
#include <iostream>

int	main()
{
  Tuple<int, float>	t1;
  t1.a = 5;
  t1.b = 5.001;

  std::cout << t1.toString() << std::endl;

  Tuple<float, std::string>	t3;
  t3.a = 3.14;
  t3.b = "Segmentation fault";

  std::cout << t3.toString() << std::endl;

  Tuple<std::string, double>	t4;
  t4.a = "Erreur de segmentation";
  t4.b = 54.2;

  std::cout << t4.toString() << std::endl;

  Tuple<char, bool>	t5;
  t5.a = '$';

  std::cout << t5.toString() << std::endl;

  Tuple<int*, bool>	t6;
  t6.a = NULL;
  t6.b = false;

  std::cout << t6.toString() << std::endl;

  Tuple<int>		t7;
  t7.a = 5;
  t7.b = 6;

  std::cout << t7.toString() << std::endl;

  return (0);
}
