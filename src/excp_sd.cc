double excp_sd(double pf, double rho) {
  return (2.0 * (5.0 - 2.0 * pf) 
	  / ((1.0 - pf) * (1.0 - pf) * (1.0 - pf) * (1.0 - pf)))
    * (pf / rho) * (pf / rho);
}
