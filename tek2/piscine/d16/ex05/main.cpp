
#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main(int ac, char **av)
{
  if (ac == 1 && av == av)
    {
      MutantStack<int> mstack;

      mstack.push(5);
      mstack.push(17);

      std::cout << mstack.top() << std::endl;

      mstack.pop();

      std::cout << mstack.size() << std::endl;

      mstack.push(3);
      mstack.push(5);
      mstack.push(737);
      mstack.push(0);

      MutantStack<int>::iterator it = mstack.begin();
      MutantStack<int>::iterator end_it = mstack.end();

      ++it;
      --it;
      while (it != end_it)
	{
	  std::cout << *it << std::endl;
	  ++it;
	}
      std::stack<int> s(mstack);
      std::cout << s.size() << std::endl;
      MutantStack<int> copy = mstack;
      std::cout << copy.size() << std::endl;
      MutantStack<int> assign;
      assign = mstack;
      std::cout << mstack.size() << std::endl;
    }
  else
    {
      std::list<int> mstack;

      mstack.push_back(5);
      mstack.push_back(17);

      std::cout << mstack.back() << std::endl;

      mstack.pop_back();

      std::cout << mstack.size() << std::endl;

      mstack.push_back(3);
      mstack.push_back(5);
      mstack.push_back(737);
      mstack.push_back(0);

      std::list<int>::iterator it = mstack.begin();
      std::list<int>::iterator end_it = mstack.end();

      ++it;
      --it;
      while (it != end_it)
	{
	  std::cout << *it << std::endl;
	  ++it;
	}
    }
  return 0;
}
