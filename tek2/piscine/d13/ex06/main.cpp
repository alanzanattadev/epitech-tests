//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j13
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Mon Jan 21 09:06:19 2013 louis brunner
// Last update Mon Jan 21 19:42:44 2013 louis brunner
//

#include "ToyStory.h"
#include "Buzz.h"
#include "Woody.h"
#include <iostream>

int	main()
{
  Buzz	b("Buzz Lightyear");
  Woody	w("Woody des forets");

  ToyStory::tellMeAStory("FAIL", b, &Toy::speak_es, w, &Toy::speak);
  ToyStory::tellMeAStory("BadStory.txt", b, &Toy::speak, w, &Toy::speak_es);
  ToyStory::tellMeAStory("BadStory.txt", b, &Toy::speak_es, w, &Toy::speak);
  w.setAscii("woody.txt");
  ToyStory::tellMeAStory("GoodStory.txt", b, &Toy::speak, w, &Toy::speak);
  //ToyStory::tellMeAStory("EmptyStory.txt", b, &Toy::speak, w, &Toy::speak);
  ToyStory::tellMeAStory("EndStory.txt", b, &Toy::speak, w, &Toy::speak);

  Buzz	b2("buzzi");
  Woody	w2("wood");

  ToyStory::tellMeAStory("MainStory.txt", b2, &Toy::speak_es, w2, &Toy::speak);
  return 0;
}
