#include <iostream>
#include <fstream>
#include "eda.h"

void EDA :: read_input(char inputfile[]) {
  std::ifstream in_file;
  in_file.open(inputfile);

  double dummy;
  in_file >> outlist;
  in_file >> dr >> grid;
  in_file >> dummy >> dummy >> dummy >> minimum;
  in_file >> rho >> dia;
}
