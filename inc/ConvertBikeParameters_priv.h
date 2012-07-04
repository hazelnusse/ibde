#ifndef CONVERTBIKEPARAMETERS_PRIV_H
#define CONVERTBIKEPARAMETERS_PRIV_H

#include <cmath>

template <class T>
BikeParameters<T> ConvertBikeParameters(const MeijaardBikeParameters<T> & parameters)
{
  using std::sin; using std::cos; using std::pow;
  BikeParameters<T> b;
  const T w = parameters.w,
        c = parameters.c,
        lambda = parameters.lambda,
        g = parameters.g,
        rR = parameters.rR,
        mR = parameters.mR,
        IRxx = parameters.IRxx,
        IRyy = parameters.IRyy,
        xB = parameters.xB,
        zB = parameters.zB,
        mB = parameters.mB,
        IBxx = parameters.IBxx,
        IByy = parameters.IByy,
        IBzz = parameters.IBzz,
        IBxz = parameters.IBxz,
        xH = parameters.xH,
        zH = parameters.zH,
        mH = parameters.mH,
        IHxx = parameters.IHxx,
        IHyy = parameters.IHyy,
        IHzz = parameters.IHzz,
        IHxz = parameters.IHxz,
        rF = parameters.rF,
        mF = parameters.mF,
        IFxx = parameters.IFxx,
        IFyy = parameters.IFyy,
        tR = parameters.tR,
        tF = parameters.tF;

  // Rear Assembly:
  b.rear.gyrostat.I.xx = IBxx*pow(cos(lambda), 2) - 2*IBxz*sin(lambda)*cos(lambda) + IBzz*pow(sin(lambda), 2) + IRxx + mB*xB*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*cos(lambda)/(mB + mR) + mB*(pow(xB, 2) + xB*(-(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*sin(lambda)/(mB + mR) - (mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*cos(lambda)/(mB + mR)) + (-(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*cos(lambda)/(mB + mR) + (mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*sin(lambda)/(mB + mR))*(rR + tR + zB) + pow(rR + tR + zB, 2) - (xB*sin(lambda) + (rR + tR + zB)*cos(lambda))*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))/(mB + mR) - (xB*cos(lambda) - (rR + tR + zB)*sin(lambda))*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/(mB + mR) + pow(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda), 2)/pow(mB + mR, 2)) - mB*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*(rR + tR + zB)*sin(lambda)/(mB + mR) + mR*pow(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda), 2)/pow(mB + mR, 2) + (-mB*pow(xB, 2)*cos(lambda) + mB*xB*(rR + tR + zB)*sin(lambda) + mB*xB*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/(mB + mR))*cos(lambda) - (-mB*xB*(rR + tR + zB)*cos(lambda) + mB*pow(rR + tR + zB, 2)*sin(lambda) + mB*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*(rR + tR + zB)/(mB + mR))*sin(lambda);
  b.rear.gyrostat.I.yy = IByy + IRyy + mB*(pow(xB, 2) + xB*(-(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*sin(lambda)/(mB + mR) - (mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*cos(lambda)/(mB + mR)) + (-(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*cos(lambda)/(mB + mR) + (mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*sin(lambda)/(mB + mR))*(rR + tR + zB) + pow(rR + tR + zB, 2) - (xB*sin(lambda) + (rR + tR + zB)*cos(lambda))*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))/(mB + mR) - (xB*cos(lambda) - (rR + tR + zB)*sin(lambda))*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/(mB + mR) + pow(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda), 2)/pow(mB + mR, 2) + pow(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda), 2)/pow(mB + mR, 2)) + mR*(pow(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda), 2)/pow(mB + mR, 2) + pow(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda), 2)/pow(mB + mR, 2));
  b.rear.gyrostat.I.zz = IBxx*pow(sin(lambda), 2) + 2*IBxz*sin(lambda)*cos(lambda) + IBzz*pow(cos(lambda), 2) + IRxx + mB*xB*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*sin(lambda)/(mB + mR) + mB*(pow(xB, 2) + xB*(-(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*sin(lambda)/(mB + mR) - (mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*cos(lambda)/(mB + mR)) + (-(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*cos(lambda)/(mB + mR) + (mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*sin(lambda)/(mB + mR))*(rR + tR + zB) + pow(rR + tR + zB, 2) - (xB*sin(lambda) + (rR + tR + zB)*cos(lambda))*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))/(mB + mR) - (xB*cos(lambda) - (rR + tR + zB)*sin(lambda))*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/(mB + mR) + pow(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda), 2)/pow(mB + mR, 2)) + mB*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*(rR + tR + zB)*cos(lambda)/(mB + mR) + mR*pow(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda), 2)/pow(mB + mR, 2) + (-mB*pow(xB, 2)*sin(lambda) - mB*xB*(rR + tR + zB)*cos(lambda) + mB*xB*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))/(mB + mR))*sin(lambda) + (-mB*xB*(rR + tR + zB)*sin(lambda) - mB*pow(rR + tR + zB, 2)*cos(lambda) + mB*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*(rR + tR + zB)/(mB + mR))*cos(lambda);
  b.rear.gyrostat.I.xy = 0.0;
  b.rear.gyrostat.I.yz = 0.0;
  b.rear.gyrostat.I.xz = IBxx*sin(lambda)*cos(lambda) - IBxz*pow(sin(lambda), 2) + IBxz*pow(cos(lambda), 2) - IBzz*sin(lambda)*cos(lambda) + mB*xB*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*cos(lambda)/(mB + mR) - mB*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*(rR + tR + zB)*sin(lambda)/(mB + mR) - mB*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/pow(mB + mR, 2) - mR*(mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/pow(mB + mR, 2) + (-mB*pow(xB, 2)*cos(lambda) + mB*xB*(rR + tR + zB)*sin(lambda) + mB*xB*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/(mB + mR))*sin(lambda) + (-mB*xB*(rR + tR + zB)*cos(lambda) + mB*pow(rR + tR + zB, 2)*sin(lambda) + mB*(mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))*(rR + tR + zB)/(mB + mR))*cos(lambda);
  b.rear.gyrostat.J = IRyy;
  b.rear.gyrostat.m = mR + mB;
  b.rear.gyrostat.d = (mB*xB*cos(lambda) - mB*(rR + tR + zB)*sin(lambda))/(mB + mR);
  b.rear.gyrostat.e = 0.0;
  b.rear.gyrostat.f = (mB*xB*sin(lambda) + mB*(rR + tR + zB)*cos(lambda))/(mB + mR);
  b.rear.a = rR;
  b.rear.b = tR;
  b.rear.g = (c + w)*cos(lambda) - (rR + tR)*sin(lambda);
  b.rear.h = 0.0;

  // Front Assembly:
  b.front.gyrostat.I.xx = IFxx + IHxx*pow(cos(lambda), 2) - 2*IHxz*sin(lambda)*cos(lambda) + IHzz*pow(sin(lambda), 2) + mF*pow(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda), 2)/pow(mF + mH, 2) + mH*(pow(-w + xH, 2) + (-w + xH)*(-(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*sin(lambda)/(mF + mH) - (mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*cos(lambda)/(mF + mH)) + (-(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*cos(lambda)/(mF + mH) + (mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*sin(lambda)/(mF + mH))*(rF + tF + zH) + pow(rF + tF + zH, 2) - ((-w + xH)*sin(lambda) + (rF + tF + zH)*cos(lambda))*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))/(mF + mH) - ((-w + xH)*cos(lambda) - (rF + tF + zH)*sin(lambda))*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/(mF + mH) + pow(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda), 2)/pow(mF + mH, 2)) + mH*(-w + xH)*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*cos(lambda)/(mF + mH) - mH*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*(rF + tF + zH)*sin(lambda)/(mF + mH) + (-mH*pow(-w + xH, 2)*cos(lambda) + mH*(-w + xH)*(rF + tF + zH)*sin(lambda) + mH*(-w + xH)*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/(mF + mH))*cos(lambda) - (-mH*(-w + xH)*(rF + tF + zH)*cos(lambda) + mH*pow(rF + tF + zH, 2)*sin(lambda) + mH*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*(rF + tF + zH)/(mF + mH))*sin(lambda);
  b.front.gyrostat.I.yy = IFyy + IHyy + mF*(pow(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda), 2)/pow(mF + mH, 2) + pow(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda), 2)/pow(mF + mH, 2)) + mH*(pow(-w + xH, 2) + (-w + xH)*(-(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*sin(lambda)/(mF + mH) - (mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*cos(lambda)/(mF + mH)) + (-(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*cos(lambda)/(mF + mH) + (mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*sin(lambda)/(mF + mH))*(rF + tF + zH) + pow(rF + tF + zH, 2) - ((-w + xH)*sin(lambda) + (rF + tF + zH)*cos(lambda))*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))/(mF + mH) - ((-w + xH)*cos(lambda) - (rF + tF + zH)*sin(lambda))*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/(mF + mH) + pow(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda), 2)/pow(mF + mH, 2) + pow(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda), 2)/pow(mF + mH, 2));
  b.front.gyrostat.I.zz = IFxx + IHxx*pow(sin(lambda), 2) + 2*IHxz*sin(lambda)*cos(lambda) + IHzz*pow(cos(lambda), 2) + mF*pow(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda), 2)/pow(mF + mH, 2) + mH*(pow(-w + xH, 2) + (-w + xH)*(-(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*sin(lambda)/(mF + mH) - (mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*cos(lambda)/(mF + mH)) + (-(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*cos(lambda)/(mF + mH) + (mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*sin(lambda)/(mF + mH))*(rF + tF + zH) + pow(rF + tF + zH, 2) - ((-w + xH)*sin(lambda) + (rF + tF + zH)*cos(lambda))*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))/(mF + mH) - ((-w + xH)*cos(lambda) - (rF + tF + zH)*sin(lambda))*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/(mF + mH) + pow(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda), 2)/pow(mF + mH, 2)) + mH*(-w + xH)*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*sin(lambda)/(mF + mH) + mH*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*(rF + tF + zH)*cos(lambda)/(mF + mH) + (-mH*pow(-w + xH, 2)*sin(lambda) - mH*(-w + xH)*(rF + tF + zH)*cos(lambda) + mH*(-w + xH)*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))/(mF + mH))*sin(lambda) + (-mH*(-w + xH)*(rF + tF + zH)*sin(lambda) - mH*pow(rF + tF + zH, 2)*cos(lambda) + mH*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*(rF + tF + zH)/(mF + mH))*cos(lambda);
  b.front.gyrostat.I.xy = 0.0;
  b.front.gyrostat.I.yz = 0.0;
  b.front.gyrostat.I.xz = IHxx*sin(lambda)*cos(lambda) - IHxz*pow(sin(lambda), 2) + IHxz*pow(cos(lambda), 2) - IHzz*sin(lambda)*cos(lambda) - mF*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/pow(mF + mH, 2) + mH*(-w + xH)*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*cos(lambda)/(mF + mH) - mH*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*(rF + tF + zH)*sin(lambda)/(mF + mH) - mH*(mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/pow(mF + mH, 2) + (-mH*pow(-w + xH, 2)*cos(lambda) + mH*(-w + xH)*(rF + tF + zH)*sin(lambda) + mH*(-w + xH)*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/(mF + mH))*sin(lambda) + (-mH*(-w + xH)*(rF + tF + zH)*cos(lambda) + mH*pow(rF + tF + zH, 2)*sin(lambda) + mH*(mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))*(rF + tF + zH)/(mF + mH))*cos(lambda);
  b.front.gyrostat.J = IFyy;
  b.front.gyrostat.m = mF + mH;
  b.front.gyrostat.d = (mH*(-w + xH)*cos(lambda) - mH*(rF + tF + zH)*sin(lambda))/(mF + mH);
  b.front.gyrostat.e = 0.0;
  b.front.gyrostat.f = (mH*(-w + xH)*sin(lambda) + mH*(rF + tF + zH)*cos(lambda))/(mF + mH);
  b.front.a = rF;
  b.front.b = tF;
  b.front.g = c*cos(lambda) - (rF + tF)*sin(lambda);
  b.front.h = 0.0;

  // Steer axis offset and gravity
  b.ls = w*sin(lambda) + (-rF + rR - tF + tR)*cos(lambda);
  b.g = g;

  return b;
} // ConvertParameters()

#endif // CONVERTBIKEPARAMETERS_PRIV_H
