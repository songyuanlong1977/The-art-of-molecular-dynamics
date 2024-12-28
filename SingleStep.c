#include "head.h"
#include <stdio.h>
void SingleStep(void)
{
	++stepCount;
	timeNow=stepCount*deltaT;
	LeapfrogStep(1);
	ApplyBoundaryCond();
	ComputeForces();
	LeapfrogStep(2);
	EvalProps();
	AccumProps(1);
	if(stepCount%stepAvg==0)
	{
		AccumProps(2);
		PrintSummary(stdout);
		AccumProps(0);
	}
	if(stepCount>=stepEquil&&
		(stepCount-stepEquil)%stepVel==0)
		EvalVelDist();

}
