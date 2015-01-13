/*
** main.c for piscine in /home/brunne_l/dev/rendu/piscine/tests/j07m
**
** Made by louis brunner
** Login   <brunne_l@epitech.net>
**
** Started on  Tue Jan 15 09:25:36 2013 louis brunner
// Last update Tue Jan 15 09:37:37 2013 louis brunner
*/

#include "Federation.hh"

int main(void)
{
  Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
  Federation::Ship Independant(150, 230, "Greok");
  WarpSystem::QuantumReactor QR;
  WarpSystem::QuantumReactor QR2;
  WarpSystem::Core core(&QR);
  WarpSystem::Core core2(&QR2);

  UssKreog.setupCore(&core);
  UssKreog.checkCore();
  Independant.setupCore(&core2);
  Independant.checkCore();

  QR.setStability(false);
  QR2.setStability(false);
  UssKreog.checkCore();
  Independant.checkCore();
  return 0;
}
