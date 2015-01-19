//
// main.cpp for piscine in /home/brunne_l/dev/rendu/piscine/tests/j13
//
// Made by louis brunner
// Login   <brunne_l@epitech.net>
//
// Started on  Mon Jan 21 09:06:19 2013 louis brunner
// Last update Mon Jan 21 14:49:23 2013 louis brunner
//

#include "Buzz.h"
#include "Woody.h"
#include <iostream>

int	main()
{
  Woody w("wood");
  Buzz	b("Lightyear");

  if (w.setAscii("file_who_does_not_exist.txt") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::PICTURE)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }

  if (w.speak_es("Woody does not have spanish mode") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::SPEAK)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }

  if (w.speak_es("Woody does not have spanish mode") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::SPEAK)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }

  Woody w2 = w;
  {
    Toy::Error e = w2.getLastError();
    if (e.type == Toy::Error::SPEAK)
      {
	std::cout << "Error in " << e.where()
		  << ": " << e.what() << std::endl;
      }
  }

  Woody w3("KIKOO");
  {
    Toy::Error e = w3.getLastError();
    if (e.type == Toy::Error::UNKNOWN)
      std::cout << "NO ERROR" << e.where() << e.what() << std::endl;
  }

  w3 = w;
  {
    Toy::Error e = w3.getLastError();
    if (e.type == Toy::Error::SPEAK)
      {
	std::cout << "Error in " << e.where()
		  << ": " << e.what() << std::endl;
      }
  }

  Toy::Error e = b.getLastError();
  if (e.type == Toy::Error::UNKNOWN)
    std::cout << "NO ERROR" << e.where() << e.what() << std::endl;
  b.speak_es("HEY GRINGO, ABLAS ESPANOL ?");
  e = b.getLastError();
  if (e.type == Toy::Error::UNKNOWN)
    std::cout << "NO ERROR" << e.where() << e.what() << std::endl;

  Buzz b2 = b;
  e = b2.getLastError();
  if (e.type == Toy::Error::UNKNOWN)
    std::cout << "NO ERROR" << e.where() << e.what() << std::endl;

  return 0;
}
