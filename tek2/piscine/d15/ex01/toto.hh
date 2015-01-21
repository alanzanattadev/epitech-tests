
#ifndef TOTO_HH_
# define TOTO_HH_

class toto
{
private:
  toto(const toto &){}
  toto &operator=(const toto&) {return *this;}
public:
  toto(){}
  ~toto(){}
  bool operator==(const toto&) const {return true;}
  bool operator>(const toto&) const {return false;}
  bool operator<(const toto&) const {return false;}
};

#endif /* !TOTO_HH_ */
