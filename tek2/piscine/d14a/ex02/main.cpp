#include "CommunicationDevice.hpp"
#include "Errors.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main() {
  {
    std::istream is(NULL);
    try {
      CommunicationDevice c(is, std::cout);
    } catch (CommunicationError& e) {
      std::cout << e.what() << std::endl;
    }
  }

  CommunicationDevice com(std::cin, std::cout);
  com.startMission("", NULL, 0);

  std::string names[10];
  names[1] = "a";
  names[2] = "b";
  names[3] = "c";
  names[4] = "d";
  names[5] = "e";
  names[6] = "f";
  names[7] = "junk";
  names[8] = "junk";
  names[9] = "";

  names[0] = "";
  com.startMission(names[8], names, 1);

  names[0] = "0";
  com.startMission(names[8], names, 6);

  com.receive(names[8], names[8]);

  com.send(names[7], names[7]);

  std::cout << names[7] << " " << names[8] << std::endl;
  return 0;
}
