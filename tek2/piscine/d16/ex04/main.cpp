
#include "Ratatouille.h"
#include <iostream>

int main()
{
  Ratatouille rata;

  rata.addSauce("Tomato").addCondiment(42).addSpice(123.321);
  rata.addVegetable('x');

  std::cout << "We taste: " << rata.kooc() << std::endl;

  rata.addSauce("Bolognese");
  rata.addSpice(3.14);

  std::cout << "C'mon, taste that: " << rata.kooc() << std::endl;

  Ratatouille glurp(rata);

  glurp.addVegetable('p');
  glurp.addVegetable('o');
  glurp.addSauce("Tartar");

  std::cout << "And now: " << glurp.kooc() << std::endl;

  rata = glurp;
  std::cout << "I'll taste again, it's sooo good: " << rata.kooc() << std::endl;

  rata.addVegetable('4');
  rata.addVegetable('2');
  std::cout << "As Turing, I'll die : " << rata.kooc() << std::endl;

  return 0;
}
