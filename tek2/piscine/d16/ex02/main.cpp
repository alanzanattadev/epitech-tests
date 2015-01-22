
#include "EventManager.h"
#include <iostream>

int main()
{
  EventManager *em = new EventManager();

  em->addEvent(Event(10, "Eat"));
  em->addEvent(Event(12, "Finish the exercises"));
  em->addEvent(Event(12, "Understand the thing"));
  em->addEvent(Event(15, "Set the rights"));
  em->addEvent(Event(8, "Ask what the hell a const_iterator is"));
  em->addEvent(Event(11, "Wash my hands so that my keyboard doesn't smell like kebab"));
  em->dumpEvents();
  std::cout << "=====" << std::endl;

  em->removeEventsAt(12);

  em->dumpEvents();
  std::cout << "=====" << std::endl;

  em->addTime(10);
  std::cout << "=====" << std::endl;

  em->dumpEvents();
  std::cout << "=====" << std::endl;

  std::list<Event> todo;
  todo.push_front(Event(19, "The vengeance of the Koala"));
  todo.push_front(Event(20, "The return of the vengeance of the Koala"));
  todo.push_front(Event(21, "The come back of the return of the vengeance of the Koala"));
  todo.push_front(Event(22, "The sequel to the come back of the return of ... well, you get the drift."));
  todo.push_front(Event(9, "What the hell do you mean 'It's due this morning'?!"));
  todo.push_front(Event(1, "No, no, you're pushing it now..."));

  em->addEventList(todo);
  em->dumpEvents();
  std::cout << "=====" << std::endl;

  em->dumpEventAt(15);
  std::cout << "=====" << std::endl;

  em->addTime(14);

  return 0;
}

