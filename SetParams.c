#include <math.h>
#include "head.h"
void SetParams(void)
{
	rCut=pow(2.0,1.0/6.0);
	VSCopy(region,1./sqrt(density), initUcell);
	/*set the size of region*/
	/*if density=number of mols in unit area in 2D, for example 64
	then, sqrt(density) is number of mols in unit length, 8
	initUcell is the size of cell arrays, for example 16*16
	the size of region is set as: 2*2.  [16/8=2] 
	if we come back, the total included cells in the area is : 
	2*2*64=16*16*/
	nMol=VProd(initUcell);
	/*calculate and set the number of molecules*/
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

	
}
