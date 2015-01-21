#include <stdexcept>
#include "SimplePtr.hpp"
#include "WaterReclaimer.hpp"

int main()
{
  SimplePtr reclaimer(new WaterReclaimer);
  SimplePtr reclaimer2(new WaterReclaimer);
  SimplePtr reclaimer3(new WaterReclaimer);
  return 0;
}
