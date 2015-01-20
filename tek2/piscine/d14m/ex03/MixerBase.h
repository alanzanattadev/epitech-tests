
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
