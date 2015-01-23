
#include "find.hpp"
#include <list>
#include <vector>
#include <iostream>

int	main()
{
  std::list<int>	l1;
  l1.push_back(5);
  l1.push_back(42);
  l1.push_back(5);
  l1.push_back(34);
  l1.push_back(12);

  std::cout << *do_find(l1, 42) << std::endl;
  std::cout << *do_find(l1, 5) << std::endl;

  std::list<int>::iterator notFoundListIterator = do_find(l1, 3);
  std::cout << "End iterator if not found: " << std::boolalpha << (notFoundListIterator == l1.end()) << std::endl;

  std::vector<int>	s2;
  s2.push_back(45);
  s2.push_back(46);
  s2.push_back(42);
  s2.push_back(46);

  std::vector<int>::iterator notFoundVectorIterator = do_find(s2, 3);
  std::cout << *do_find(s2, 42) << std::endl;
  std::cout << *do_find(s2, 46) << std::endl;
  std::cout << "End iterator if not found: " << std::boolalpha << (notFoundVectorIterator == s2.end()) << std::endl;

  return (0);
}
