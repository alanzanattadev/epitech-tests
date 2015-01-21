#include <stdexcept>
#include <cassert>

#include "RefPtr.hpp"
#include "../ex01/Oxygenator.hpp"

int
main()
{
  RefPtr oxygenator = new BaseComponent;
  BaseComponent *raw = oxygenator.get();
  RefPtr other(raw);
  RefPtr useless;
  RefPtr lastOne;
  lastOne = other;
  assert(lastOne.get() == raw);
  (void)useless;
  lastOne = NULL;
  return 0;
}
