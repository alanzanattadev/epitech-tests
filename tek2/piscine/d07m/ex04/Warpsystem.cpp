//
// Warpsystem.cpp for piscine in /home/brunne_l/dev/rendu/piscine/piscine_cpp_d07m-2016-brunne_l/ex00
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Tue Jan 15 09:39:08 2013 louis brunner
// Last update Tue Jan 15 09:59:43 2013 louis brunner
//

#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor()
{
  _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool	WarpSystem::QuantumReactor::isStable()
{
  return (_stability);
}

void	WarpSystem::QuantumReactor::setStability(bool stability)
{
  _stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *reactor)
{
  _coreReactor = reactor;
}

WarpSystem::Core::~Core()
{
}

WarpSystem::QuantumReactor	*WarpSystem::Core::checkReactor()
{
  return (_coreReactor);
}
