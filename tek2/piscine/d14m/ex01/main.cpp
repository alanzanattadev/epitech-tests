
#include "LittleHand.h"
#include "Lime.h"
#include "Banana.h"
#include <iostream>

int	main()
{
  FruitBox	unsorted(9);
  unsorted.putFruit(new Lemon);
  unsorted.putFruit(new Banana);
  unsorted.putFruit(new Banana);
  unsorted.putFruit(new Lime);
  unsorted.putFruit(new Lemon);
  unsorted.putFruit(new Lime);
  unsorted.putFruit(new Lemon);
  unsorted.putFruit(new Banana);
  unsorted.putFruit(new Lime);

  FruitBox	lemons(2);
  FruitBox	bananas(2);
  FruitBox	limes(2);

  Fruit *f;

  LittleHand::sortFruitBox(unsorted, lemons, bananas, limes);

  std::cout << unsorted.nbFruits() << std::endl;
  std::cout << lemons.nbFruits() << std::endl;
  std::cout << bananas.nbFruits() << std::endl;
  std::cout << limes.nbFruits() << std::endl;

  f = lemons.pickFruit();
  std::cout << f->getName() << std::endl;
  delete f;
  f = lemons.pickFruit();
  std::cout << f->getName() << std::endl;
  delete f;

  f = bananas.pickFruit();
  std::cout << f->getName() << std::endl;
  delete f;
  f = bananas.pickFruit();
  std::cout << f->getName() << std::endl;
  delete f;

  f = limes.pickFruit();
  std::cout << f->getName() << std::endl;
  delete f;
  f = limes.pickFruit();
  std::cout << f->getName() << std::endl;
  delete f;

  FruitBox	f1(24);
  FruitBox	f2(11);
  FruitBox	f3(6);
  FruitBox	f4(6);

  int	i = -1;
  while (++i < 40)
    f1.putFruit(new Lemon);
  f1.pickFruit();
  f1.pickFruit();
  i = -1;
  while (++i < 40)
    f1.putFruit(new Lemon);
  i = -1;
  while (++i < 40)
    f1.pickFruit();
  i = -1;
  while (++i < 40)
    f1.putFruit(new Lemon);
  i = -1;
  while (++i < 40)
    f2.putFruit(new Lemon);
  i = -1;
  while (++i < 40)
    f3.putFruit(new Lemon);
  i = -1;
  while (++i < 40)
    f4.putFruit(new Lemon);

  std::cout << f1.nbFruits() << std::endl;
  std::cout << f2.nbFruits() << std::endl;
  std::cout << f3.nbFruits() << std::endl;
  std::cout << f4.nbFruits() << std::endl;

  return 0;
}
