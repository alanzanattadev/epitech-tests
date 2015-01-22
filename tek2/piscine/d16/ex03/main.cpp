
#include "BF_Translator.h"
#include <iostream>

int main()
{
  BF_Translator	bf;

  if (bf.translate("lol", "out.c") != 0)
    std::cout << "GOOD1" << std::endl;
  if (bf.translate("in.bf", "NO.c") != 0)
    std::cout << "GOOD2" << std::endl;
  if (bf.translate("in.bf", "out.c") == 0)
    std::cout << "GOOD3" << std::endl;
  bf.translate("in2.bf", "out2.c");
  return 0;
}

