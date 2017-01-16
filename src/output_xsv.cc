#include <iostream>
#include <fstream>
#include <cmath>
#include "eda.h"

void EDA :: output_xsv() {
  void fft(double *, double *, double, double, int, int);
  double sum(double *, double, int);

  for (int i = 1; i < grid; ++i) {
    fftk[i] = dcfk[i];
  }
  fft(fftr, fftk, dr, dk, grid, -1);
  for (int i = 0; i < grid; ++i) {
    fftr[i] *= 4.0 * M_PI * dr * dr * i * i;
  }  
  dcfk[0] = sum(fftr, dr, grid);
  
  for (int i = 1; i < grid; ++i) {
    fftk[i] = wk[i];
  }
  fft(fftr, fftk, dr, dk, grid, -1);
  for (int i = 0; i < grid; ++i) {
    fftr[i] *= 4.0 * M_PI * dr * dr * i * i;
  }  
  double w = sum(fftr, dr, grid);
  wk[0] = w;
  
  std::ofstream out_file;
  out_file.open((fname + ".xsv").c_str());
  out_file << pf << " " << w << std::endl;
  for (int i = 0; i < grid; ++i) {
    out_file << dk * i << " " << dcfk[i] << " " << wk[i] << std::endl;
  }
}
