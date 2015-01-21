
#include "ex02.hpp"
#include <iostream>

int	main()
{
  {
    int		t1[5] = { -654, 43, 56, -56 };
    int		t2[1] = { 42 };
    int		t3[2] = { 4543534, 234233 };

    std::cout << ::templateMin(t1, 5) << std::endl;
    std::cout << ::templateMin(t2, 1) << std::endl;
    std::cout << ::templateMin(t3, 2) << std::endl;

    std::cout << std::endl;

    std::cout << ::nonTemplateMin(t1, 5) << std::endl;
    std::cout << ::nonTemplateMin(t2, 1) << std::endl;
    std::cout << ::nonTemplateMin(t3, 2) << std::endl;
  }
}
