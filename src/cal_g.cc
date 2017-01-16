#include<cmath>
#include"eda.h"

void EDA :: cal_g() {
  void fft(double *, double *, double, double, int, int);
  double sum(double *, double, int);

  for (int i = 0; i < grid; ++i) {
    tcfk0[i] = tcfk[i];
  }
  for (int i = 0; i < grid; ++i) {
    if (dr * i < dia) {
      g[i] = 0.0;
    } else {
      g[i] = exp(u[i]);
    }
  }
  for (int i = 0; i < grid; ++i) {
    fftr[i] = g[i] - 1.0;
  }
  
  fft(tcfk, fftr, dr, dk, grid, 1);

  for (int i = 0; i < grid; ++i) {
    fftr[i] *= 4.0 * M_PI * dr * dr * i * i;
  }
   
  tcfk[0] = sum(fftr, dr, grid);
}
