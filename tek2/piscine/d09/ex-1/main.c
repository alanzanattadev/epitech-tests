/*
** ex-1.c for piscine in /home/brunne_l/dev/rendu/piscine/tests/j09
**
** Made by louis brunner
** Login   <brunne_l@epitech.net>
**
** Started on  Thu Jan 17 09:20:12 2013 louis brunner
** Last update Thu Jan 15 23:50:31 2015 matthieu kern
*/

#include "Exo-1.h"
#include "Exo-1.h"
#include "Exo-1.h"
#include <stdio.h>

int	main()
{
  t_koala* _LKoala = NewKoala("Legend", 1);
  t_koala* _NLKoala = NewKoala("NotLegend", 0);

  t_cthulhu* _cthulhu = NewCthulhu();

  printf("----Start----\n");

  PrintPower(_cthulhu);
  PrintPower(&_LKoala->m_parent);
  PrintPower(&_NLKoala->m_parent);

  Attack(_cthulhu);
  Attack(&_LKoala->m_parent);
  Attack(&_NLKoala->m_parent);

  Eat(_NLKoala);

  Attack(_cthulhu);
  Sleeping(_cthulhu);
  PrintPower(_cthulhu);

  Attack(&_NLKoala->m_parent);

  return(0);
}

