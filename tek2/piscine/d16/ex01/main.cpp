
#include "DomesticKoala.h"
#include "KoalaAction.h"
#include <iostream>

int	main()
{
  KoalaAction	a1;
  KoalaAction2	a2;

  DomesticKoala	k(a1);

  k.learnAction(56, &KoalaAction::hit);
  k.learnAction(23, &KoalaAction::kick);
  k.learnAction(87, &KoalaAction::punch);
  k.learnAction(127, &KoalaAction::die);

  k.doAction(56, "AIE");
  k.doAction(23, "OUILLE");
  k.doAction(87, "KAI");
  k.doAction(127, "KRAK");

  std::cout << std::endl;

  k.unlearnAction(127);
  k.unlearnAction(23);
  k.unlearnAction(45);

  k.doAction(56, "AIE");
  k.doAction(23, "OUILLE");
  k.doAction(87, "KAI");
  k.doAction(127, "KRAK");

  std::cout << std::endl;

  k.setKoalaAction(a2);

  k.doAction(56, "AIE");
  k.doAction(23, "OUILLE");
  k.doAction(87, "KAI");
  k.doAction(127, "KRAK");

  k.learnAction(56, &KoalaAction::hit);
  k.learnAction(23, &KoalaAction::kick);
  k.learnAction(87, &KoalaAction::punch);
  k.learnAction(127, &KoalaAction::die);

  std::cout << std::endl;

  k.doAction(56, "AIE");
  k.doAction(23, "OUILLE");
  k.doAction(87, "KAI");
  k.doAction(127, "KRAK");

  std::cout << std::endl;

  DomesticKoala	*k2 = new DomesticKoala(k);

  k.doAction(56, "AIE");
  k.doAction(23, "OUILLE");
  k.doAction(87, "KAI");
  k.doAction(127, "KRAK");

  k2->doAction(56, "AIE");
  k2->doAction(23, "OUILLE");
  k2->doAction(87, "KAI");
  k2->doAction(127, "KRAK");

  delete k2;

  std::cout << std::endl;

  {
    DomesticKoala k3(a1);
    k3 = k;

    k.doAction(56, "AIE");
    k.doAction(23, "OUILLE");
    k.doAction(87, "KAI");
    k.doAction(127, "KRAK");

    k3.doAction(56, "AIE");
    k3.doAction(23, "OUILLE");
    k3.doAction(87, "KAI");
    k3.doAction(127, "KRAK");
  }

  std::cout << std::endl;

  k.doAction(56, "AIE");
  k.doAction(23, "OUILLE");
  k.doAction(87, "KAI");
  k.doAction(127, "KRAK");

  std::cout << std::endl;

  k.doAction(234, "FAIL");
  k.doAction(212, "FAIL");

  std::vector<methodPointer_t> v = *k.getActions();

  unsigned int	i;
  i = 0;
  while (++i <= v.size())
    std::cout << v[i - 1] << " ";
  std::cout << std::endl;

  return (0);
}
