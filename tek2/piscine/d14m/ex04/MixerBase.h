/*
** MixerBase.h for piscine in /home/lachka_s/dev
**
** Made by sacha lachkar
** Login   <lachka_s@epitech.net>
**
** Started on  Tue Jan 22 15:23:35 2013 sacha lachkar
** Last update Tue Jan 22 15:23:36 2013 sacha lachkar
*/

#ifndef MIXERBASE_H_
# define MIXERBASE_H_

# include "FruitBox.h"

class MixerBase
{
 public:
  MixerBase();
  int mix(FruitBox&) const;

 protected:
  bool _plugged;
  int (*_mixfunc)(FruitBox&);
};

#endif /* !MIXERBASE_H_ */
