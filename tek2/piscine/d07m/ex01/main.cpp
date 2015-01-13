//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07m
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 10:08:43 2013 louis brunner
// Last update Tue Jan 15 11:06:49 2013 louis brunner
//

#include <iostream>
#include "Federation.hh"
#include "Borg.hh"

int main(void)
{
  Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
  Federation::Starfleet::Captain James("James T. Kirk");
  //Federation::Starfleet::Captain James2 = "James T. Kirk";
  Federation::Starfleet::Ensign Ensign("Pavel Chekov");
  //Federation::Starfleet::Ensign Ensign2 = "Pavel Chekov";
  WarpSystem::QuantumReactor QR;
  WarpSystem::QuantumReactor QR2;
  WarpSystem::Core core(&QR);
  WarpSystem::Core core2(&QR2);

  UssKreog.setupCore(&core);
  UssKreog.checkCore();
  UssKreog.promote(&James);
  James.setAge(42);
  std::cout << "Age: 42 = " << James.getAge() << std::endl;
  QR.setStability(false);
  UssKreog.checkCore();

  Borg::Ship Cube;
  Cube.setupCore(&core2);
  Cube.checkCore();
  QR2.setStability(false);
  Cube.checkCore();

  return 0;
}
