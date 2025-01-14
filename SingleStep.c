#include "head.h"
#include <stdio.h>
void SingleStep(void)
{
  ++ stepCount;
  timeNow = stepCount * deltaT;
  PredictorStep ();
  ApplyBoundaryCond ();
  ComputeForces ();
  CorrectorStep ();
  ApplyBoundaryCond ();
  EvalProps ();
  if (stepCount < stepEquil) AdjustInitTemp ();
  AccumProps (1);
  if (stepCount % stepAvg == 0) 
  {
    AccumProps (2);
    PrintSummary (stdout);
    AccumProps (0);
  }
}
