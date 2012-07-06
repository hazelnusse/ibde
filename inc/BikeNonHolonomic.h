#ifndef BIKENONHOLONOMIC_H
#define BIKENONHOLONOMIC_H

#include <Eigen/Core>
#include "BikeParameters.h"

template <class T>
void VelocityConstraintMatrixMinimal(const T LeanPitchSteer[3],
                                     const BikeParameters<T> & b,
                                     Eigen::Matrix<T, 3, 6> & B);

template <class T>
void VelocityConstraintMatrix(const T LeanPitchSteer[3],
                              const BikeParameters<T> & b,
                              Eigen::Matrix<T, 5, 8> & B);


#include "BikeNonHolonomic_priv.h"

#endif // BIKENONHOLONOMIC_H
