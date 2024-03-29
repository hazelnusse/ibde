#ifndef BIKEHOLONOMIC_H
#define BIKEHOLONOMIC_H
#include "BikeParameters.h"

template <class T>
T FrontContactHeight(const T LeanPitchSteer[3], const BikeParameters<T> & b);

template <class T>
void FrontContactHeightGradient(const T LeanPitchSteer[3], const BikeParameters<T> & b, T gradient[3]);

template <class T>
void ReferencePitchAngles(const BikeParameters<T> & b, T Angles[2]);

template <class T>
void RefineLeanPitchSteer(const BikeParameters<T> & b, int maxIterations,
                          T LeanPitchSteer[3]);

#include "BikeHolonomic_priv.h"

#endif // BIKEHOLONOMIC_H
