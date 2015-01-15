//
// main.cpp for  in /home/didier_m/school/d09/ex03
// 
// Made by maxime didier
// Login <didier_m@epitech.net>
// 
// Started on  Thu Jan 12 13:54:44 2012 maxime didier
// Last update Thu Jan 12 19:06:05 2012 maxime didier
//

#include <iostream>
#include "Warrior.hh"
#include "Priest.hh"

using namespace std;

# define CHECK(func)						\
  cout << "[ " #func " ]" << endl;				\
  c.func;							\
  cout << "Range = "						\
  << ((c.Range == Character::CLOSE) ? "CLOSE" : "RANGE")	\
  << "\nPV = " << c.getPv()					\
  << "\npower = " << c.getPower()				\
  << "\n------------------------------" << endl

# define CHECKR(func)						\
  cout << "[ " #func " ]" << endl;				\
  ret = c.func;							\
  cout << "Value: "  << ret << "\n";				\
  cout << "Range = "						\
  << ((c.Range == Character::CLOSE) ? "CLOSE" : "RANGE")	\
  << "\nPV = " << ((c.getPv() < 0) ? 0 : c.getPv())		\
  << "\npower = " << c.getPower()				\
  << "\n------------------------------" << endl

# define TEST(real, cast)						\
  void test_##real##_##cast() {						\
    int ret;								\
    int	i;								\
    cout << "##############################\n"				\
      #real "(as " #cast ")\n"						\
      "(creation)" << endl;						\
    real	r(#real #cast, 42);					\
    cast& 	c = r;							\
    CHECKR(CloseAttack());						\
    CHECKR(RangeAttack());						\
    CHECK(TakeDamage(100));						\
    CHECK(Heal());							\
    cout << ">> Dummy actions to empty mana <<"				\
	 << endl;							\
    for (i = 0; i < 10; i++) {						\
      c.CloseAttack();							\
      c.RangeAttack();							\
    }									\
    cout << "------------------------------\n"				\
	 << endl;							\
    CHECK(RestorePower());						\
    CHECK(TakeDamage(10));						\
    CHECK(TakeDamage(90));						\
  }

# define ALL					\
  TEST(Character, Character)			\
  TEST(Warrior, Warrior)			\
  TEST(Warrior, Character)			\
  TEST(Mage, Mage)				\
  TEST(Mage, Character)				\
  TEST(Priest, Priest)				\
  TEST(Priest, Mage)				\
  TEST(Priest, Character)

ALL

int		main() {
#undef TEST
#define TEST(real, cast)	test_##real##_##cast();
  ALL
}
