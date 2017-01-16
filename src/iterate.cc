#include<iostream>
#include<cmath>
#include"eda.h"

void EDA :: iterate() {
  for (int i = 0; i < grid; ++i) {
    ueffk2[i] = 0.0;
    tauk2[i] = 0.0;
    tcfk[i] = 0.0;
    deffr[i] = rho;
    u[i] = 0.0;
  }

  for (int i = 0; i < 100000; ++i) {
    cal_g();
    cal_u();
    double dh = std::abs(tcfk[1] - tcfk0[1]);
    std::cout << i << " " << dh << std::endl;

    if (dh < minimum) break;
  }
}
