double excp_fd(double pf, double rho) {
  return (4.0 - 2.0 * pf) / ((1.0 - pf) * (1.0 - pf) * (1.0 - pf))
    * (pf / rho);
}
