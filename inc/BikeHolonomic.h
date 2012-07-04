#ifndef BIKEHOLONOMIC_H
#define BIKEHOLONOMIC_H
#include <array>
#include "BikeParameters.h"

template <class T>
T FrontContactHeight(const T lps[3], const BikeParameters<T> & b);

template <class T>
void FrontContactHeightGradient(const T LeanPitchSteer[3], const BikeParameters<T> & b, T gradient[3]);

template <class T>
void ReferencePitchAngles(const BikeParameters<T> & b, T Angles[2]);

template <class T>
void RefineLeanPitchSteer(const BikeParameters<T> & b, const int maxIterations,
                          const T xtol, const T ftol, T LeanPitchSteer[3]);

#include "BikeHolonomic_priv.h"

#endif // BIKEHOLONOMIC_H
