#ifndef FUNC
#define HEADER
#include <stdio.h>
int GetNameList(int argc, char ** argv);
void PrintNameList(FILE *);
void SetParams(void);
void SetupJob(void);
void SingleStep(void);
void LeapfrogStep(int);
void ApplyBoundaryCond(void);
void ComputeForces(void);
void EvalProps(void);
void AccumProps(int);
void PrintSummary(FILE *);
void AllocArrays(void);
void InitCoords(void);
void InitVels(void);
void InitAccels(void);
void VRand(VecR *);
real RandR(void);
void EvalVelDist(void);
void PrintVelDist(FILE *);
#endif

