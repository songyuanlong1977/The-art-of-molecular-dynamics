#include "head.h"
void EvalProps()
/*evaluate properties
compute the velocity and velocity-squared sums
compute the instantaneous energy and pressure
*/
{
	real vv;
	int n;
	VZero (vSum);
	/*zero the summed velocity*/
	vvSum=0.0; /*the velocity squared sum*/
	DO_MOL /*for each molecules*/
	{
		VVAdd(vSum, mol[n].rv);
		/*add the velocity to vSum*/
		vv=VLenSq(mol[n].rv);
		vvSum+=vv;
		/*add the squared velocity to vvSum*/
	}
	kinEnergy.val=0.5*vvSum/nMol;
	/*the averaged kinetic energy of each molecules, with unit molecule mass*/
	totEnergy.val=kinEnergy.val+uSum/nMol;
	/*the total energy*/
	pressure.val=density*(vvSum+virSum)/(nMol*NDIM);
	/*according to equation 2.3.9:
	PV=1/d(vvSum+virSum)
	density=nMol/V-->V=nMol/density
	-->P=density/(d*nMol)*(vvSum+virSum)
	virSum=force*|dr|,= 48*(|dr|^(-12)-1/2*|dr|^(-6)), 
	is updated from the function computeforces()*/
	

}
