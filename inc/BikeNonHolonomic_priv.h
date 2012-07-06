#ifndef BIKENONHOLONOMIC_PRIV_H
#define BIKENONHOLONOMIC_PRIV_H
template <class T>
void VelocityConstraintMatrixMinimal(const T LeanPitchSteer[3],
                                     const BikeParameters<T> & b,
                                     Eigen::Matrix<T, 3, 6> & B)
{
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 6; ++j) {
      B(i, j) = i*j; // Need to implement
    }
  }

} // VelocityConstraintMatrixMinimal()
#endif // BIKENONHOLONOMIC_PRIV_H
