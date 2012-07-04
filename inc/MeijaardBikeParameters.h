#ifndef MIEJAARDBIKEPARAMETERS_H
#define MIEJAARDBIKEPARAMETERS_H

template <class T>
class MeijaardBikeParameters {
 public:
  T w,
    c,
    lambda,
    g,
    rR,
    mR,
    IRxx,
    IRyy,
    xB,
    zB,
    mB,
    IBxx,
    IByy,
    IBzz,
    IBxz,
    xH,
    zH,
    mH,
    IHxx,
    IHyy,
    IHzz,
    IHxz,
    rF,
    mF,
    IFxx,
    IFyy,
    tR,
    tF;
  void Validate();
};

template <class T>
MeijaardBikeParameters<T> BenchmarkParameters();

#include "MeijaardBikeParameters_priv.h"

#endif // MIEJAARDBIKEPARAMETERS_H

