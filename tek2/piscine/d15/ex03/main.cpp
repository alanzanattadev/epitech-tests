
#include "ex03.hpp"
#include <iostream>

int	main()
{
  {
    int		t1[5] = { -654, 43, 56, -56, 0xDEAD };
    std::string	t2[3] = { "BONJOUR", "les", "DAUPHINS" };
    double const	t3[6] = { 0.1, 0.2, 0.3, 0.5, 0.6, 0.7 };
    float	t4[0] = {};
    int		*t5 = new int[5];

    foreach(t1, print, 5);
    foreach(t2, print, 3);
    foreach(t3, print, 6);
    foreach(t4, print, 0);
    foreach(t4, print, -1);
    t5[0] = 1;
    foreach(t5, print, 5);
  }
}
