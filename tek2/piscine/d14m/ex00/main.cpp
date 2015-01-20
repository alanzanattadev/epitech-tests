
#include "Lemon.h"
#include "Banana.h"
#include "FruitBox.h"
#include <iostream>

int	main()
{
  std::cout << "---1---" << std::endl;

  {
    Lemon l;
    Banana b;

    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;
    Fruit& f = l;
    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;
  }

  std::cout << "---2---" << std::endl;

  {
    FruitBox fb(2);
    Banana *IMABANANA = new Banana;

    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(new Lemon) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.head() != NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == IMABANANA) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << fb.putFruit(new Banana) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() != NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() != NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    delete IMABANANA;
  }

  std::cout << "---3---" << std::endl;
  {
    FruitBox fb(0);
    FruitBox fb2(-1);
    Banana *IMABANANA = new Banana;

    std::cout << fb.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb.nbFruits() << std::endl;
    std::cout << fb2.nbFruits() << std::endl;
    std::cout << std::boolalpha << (fb2.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << fb2.putFruit(IMABANANA) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.head() == NULL) << std::noboolalpha << std::endl;
    std::cout << std::boolalpha << (fb2.pickFruit() == NULL) << std::noboolalpha << std::endl;
    std::cout << fb2.nbFruits() << std::endl;
    delete IMABANANA;
  }

  return 0;
}
