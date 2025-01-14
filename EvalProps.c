#include "head.h"
void EvalProps()
/*evaluate properties
compute the velocity and velocity-squared sums
compute the instantaneous energy and pressure
*/
{
	real vv;
	real vvMax;
	vvMax=0;
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
		}
		/*add the squared velocity to vvSum*/
		kinEnergy.val = 0.5 * vvSum / nMol;
	  	totEnergy.val = kinEnergy.val + uSum / nMol;
		pressure.val = density * (vvSum + virSum) / (nMol * NDIM);
	
}
