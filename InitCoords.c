#include "head.h"
void InitCoords(void)
{
/*
	body-centered cubic (BCC) lattice has two atoms per unit cell
*/
	VecR c,gap;
	/*gap: */
	int j,n, nx,ny,nz;
	VDiv(gap,region,initUcell);
	/*region hold the size of a square */

	n=0;
	for (nz=0;nz<initUcell.z; nz++)
	{
		for (ny=0;ny<initUcell.y;ny++)
		{
			for(nx=0;nx<initUcell.x;nx++)
			{
				VSet(c,nx+0.25,ny+0.25,nz+0.25);
				/*c is the normalied coordinate of the unit cells*/
				VMul(c,c,gap);
				/*c is coordinate mapped to the region*/
				VVSAdd(c,-0.5,region);
				/* make origin the center of region */
				for(j=0;j<2;j++)
				{
					mol[n].r=c;
					if(j==1) VVSAdd(mol[n].r,0.5,gap);
					++n;
				}
			}
		}
	}

}
