#ifndef CYLINDRICALGYROSTATPARAMETERS_H
#define CYLINDRICALGYROSTATPARAMETERS_H

#include "InertiaParameters.h"

template <class T>
class CylindricalGyrostatParameters {
 public:
  InertiaParameters<T> I;
  T J, m, d, e, f;
  void Validate();
};

#include "CylindricalGyrostatParameters_priv.h"

#endif // CYLINDRICALGYROSTATPARAMETERS_H
