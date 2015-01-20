#include "Errors.hpp"
#include <iostream>
#include <string>

static void throwNasaError(std::string const& message, std::string const& component) {
  throw NasaError(message, component);
}

static void throwMissionCriticalError(std::string const& message, std::string const& component) {
  throw MissionCriticalError(message, component);
}

static void throwLifeCriticalError(std::string const& message, std::string const& component) {
  throw LifeCriticalError(message, component);
}

static void throwUserError(std::string const& message, std::string const& component) {
  throw UserError(message, component);
}

static void throwCommunicationError(std::string const& message, std::string const& _) {
  (void) _;
  throw CommunicationError(message);
}

static void testException(void (*exceptionThrower)(std::string const&, std::string const&), std::string const& message, std::string const& component) {
  try {
    exceptionThrower(message, component);
  } catch (NasaError& ne) { // Si emacs ne marche pas, au pire on a ça.
    std::cout << ne.getComponent() << ": \"" << ne.what() << "\"" << std::endl;
  }
}

int main(void) {
  testException(&throwNasaError, "On se fait un baby' ?", "Nose");
  testException(&throwMissionCriticalError, "TG, casse-toi !", "TransportPad");
  testException(&throwLifeCriticalError, "True, False, Tarte aux quetsches.", "Oven");
  testException(&throwUserError, "Zizi Superstar !", "SecurityCenter");
  testException(&throwCommunicationError, "I'm blue da ba dee da ba daa...", "This should not appear on this test.");
  testException(&throwNasaError, "", "");
  testException(&throwMissionCriticalError, "", "");
  testException(&throwLifeCriticalError, "", "");
  testException(&throwUserError, "", "");
  testException(&throwCommunicationError, "", "");
  return 0;
}
