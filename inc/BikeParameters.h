#ifndef BIKEPARAMETERS_H
#define BIKEPARAMETERS_H

#include "WheelAssemblyParameters.h"

template <class T>
class BikeParameters {
 public:
  WheelAssemblyParameters<T> rear, front;
  T ls, g;
  void Validate();
};

#include "BikeParameters_priv.h"

#endif // BIKEPARAMETERS_H
