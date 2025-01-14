#include "head.h"
void SetupJob(void)
{
	AllocArrays();
  	InitRand (randSeed);
	stepCount=0;
	InitCoords();
	InitVels();
	InitAccels();
	AccumProps(0);
  	kinEnInitSum = 0.;
  	nebrNow = 1;
}
 
