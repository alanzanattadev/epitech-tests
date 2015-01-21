
#include "ex00.hpp"
#include <iostream>

int	main()
{
  {
    std::string		v1 = "tricheur";
    std::string		v2 = "navet_m";
    std::string		v3 = "sale con";
    std::string const	v4 = "tricheur";

    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;
    swap(v1, v2);
    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;
    swap(v2, v3);
    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;
    swap(v3, v1);
    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;

    std::cout << std::endl;

    std::cout << ::min(v1, v2) << std::endl;
    std::cout << ::min(v2, v3) << std::endl;
    std::cout << (v4 == ::min(v1, v4)) << std::endl;
    std::cout << ::min(v1, ::min(v2, v3)) << std::endl;

    std::cout << std::endl;

    std::cout << ::max(v1, v2) << std::endl;
    std::cout << ::max(v2, v3) << std::endl;
    std::cout << (v4 == ::max(v1, v4)) << std::endl;
    std::cout << ::max(v1, ::max(v2, v3)) << std::endl;

    std::cout << std::endl;

    std::cout << ::add(v1, v2) << std::endl;
    std::cout << ::add(v2, v3) << std::endl;
    std::cout << ::add(v1, v4) << std::endl;
    std::cout << ::add(v1, ::add(v2, v3)) << std::endl;
  }

  std::cout << std::endl;

  {
    int		v1 = 42;
    int		v2 = 1337;
    int		v3 = -666;
    int const	v4 = 42;

    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;
    swap(v1, v2);
    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;
    swap(v2, v3);
    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;
    swap(v3, v1);
    std::cout << v1 << ":" << v2 << ":" << v3 << std::endl;

    std::cout << std::endl;

    std::cout << ::min(v1, v2) << std::endl;
    std::cout << ::min(v2, v3) << std::endl;
    std::cout << (v4 == ::min(v1, v4)) << std::endl;
    std::cout << ::min(v1, ::min(v2, v3)) << std::endl;

    std::cout << std::endl;

    std::cout << ::max(v1, v2) << std::endl;
    std::cout << ::max(v2, v3) << std::endl;
    std::cout << (v4 == ::max(v1, v4)) << std::endl;
    std::cout << ::max(v1, ::max(v2, v3)) << std::endl;

    std::cout << std::endl;

    std::cout << ::add(v1, v2) << std::endl;
    std::cout << ::add(v2, v3) << std::endl;
    std::cout << ::add(v1, v4) << std::endl;
    std::cout << ::add(v1, ::add(v2, v3)) << std::endl;
  }
}
