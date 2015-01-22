
#ifndef KOALAACTION_HPP_
# define KOALAACTION_HPP_

# include <iostream>

class KoalaAction
{
public:
  KoalaAction();

  virtual void	hit(std::string const &);
  virtual void	kick(std::string const &);
  virtual void	punch(std::string const &);
  virtual void	die(std::string const &);
};

class KoalaAction2 : public KoalaAction
{
public:
  KoalaAction2();

  void	hit(std::string const &);
  void	kick(std::string const &);
  void	punch(std::string const &);
  void	die(std::string const &);
};

#endif /* !KOALAACTION_HPP_ */
