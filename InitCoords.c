#include "head.h"
void InitCoords(void)
{
	VecR c,gap;
	/*gap: */
	int n, nx,ny;
	VDiv(gap,region,initUcell);
	/*region hold the size of a square */

	n=0;
	for (ny=0;ny<initUcell.y; ny++)
	{
		for (nx=0;nx<initUcell.x;nx++)
		{
			VSet(c,nx+0.5,ny+0.5);
			/*c is the normalied coordinate of the unit cells*/
			VMul(c,c,gap);
			/*c is coordinate mapped to the region*/
			VVSAdd(c,-0.5,region);
			/* make origin the center of region */
			mol[n].r=c;
			++n;
		}
	}

}
