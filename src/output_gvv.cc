#include <iostream>
#include <fstream>
#include <cmath>
#include "eda.h"

void EDA :: output_gvv() {
  std::ofstream out_file;
  out_file.open((fname + ".gvv").c_str());

  for (int i = 0; i < grid; ++i) {
    out_file << dr * i << " " << g[i] << std::endl;
  }
}
