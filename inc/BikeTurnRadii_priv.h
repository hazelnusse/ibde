#ifndef BIKETURNRADII_PRIV_H
#define BIKETURNRADII_PRIV_H

#include <cmath>

template <class T>
void TurnRadii(const T LeanPitchSteer[3], const BikeParameters<T> & bike,
               T & Rr, T & Rf)
{
  using std::sqrt; using std::pow; using std::sin; using std::cos;
  const T q1 = LeanPitchSteer[0],
          q2 = LeanPitchSteer[1],
          q3 = LeanPitchSteer[2],
          a_r = bike.rear.a,
          b_r = bike.rear.b,
          g_r = bike.rear.g,
          h_r = bike.rear.h,
          a_f = bike.front.a,
          b_f = bike.front.b,
          g_f = bike.front.g,
          h_f = bike.front.h,
          ls = bike.ls;

  Rf = sqrt(pow(sin(q1)*sin(q2)*sin(q3) - cos(q1)*cos(q3), 2) - pow(cos(q2), 2)*pow(cos(q3), 2) + pow(cos(q2), 2))*(-a_f*sin(q1)*cos(q3)/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + a_f*sin(q2)*cos(q1)*pow(cos(q3), 2)/(sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2))*sin(q3)) - a_f*sin(q2)*cos(q1)/(sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2))*sin(q3)) + b_f*sin(q2)*sin(q3)*cos(q1) + b_f*sin(q2)*cos(q1)*pow(cos(q3), 2)/sin(q3) - b_f*sin(q2)*cos(q1)/sin(q3) + g_f*cos(q3)/sin(q3) - g_r/sin(q3) - h_f - ls*sin(q2)/(sin(q3)*cos(q2)));
  Rr = -(-(-Rf*sin(q1)*sin(q2)*sin(q3) + Rf*cos(q1)*cos(q3))*sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) - sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2))*sqrt(pow(sin(q1)*sin(q2)*sin(q3) - cos(q1)*cos(q3), 2) - pow(cos(q2), 2)*pow(cos(q3), 2) + pow(cos(q2), 2))*(-a_r*sin(q1) - b_f*sin(q1)*pow(sin(q2), 2)*cos(q1)*pow(cos(q3), 2) + b_f*sin(q1)*pow(sin(q2), 2)*cos(q1) - b_f*sin(q1)*cos(q1)*pow(cos(q2), 2)*pow(cos(q3), 2) + b_f*sin(q1)*cos(q1)*pow(cos(q2), 2) + b_f*sin(q1)*cos(q1)*pow(cos(q3), 2) - b_f*sin(q1)*cos(q1) + g_f*sin(q1)*sin(q2)*cos(q3) + g_f*sin(q3)*cos(q1) - g_r*sin(q1)*sin(q2) - h_f*sin(q1)*sin(q2)*sin(q3) + h_f*cos(q1)*cos(q3) - h_r*cos(q1) + ls*sin(q1)*cos(q2)) - sqrt(pow(sin(q1)*sin(q2)*sin(q3) - cos(q1)*cos(q3), 2) - pow(cos(q2), 2)*pow(cos(q3), 2) + pow(cos(q2), 2))*(-a_f*sin(q1)*cos(q1)*pow(cos(q2), 2)*pow(cos(q3), 2) + a_f*sin(q1)*cos(q1)*pow(cos(q2), 2) + 2*a_f*sin(q1)*cos(q1)*pow(cos(q3), 2) - a_f*sin(q1)*cos(q1) + 2*a_f*sin(q2)*sin(q3)*pow(cos(q1), 2)*cos(q3) - a_f*sin(q2)*sin(q3)*cos(q3)))/(sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2))*sqrt(pow(sin(q1)*sin(q2)*sin(q3) - cos(q1)*cos(q3), 2) - pow(cos(q2), 2)*pow(cos(q3), 2) + pow(cos(q2), 2)));
}
#endif // BIKETURNRADII_PRIV_H
