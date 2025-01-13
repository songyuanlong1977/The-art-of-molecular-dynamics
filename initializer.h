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

  Prop kinEnergy={0.,0.,0.};
  Prop pressure={0.,0.,0.};
  Prop totEnergy={0.,0.,0.};

  real deltaT=0., density=0., rCut=0., temperature=0., timeNow=0., uSum=0.;
  real velMag=0., virSum=0., vvSum=0.;
  real rangeVel=0.;
  real rNebrShell=0.;
  real dispHi=0.;
  int moreCycles=0, nMol=0, stepAvg=0, stepCount=0, stepEquil=0, stepLimit=0;
  int countVel=0;
  int limitVel=0;
  int  sizeHistVel=0;
  int stepVel=0;
  int nebrNow=0,nebrTabFac=0,nebrTabLen=0,nebrTabMax=0;
  int stepAdjustTemp=0;

 NameList nameList[]={
	NameR(deltaT),
	NameR(density),
	NameI(initUcell),
	NameI(stepAvg), /*the number of steps to output the avereged result*/
	NameI(stepEquil),
	NameI(stepLimit),/*the maximum number of steps*/
	NameI(limitVel),
	NameR(rangeVel),
	NameI(sizeHistVel),
	NameI(stepVel),
	NameR(temperature),
	NameI(nebrTabFac),
	NameR(rNebrShell),
	NameI(stepAdjustTemp)
};
#endif
