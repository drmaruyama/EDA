#include <cmath>
#include "eda.h"

void EDA :: initialize(char inputfile[]) {
  read_input(inputfile);
  fname.append(inputfile);
  fname = fname.substr(0, fname.rfind("."));
  pf = M_PI * rho * dia * dia * dia / 6.0;
  dk = M_PI / (dr * grid);
  allocate();
}
