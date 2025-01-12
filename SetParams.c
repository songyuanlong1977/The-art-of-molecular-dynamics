#include <math.h>
#include "head.h"
void SetParams(void)
{
	rCut=pow(2.0,1.0/6.0);
	VSCopy(region, 1./pow(density/4., 1./3.),initUcell);
	/*
	set up the region size according to the density and the initUcell
	the coordinartes was arranged as the FCC (face centered cubic) pattern
	*/
	nMol=4*VProd(initUcell);
	/*
	determine the number of total molecules
	*/
	velMag=sqrt(NDIM*(1.-1./nMol)*temperature);
	/*the amplitude of the velocity was determined by 
	the dimension of the system,
	the number of molecules,
	and the temperature of the system*/
	/*the equation the describe the relation between nMol, NDIM, and v
	is described with the equation 2.2.10:
	T=(vi)^2/d; vi should be sqrt(T*d) why in the above calculation
	it is vi=sqrt(T*d-1/n*T*d), thus one molecule is removed from the 
	contribution! WHY?*/
	VSCopy(cells, 1./(rCut+rNebrShell), region);
	nebrTabMax=nebrTabFac*nMol;
	/*set the size of the cell array*/
    /*each cell has the edge length of ~ rCut*/
}
