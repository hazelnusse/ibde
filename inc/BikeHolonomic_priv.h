#ifndef BIKEHOLONOMIC_PRIV_H
#define BIKEHOLONOMIC_PRIV_H

#include <cmath>

template <class T>
T FrontContactHeight(const T lean_pitch_steer[3], const BikeParameters<T> & bike)
{
  using std::sin; using std::cos;
  const T q1 = lean_pitch_steer[0],
          q2 = lean_pitch_steer[1],
          q3 = lean_pitch_steer[2],
          a_r = bike.rear.a,
          b_r = bike.rear.b,
          g_r = bike.rear.g,
          h_r = bike.rear.h,
          a_f = bike.front.a,
          b_f = bike.front.b,
          g_f = bike.front.g,
          h_f = bike.front.h,
          ls = bike.ls;

  return (b_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1)) - h_f)*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1)) + (-b_r*sin(q1) + h_r)*sin(q1) + (sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*(a_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3)) - g_f) + (a_f*cos(q1)*cos(q2)/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*cos(q1)*cos(q2))*cos(q1)*cos(q2) - (a_r*sin(q2) + b_r*sin(q2)*cos(q1) + g_r)*sin(q2)*cos(q1) + (-a_r*cos(q2) - b_r*cos(q1)*cos(q2) + ls)*cos(q1)*cos(q2);
} // FrontContactHeight()

template <class T>
void FrontContactHeightGradient(const T lean_pitch_steer[3], const BikeParameters<T> & bike, T gradient[3])
{
  using std::sin; using std::cos;
  const T q1 = lean_pitch_steer[0],
          q2 = lean_pitch_steer[1],
          q3 = lean_pitch_steer[2],
          a_r = bike.rear.a,
          b_r = bike.rear.b,
          g_r = bike.rear.g,
          h_r = bike.rear.h,
          a_f = bike.front.a,
          b_f = bike.front.b,
          g_f = bike.front.g,
          h_f = bike.front.h,
          ls = bike.ls;

  gradient[0] = (b_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1))*(-sin(q1)*sin(q2)*sin(q3) + cos(q1)*cos(q3)) + b_r*sin(q1)*pow(sin(q2), 2)*cos(q1) + b_r*sin(q1)*cos(q1)*pow(cos(q2), 2) - b_r*sin(q1)*cos(q1) + (b_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1)) - h_f)*(-sin(q1)*sin(q2)*sin(q3) + cos(q1)*cos(q3)) + (-b_r*sin(q1) + h_r)*cos(q1) + (sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*(a_f*(-(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*(2*sin(q1)*sin(q2)*cos(q3) + 2*sin(q3)*cos(q1))/2 + sin(q1)*cos(q1)*pow(cos(q2), 2))*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))/pow(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2), 3.0/2.0) + a_f*(sin(q1)*sin(q2)*cos(q3) + sin(q3)*cos(q1))/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*(sin(q1)*sin(q2)*cos(q3) + sin(q3)*cos(q1))) + (sin(q1)*sin(q2)*cos(q3) + sin(q3)*cos(q1))*(a_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3)) - g_f) - (a_f*cos(q1)*cos(q2)/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*cos(q1)*cos(q2))*sin(q1)*cos(q2) + (a_r*sin(q2) + b_r*sin(q2)*cos(q1) + g_r)*sin(q1)*sin(q2) - (-a_r*cos(q2) - b_r*cos(q1)*cos(q2) + ls)*sin(q1)*cos(q2) + (a_f*(-(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*(2*sin(q1)*sin(q2)*cos(q3) + 2*sin(q3)*cos(q1))/2 + sin(q1)*cos(q1)*pow(cos(q2), 2))*cos(q1)*cos(q2)/pow(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2), 3.0/2.0) - a_f*sin(q1)*cos(q2)/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) - b_f*sin(q1)*cos(q2))*cos(q1)*cos(q2));
  gradient[1] = (b_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1))*sin(q3)*cos(q1)*cos(q2) + (a_r*sin(q2) + b_r*sin(q2)*cos(q1))*cos(q1)*cos(q2) - (a_r*cos(q2) + b_r*cos(q1)*cos(q2))*sin(q2)*cos(q1) + (b_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1)) - h_f)*sin(q3)*cos(q1)*cos(q2) + (sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*(a_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*((sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*cos(q1)*cos(q2)*cos(q3) + sin(q2)*pow(cos(q1), 2)*cos(q2))/pow(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2), 3.0/2.0) - a_f*cos(q1)*cos(q2)*cos(q3)/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) - b_f*cos(q1)*cos(q2)*cos(q3)) - (a_f*cos(q1)*cos(q2)/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*cos(q1)*cos(q2))*sin(q2)*cos(q1) - (a_r*sin(q2) + b_r*sin(q2)*cos(q1) + g_r)*cos(q1)*cos(q2) - (-a_r*cos(q2) - b_r*cos(q1)*cos(q2) + ls)*sin(q2)*cos(q1) - (a_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3)) - g_f)*cos(q1)*cos(q2)*cos(q3) + (a_f*((sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*cos(q1)*cos(q2)*cos(q3) + sin(q2)*pow(cos(q1), 2)*cos(q2))*cos(q1)*cos(q2)/pow(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2), 3.0/2.0) - a_f*sin(q2)*cos(q1)/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) - b_f*sin(q2)*cos(q1))*cos(q1)*cos(q2));
  gradient[2] = (-a_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*(2*sin(q1)*cos(q3) + 2*sin(q2)*sin(q3)*cos(q1))*pow(cos(q1), 2)*pow(cos(q2), 2)/(2*pow(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2), 3.0/2.0)) + b_f*(-sin(q1)*sin(q3) + sin(q2)*cos(q1)*cos(q3))*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1)) + (b_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1)) - h_f)*(-sin(q1)*sin(q3) + sin(q2)*cos(q1)*cos(q3)) + (sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))*(-a_f*pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2)*(2*sin(q1)*cos(q3) + 2*sin(q2)*sin(q3)*cos(q1))/(2*pow(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2), 3.0/2.0)) + a_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1))/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*(sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1))) + (sin(q1)*cos(q3) + sin(q2)*sin(q3)*cos(q1))*(a_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3))/sqrt(pow(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3), 2) + pow(cos(q1), 2)*pow(cos(q2), 2)) + b_f*(sin(q1)*sin(q3) - sin(q2)*cos(q1)*cos(q3)) - g_f));
} // FrontContactHeightGradient()

template <class T>
void ReferencePitchAngles(const BikeParameters<T> & bike, T angles[2])
{
  using std::abs;
  using std::asin;
  using std::atan;
  using std::atan2;
  using std::pow;
  using std::sqrt;
  const T a_r = bike.rear.a,
          b_r = bike.rear.b,
          g_r = bike.rear.g,
          a_f = bike.front.a,
          b_f = bike.front.b,
          g_f = bike.front.g,
          ls = bike.ls;
  const T pi = 4.0L*atan(1.0L);
  const T cc = sqrt(pow(ls, 2) + pow(g_r - g_f, 2)); // center to center distance
  const T dr = a_f + b_f - a_r - b_r;       // difference in axle heights
  const T alpha = atan(ls / (g_r - g_f));
  const T beta = asin(dr / cc);

  angles[0] = alpha + beta;
  angles[1] = pi + alpha - beta;

  if (angles[0] > angles[1]){
    T tmp = angles[0];
    angles[0] = angles[1];
    angles[1] = tmp;
  }
} // ReferencePitchAngles()

template <class T>
void RefineLeanPitchSteer(const BikeParameters<T> & b, T LeanPitchSteer[3])
{

}

#endif // BIKEHOLONOMIC_PRIV_H
