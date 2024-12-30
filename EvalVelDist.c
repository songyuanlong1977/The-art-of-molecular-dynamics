#include "head.h"
void EvalVelDist(void)
{
	real deltaV,histSum;
	int j, n;
	if (countVel==0)
	{
		for(j=0;j<sizeHistVel;j++) histVel[j]=0.;
	}
	/*initialize the array: histVel */
	deltaV=rangeVel/sizeHistVel;
	DO_MOL 
	{
		j=VLen(mol[n].rv)/deltaV;
		/*classification of the velocity:which range does v belongs to */
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
	/*when reach limit (or finished) do the normalization of the distribution*/
}
