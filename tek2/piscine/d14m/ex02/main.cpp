
#include "Coconut.h"
#include "LittleHand.h"
#include <iostream>

int	main()
{
  {
    Coconut**		pack = new Coconut*[14];
    FruitBox * const *	boxes;
    int			i = -1;

    boxes = LittleHand::organizeCoconut(NULL);
    std::cout << boxes << std::endl;

    while (++i < 13)
      pack[i] = new Coconut;
    pack[i] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    i = -1;
    while (boxes[++i])
      {
        std::cout << boxes[i]->nbFruits() << std::endl;
        delete boxes[i];
      }
    delete [] boxes;

    pack = new Coconut*[1];
    pack[0] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    std::cout << boxes[0] << std::endl;
    delete [] boxes;
  }

  {
    Coconut**		pack = new Coconut*[19];
    FruitBox * const *	boxes;
    int			i = -1;

    boxes = LittleHand::organizeCoconut(NULL);
    std::cout << boxes << std::endl;

    while (++i < 18)
      pack[i] = new Coconut;
    pack[i] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    i = -1;
    while (boxes[++i])
    {
      std::cout << boxes[i]->nbFruits() << std::endl;
      delete boxes[i];
    }
    delete [] boxes;

    pack = new Coconut*[1];
    pack[0] = NULL;
    boxes = LittleHand::organizeCoconut(pack);
    delete [] pack;
    std::cout << boxes[0] << std::endl;
    delete [] boxes;
  }
}
