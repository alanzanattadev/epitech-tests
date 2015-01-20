
#include "Mixer.h"
#include "LittleHand.h"
#include "Banana.h"
#include "Coconut.h"
#include "Lime.h"
#include "FruitBox.h"
#include <iostream>

int	main()
{
  FruitBox fb(10);

  fb.putFruit(new Coconut);
  fb.putFruit(new Coconut);
  fb.putFruit(new Banana);
  fb.putFruit(new Banana);
  fb.putFruit(new Lemon);
  fb.putFruit(new Lemon);
  fb.putFruit(new Lime);
  fb.putFruit(new Lime);
  fb.putFruit(new Banana);
  fb.putFruit(new Lemon);

  Mixer m;

  std::cout << m.mix(fb) << std::endl;
  LittleHand::plugMixer(m);
  std::cout << m.mix(fb) << std::endl;
  return 0;
}
