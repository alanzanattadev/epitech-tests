
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
