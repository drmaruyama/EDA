#include"eda.h"

void EDA :: allocate() {
  g = new double[grid];
  dcfk = new double[grid];
  tcfk = new double[grid];
  tcfk0 = new double[grid];
  fftr = new double[grid];
  fftr1 = new double[grid];
  fftk = new double[grid];
  fftk1 = new double[grid];
  ueffk1 = new double[grid];
  ueffk2 = new double[grid];
  taur = new double[grid];
  tauk1 = new double[grid];
  tauk2 = new double[grid];
  deffr0 = new double[grid];  
  deffr = new double[grid];  
  wk = new double[grid];
  u = new double[grid];
}
