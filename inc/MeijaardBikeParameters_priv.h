#ifndef MIEJAARDBIKEPARAMETERS_PRIV_H
#define MIEJAARDBIKEPARAMETERS_PRIV_H

#include <cmath>

template <class T>
void MeijaardBikeParameters<T>::Validate()
{

} // Validate()

template <class T>
MeijaardBikeParameters<T> BenchmarkParameters()
{
  using std::atan;
  return MeijaardBikeParameters<T>(
    { 1.02L,           // w
      0.08L,           // c
      atan(1.0L)*0.4L, // lambda = pi/10, pi = atan(1)*4
      9.81L,           // g
      0.3L,            // rR
      2.0L,            // mR
      0.0603L,         // IRxx
      0.12L,           // IRyy
      0.3L,            // xB
     -0.9L,            // zB
     85.0L,            // mB
      9.2L,            // IBxx
     11.0L,            // IByy
      2.8L,            // IBzz
      2.4L,            // IBxz
      0.9L,            // xH
     -0.7L,            // zH
      4.0L,            // mH
      0.05892L,        // IHxx
      0.06L,           // IHyy
      0.00708L,        // IHzz
     -0.00756L,        // IHxz
      0.35L,           // rF
      3.0L,            // mF
      0.1405L,         // IFxx
      0.28L,           // IFyy
      0.0L,            // tR
      0.0L});          // tF
}
#endif // MIEJAARDBIKEPARAMETERS_PRIV_H
