//
// MixerBase.cpp for piscine in /home/lachka_s/dev
//
// Made by sacha lachkar
// Login   <lachka_s@epitech.net>
//
// Started on  Tue Jan 22 15:23:43 2013 sacha lachkar
// Last update Tue Jan 22 15:23:43 2013 sacha lachkar
//

#include "MixerBase.h"

MixerBase::MixerBase() : _plugged(false), _mixfunc(NULL)
{
}

int	MixerBase::mix(FruitBox& fb) const
{
  if (_plugged)
    return ((*_mixfunc)(fb));
  return (0);
}
