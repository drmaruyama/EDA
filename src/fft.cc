#include<cmath>

void fft(double * out, double * in, double dr, double dk, int grid, int fb) {
  void sinfft(double *, int);

  double tmp[grid];
  
  if (fb == 1) {
    for (int i = 0; i < grid; ++i) {
      tmp[i] = in[i] * dr * i;
    }
  } else {
    for (int i = 0; i < grid; ++i) {
      tmp[i] = in[i] * dk * i;
    }
  }

  sinfft(tmp, grid);

  if (fb == 1) {
    for (int i = 1; i < grid; ++i) {
      out[i] = tmp[i] * 4.0 * M_PI * dr / (dk * i);
    }
  } else {
    for (int i = 1; i < grid; ++i) {
      out[i] = tmp[i] * dk / (2.0 * M_PI * M_PI * dr * i);
    }
  }
}

void sinfft(double * tmp, int grid) {
  void rdft(int, int, double *, int *, double *);

  double theta = M_PI / grid;
  double wpr = -2.0 * sin(0.5 * theta) * sin(0.5 * theta);
  double wpi = sin(theta);
  static double * w;
  static int * ip;
  static bool init = true;
  if (init) {
    ip = new int[grid];
    ip[0] = 0;
    w = new double[grid / 2];
    init = false;
  }

  tmp[0] = 0.0;
  
  double wr = 1.0;
  double wi = 0.0;

  for (int i = 0; i < grid / 2; ++i) {
    double wtmp = wr;
    wr = wr * wpr - wi * wpi + wr;
    wi = wi * wpr + wtmp * wpi + wi;
    double tmp1 = wi * (tmp[i + 1] + tmp[grid - i - 1]);
    double tmp2 = 0.5 * (tmp[i + 1] - tmp[grid - i - 1]);
    tmp[i + 1] = tmp1 + tmp2;
    tmp[grid - i - 1] = tmp1 - tmp2;
  }

  rdft(grid, 1, tmp, ip, w);

  double sum = 0.0;
  tmp[0] *= 0.5;
  tmp[1] = 0.0;

  for (int i = 0; i < grid - 1; i += 2) {
    sum += tmp[i];
    tmp[i] = tmp[i + 1];
    tmp[i + 1] = sum;
  }
}
