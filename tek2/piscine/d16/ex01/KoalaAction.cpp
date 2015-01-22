
#include "KoalaAction.h"

KoalaAction::KoalaAction()
{
}

void	KoalaAction::hit(std::string const & m)
{
  std::cout << "HOMERUN (" << m << ")" << std::endl;
}

void	KoalaAction::kick(std::string const & m)
{
  std::cout << "HIGH-KICK (" << m << ")" << std::endl;
}

void	KoalaAction::punch(std::string const & m)
{
  std::cout << "CROCHET DU DROIT (" << m << ")" << std::endl;
}

void	KoalaAction::die(std::string const & m)
{
  std::cout << "kreooooog..... (" << m << ")" << std::endl;
}

KoalaAction2::KoalaAction2()
{
}

void	KoalaAction2::hit(std::string const &m)
{
  std::cout << "TAKE THAT (" << m << ")" << std::endl;
}

void	KoalaAction2::kick(std::string const & m)
{
  std::cout << "BOOM (" << m << ")" << std::endl;
}

void	KoalaAction2::punch(std::string const & m)
{
  std::cout << "BAM (" << m << ")" << std::endl;
}

void	KoalaAction2::die(std::string const & m)
{
  std::cout << "argh..... (" << m << ")" << std::endl;
}
