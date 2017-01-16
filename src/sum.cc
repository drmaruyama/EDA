double sum (double * a, double d, int n) {
  double s = 0.0;
  for (int i = 1; i < n - 1; ++i) {
    s += a[i];
  }
  s += 0.5 * (a[0] + a[n - 1]);
  s *= d;
  return s;
}
