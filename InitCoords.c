#include "head.h"
void InitCoords(void)
{
/*face-centered cubic (FCC) initialization*/
/*with the option of unequal edges. There are four atoms per unit cell, and the system is centered at the origin*/
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
			/*	VSet(c,nx+0.5,ny+0.5,nz+0.5);*/
				VSet(c,nx+0.25,ny+0.25,nz+0.25);
				/*c is the normalied coordinate of the unit cells*/
				VMul(c,c,gap);
				/*c is coordinate mapped to the region*/
				VVSAdd(c,-0.5,region);
				/* make origin the center of region */
				for(j=0;j<4;j++)
				{
					mol[n].r=c;
					if(j!=3) /* if j!=3*/
					{
						if(j!=0) mol[n].r.x+=0.5*gap.x;
						if(j!=1) mol[n].r.y+=0.5*gap.y;
						if(j!=2) mol[n].r.z+=0.5*gap.z;
					}
					++n; /*if j==3, ++n*/
				}
				/*
				as an simplest example , suppose  nz=ny=nx=0
				j=0--m[0].r=c--m[0].r.y=m[0].r.y+0.5*gap.y--m[0].r.z=m[0].r.z+0.5*gap.z
				j=1--m[1].r=c--m[1].r.x=m[1].r.x+0.5*gap.x--m[1].r.z=m[1].r.z+0.5*gap.z
				j=2--m[2].r=c--m[2].r.x=m[2].r.x+0.5.gap.x--m[2].r.y=m[2].r.y+0.5.gap.y
				j=3--m[3].r=c
				therefore, after the 1st inner round, before nz was increased, the coordinate of m[0]-m[4] is:
				m[0].r={c.x, c.y+0.5g, c.z+0.5g}
				m[1].r={c.x+0.5g, c.y, c.z+0.5g}
				m[2].r={c.x+0.5g, c.y+0.5g, c.z}
				m[3].r={c.x,c.y,c.z}
				*/
			}
		}
	}

}
