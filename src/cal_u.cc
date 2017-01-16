#include<cmath>
#include"eda.h"

void EDA :: cal_u() {
  void fft(double *, double *, double, double, int, int);
  double excp(double);
  double excp_fd(double, double);
  double excp_sd(double, double);

  for (int i = 1; i < grid; ++i) {
    ueffk1[i] = ueffk2[i];
    tauk1[i] = tauk2[i];
    deffr0[i] = deffr[i]; 
  }
  for (int i = 0; i < grid; ++i) {
    dcfk[i] = tcfk[i] - tauk2[i];
  }
  double a = rho * excp_sd(pf, rho);
  double b = 2.0 * excp_fd(pf, rho);
  for (int i = 1; i < grid; ++i) {
    wk[i] = (- b + sqrt(b * b - 4.0 * a * dcfk[i])) / (2.0 * a);
  }

  for (int i = 0; i < grid; ++i) {
    tauk2[i] = dcfk[i] * rho * tcfk[i];
  }

  fft(taur, tauk2, dr, dk, grid, -1);

  for (int i = 0; i < grid; ++i) {
    tauk2[i] = 0.1 * tauk2[i] + 0.9 * tauk1[i];
  }
  
  for (int i = 1; i < grid; ++i) {
    fftk[i] = wk[i] * rho * tcfk[i];
  }

  fft(fftr, fftk, dr, dk, grid, -1);
  
  for (int i = 1; i < grid; ++i) {
    deffr[i] = 0.1 * (rho + fftr[i]) + 0.9 * deffr0[i];
    if (deffr[i] < 0.0) deffr[i] = 1.0e-5;
  }
  
  fft(fftr1, tcfk, dr, dk, grid, -1);
  
  double bexcp = excp(pf);
  double bexcp_fd = excp_fd(pf, rho);
  a = pf / rho;
  
  for (int i = 1; i < grid; ++i) {
    double d = deffr[i];
    double p = a * d;
    double bexcpr = excp(p);
    double bexcp_fdr = excp_fd(p, d);
    fftr[i] = bexcpr - bexcp;
    fftr1[i] = rho * (fftr1[i] + 1.0) * bexcp_fdr - rho * bexcp_fd;
  }

  fft(fftk, fftr, dr, dk, grid, 1);

  for (int i = 1; i < grid; ++i) {
    ueffk2[i] = - fftk[i];
  }

  fft(fftk1, fftr1, dr, dk, grid, 1);

  for (int i = 1; i < grid; ++i) {
    fftk1[i] = wk[i] * fftk1[i];
  }

  for (int i = 1; i < grid; ++i) {
    ueffk2[i] -= fftk1[i];
  }

  for (int i = 1; i < grid; ++i) {
    ueffk2[i] = 0.1 * ueffk2[i] + 0.9 * ueffk1[i];
  }
  
  fft(u, ueffk2, dr, dk, grid, -1);
}
