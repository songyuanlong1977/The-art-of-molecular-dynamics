#ifndef INIT
#define INIT
#include "head.h"
#include <stdio.h>
#include "macros.h"

#define D2_INI {0,0}
#define D2_REAL {0.,0.}
#define D3_INI {0,0,0}
#define D3_REAL {0.,0.,0.}

#if NDIM==2
  VecI cells=D2_INI;
  VecI initUcell=D2_INI;
  VecR region=D2_REAL;
  VecR vSum=D2_REAL;
#endif

#if NDIM==3
  VecI cells=D3_INI;
  VecI initUcell=D3_INI;
  VecR region=D3_REAL;
  VecR vSum=D3_REAL;
#endif

  Mol *mol=NULL;
  real *histVel=NULL;
  int *cellList=NULL;
  int *nebrTab=NULL;

  Prop kinEnergy=D3_REAL;
  Prop pressure=D3_REAL;
  Prop totEnergy=D3_REAL;

  real deltaT=0., density=0., rCut=0., temperature=0., timeNow=0., uSum=0.;
  real velMag=0., virSum=0., vvSum=0.;
  real rangeVel=0.;
  real rNebrShell=0.;
  real dispHi=0.;
  real kinEnInitSum=0.;
  int moreCycles=0, nMol=0, stepAvg=0, stepCount=0, stepEquil=0, stepLimit=0;
  int randSeed=0;
  int countVel=0;
  int limitVel=0;
  int  sizeHistVel=0;
  int stepVel=0;
  int nebrNow=0,nebrTabFac=0,nebrTabLen=0,nebrTabMax=0;
  int stepInitlzTemp=0;
 char *fileNameR[] = {"xxnnchecka.data", "xxnncheckb.data",
   "xxnncklast.data", "xxnnsnap.data"}, fileName[5][20];
 char *progId = "md";
 char *errorMsg[] = {"", "bond snapped", "read checkpoint data",
   "write checkpoint data", "copy buffer full", "empty event pool",
   "message buffer full", "outside region", "read snap data",
   "write snap data", "subdivision unfinished", "too many cells",
   "too many copied mols", "too many layers", "too many levels",
   "too many mols", "too many moved mols", "too many neighbors",
   "too many replicas"};

 NameList nameList[]={
  NameR (deltaT),
  NameR (density),
  NameI (initUcell),
  NameI (nebrTabFac),
  NameI (randSeed),
  NameR (rNebrShell),
  NameI (stepAvg),
  NameI (stepEquil),
  NameI (stepInitlzTemp),
  NameI (stepLimit),
  NameR (temperature),
};
#endif
