#include "head.h"
void EvalVelDist()
{
	real deltaV,histSum;
	int j, n;
	if (countVel==0)
	{
		for(j=0;j<sizeHistVel;j++) histVel[j]=0.;
	}
	deltaV=rangeVel/sizeHistVel;
	DO_MOL 
	{
		j=VLen(mol[n].rv)/deltaV;
		++histVel[Min(j,sizeHistVel-1)];
	}
	++countVel;
	if(countVel==limitVel)
	{
		histSum=0.;
		for(j=0;j<sizeHistVel;j++) histSum+=histVel[j];
		for(j=0;j<sizeHistVel;j++) histVel[j]/=histSum;
		PrintVelDist(stdout);
		countVel=0;
	}
}
