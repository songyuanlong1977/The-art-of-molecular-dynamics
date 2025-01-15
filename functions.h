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
real RandR(void);
void InitRand(int);
void VRand(VecR *);
void EvalVelDist(void);
void PrintVelDist(FILE *);
void BuildNebrList(void);
void ErrExit(int);
void AdjustInitTemp(void);
void PredictorStep(void);
void CorrectorStep(void);
void PerturbTrajDev(void);
void PrintTrajDev(FILE *);
void MeasureTrajDev(void);
#endif

