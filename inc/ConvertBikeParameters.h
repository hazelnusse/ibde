#ifndef CONVERTBIKEPARAMETERS_H
#define CONVERTBIKEPARAMETERS_H

#include "BikeParameters.h"
#include "MeijaardBikeParameters.h"

template <class T>
BikeParameters<T> ConvertBikeParameters(const MeijaardBikeParameters<T> & parameters);

#include "ConvertBikeParameters_priv.h"

#endif // CONVERTBIKEPARAMETERS_H
