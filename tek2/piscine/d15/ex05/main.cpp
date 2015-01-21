
#include "ex05.hpp"
#include <iostream>

double	int2double(int const & n)
{
  return (static_cast<double>(n));
}

int	main()
{
  array<int>	a1;

  std::cout << a1.size() << std::endl;
  a1.dump();
  a1[5] = 5;
  std::cout << a1.size() << std::endl;
  a1.dump();
  a1[0] = 4;
  a1[1] = 2;
  a1[2] = 3;
  a1[3] = 1;
  a1[4] = 6;
  std::cout << a1.size() << std::endl;
  a1.dump();
  std::cout << a1[0] << a1[1] << std::endl;

  array<int>	*a2 = new array<int>(a1);
  std::cout << a2->size() << std::endl;
  a2->dump();
  (*a2)[2] = 0;
  a2->dump();

  a1.dump();
  a1 = *a2;
  std::cout << a1.size() << std::endl;
  a1.dump();

  array<int> const	a3 = *a2;
  std::cout << a3.size() << std::endl;
  a3.dump();

  delete a2;
  a1.dump();
  a3.dump();

  std::cout << a3[3] << std::endl;
  try
    {
      a3[16] = 5;
    }
  catch (std::exception ex)
    {
      std::cout << "gotcha" << std::endl;
    }

  array<double>	a4(1);
  std::cout << a4.size() << std::endl;
  a4[0] = 0;
  a4.dump();

  a4 = a3.convertTo(&int2double);
  std::cout << a4.size() << std::endl;
  a4.dump();

  array<bool> a5;
  std::cout << a5.size() << std::endl;
  a5.dump();

  a5 = array<bool>(2);

  std::cout << a5.size() << std::endl;
  a5.dump();

  a5[1] = true;

  std::cout << a5.size() << std::endl;
  a5.dump();

  return (0);
}
