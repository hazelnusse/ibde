#ifndef INERTIAPARAMETERS_H
#define INERTIAPARAMETERS_H

template <class T>
class InertiaParameters {
 public:
  T xx, yy, zz, xy, yz, xz;
  void Validate();
};

#include "InertiaParameters_priv.h"

#endif // INERTIAPARAMETERS_H
