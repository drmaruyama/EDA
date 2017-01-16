#include "eda.h"

void EDA :: output() {
  if (outlist.find("x") != std::string::npos) {
    output_xsv();
  }
  if (outlist.find("g") != std::string::npos) {
    output_gvv();
  }
}
