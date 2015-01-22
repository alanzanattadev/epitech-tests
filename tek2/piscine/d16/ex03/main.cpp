
#include "BF_Translator.h"
#include <iostream>

int main()
{
  BF_Translator	bf;

  if (bf.translate("lol", "/tmp/epitech-tests/out.c") != 0)
    std::cout << "GOOD1" << std::endl;
  if (bf.translate("/tmp/epitech-tests/ex03/in.bf", "/tmp/epitech-tests/NO.c") != 0)
    std::cout << "GOOD2" << std::endl;
  if (bf.translate("/tmp/epitech-tests/ex03/in.bf", "/tmp/epitech-tests/out.c") == 0)
    std::cout << "GOOD3" << std::endl;
  bf.translate("/tmp/epitech-tests/ex03/in2.bf", "/tmp/epitech-tests/out2.c");
  return 0;
}
