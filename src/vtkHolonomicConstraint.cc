#include "vtkObjectFactory.h"
#include "vtkHolonomicConstraint.h"

#include "BikeHolonomic.h"

vtkStandardNewMacro(vtkHolonomicConstraint);

vtkHolonomicConstraint::vtkHolonomicConstraint()
{

}

double vtkHolonomicConstraint::EvaluateFunction(double x[3])
{
  return FrontContactHeight(x, *b_);
}

void vtkHolonomicConstraint::EvaluateGradient(double x[3], double n[3])
{
  FrontContactHeightGradient(x, *b_, n); 
}

void vtkHolonomicConstraint::PrintSelf(std::ostream & os, vtkIndent indent)
{
  Superclass::PrintSelf(os,indent);
  os << indent << "Rear Assembly: " << std::endl
     << indent << " a: " << b_->rear.a << std::endl
     << indent << " b: " << b_->rear.b << std::endl
     << indent << " g: " << b_->rear.a << std::endl
     << indent << " h: " << b_->rear.a << std::endl
     << indent << "Front Assembly: " << std::endl
     << indent << " a: " << b_->front.a << std::endl
     << indent << " b: " << b_->front.b << std::endl
     << indent << " g: " << b_->front.a << std::endl
     << indent << " h: " << b_->front.a << std::endl
     << indent << "Steer axis offset: " << std::endl
     << indent << " ls: " << b_->ls << std::endl;
}

void vtkHolonomicConstraint::SetBike(BikeParameters<double> * b)
{
  b_ = b;
}
