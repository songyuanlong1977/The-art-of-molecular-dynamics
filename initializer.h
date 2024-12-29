#ifndef INIT
#define INIT
#include "head.h"
#include <stdio.h>
  Mol *mol=NULL;
  VecR region={0.,0.};
  VecR vSum={0.,0.};

  VecI initUcell={0,0};
  Prop kinEnergy={0.,0.,0.};
  Prop pressure={0.,0.,0.};
  Prop totEnergy={0.,0.,0.};

  real deltaT=0., density=0., rCut=0., temperature=0., timeNow=0., uSum=0., velMag=0., virSum=0., vvSum=0.;

 NameList nameList[]={
	NameR(deltaT),
	NameR(density),
	NameI(initUcell),
	NameI(stepAvg), /*the number of steps to output the avereged result*/
	NameI(stepEquil),
	NameI(stepLimit),/*the maximum number of steps*/
	NameR(temperature)
};
#endif
