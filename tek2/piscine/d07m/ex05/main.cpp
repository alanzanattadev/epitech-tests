//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07m/ex05
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 15:30:10 2013 louis brunner
// Last update Tue Jan 15 15:31:32 2013 louis brunner
//

#include "Exam.hh"

int main(void)
{
  Exam e = Exam(&Exam::cheat);
  e.kobayashiMaru = &Exam::start;
  (e.*e.kobayashiMaru)(3);
  Exam::cheat = true;
  if (e.isCheating())
    (e.*e.kobayashiMaru)(4);
}
