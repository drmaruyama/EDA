#include <iostream>
#include <fstream>
#include "eda.h"

int main (int argc, char * argv[]) {
  EDA * system;

  system = new EDA;

  if (argc == 1) {
    std::cout << "No parameter file!" << std::endl;
    return (1);
  } 

  if (argc > 2) {
    std::cout << "Too much arguments!" << std::endl;
    return(1);
  }

  system -> initialize(argv[1]);
  system -> iterate();
  system -> output();    

  return(0);
}
