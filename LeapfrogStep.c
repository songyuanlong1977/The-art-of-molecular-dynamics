#include "head.h"
void LeapfrogStep(int part)
{
	int n; /*used as a local variable for DO_MOL*/
	if (part==1)
	{
		DO_MOL 
		{
			VVSAdd(mol[n].rv,0.5*deltaT,mol[n].ra);
			VVSAdd(mol[n].r,deltaT, mol[n].rv);
		}
	}
	else
	{
		DO_MOL VVSAdd(mol[n].rv,0.5*deltaT,mol[n].ra);
	}
}
