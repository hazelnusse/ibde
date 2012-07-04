#ifndef WHEELASSEMBLYPARAMETERS_H
#define WHEELASSEMBLYPARAMETERS_H

#include "CylindricalGyrostatParameters.h"

template <class T>
class WheelAssemblyParameters {
 public:
  CylindricalGyrostatParameters<T> gyrostat;
  T a, b, g, h;
  void Validate();
};

#include "WheelAssemblyParameters_priv.h"

#endif // WHEELASSEMBLYPARAMETERS_H
