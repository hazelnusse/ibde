#ifndef VTKHOLONOMICCONSTRAINT_H
#define VTKHOLONOMICCONSTRAINT_H

#include <iostream>
#include "vtkImplicitFunction.h"
#include "BikeParameters.h"

class vtkHolonomicConstraint : public vtkImplicitFunction
{
 public:
  // VTK related methods
  double EvaluateFunction(double x[3]);
  void EvaluateGradient(double x[3], double gradient[3]);
  static vtkHolonomicConstraint * New();
  void PrintSelf(std::ostream & os, vtkIndent indent);
  
  // Non-VTK methods
  void SetBike(BikeParameters<double> * b);

 private:
  vtkHolonomicConstraint();
  BikeParameters<double> * b_;
  vtkHolonomicConstraint(const vtkHolonomicConstraint&);  // Not implemented.
  void operator=(const vtkHolonomicConstraint&);  // Not implemented.
};
#endif // VTKHOLONOMICCONSTRAINT_H
