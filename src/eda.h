#ifndef EDA_H
#define EDA_H

#include <string>

class EDA {
public:
  EDA() {}
  ~EDA() {}
  void initialize(char[]);
  void iterate();
  void output();
private:
  void allocate();
  void calculate();
  void cal_g();
  void cal_u();
  void read_input(char[]);
  void output_gvv();
  void output_xsv();

  std::string outlist;
  std::string fname;
  double * g;
  double * dcfk;
  double * tcfk;
  double * tcfk0;
  double * fftr;
  double * fftr1;
  double * fftk;
  double * fftk1;
  double * ueffk1;
  double * ueffk2;
  double * taur;
  double * tauk1;
  double * tauk2;
  double * deffr0;  
  double * deffr;  
  double * wk;
  double * u;
  double dr, dk;
  double rho, dia;
  double pf, w;
  double minimum;
  int grid;
};

#endif
