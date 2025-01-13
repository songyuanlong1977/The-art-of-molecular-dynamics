#include "head.h"
void InitCoords(void)
{
/*
	Random set of initial coordinates
*/
	real randTab[100];
	int i,n,k;
	for (i=0;i<100;i++) randTab[i]=RandR();
	/*
	Rand generate uniformly distributed random values in the range(0,1)
	*/
	n=0;
	DO_MOL 
	{
		for (k=0;k<NDIM;k++)
		{
			i=(int) (100.*RandR());
			VComp (mol[n].r,k)=(randTab[i]-0.5)*VComp (region,k);
			/*
				a shuffing scheme employed to reduce possible unwanted correlations in the random numbers
			*/
			randTab[i]=RandR();
		}
	}


}
