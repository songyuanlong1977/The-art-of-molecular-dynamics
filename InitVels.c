#include "head.h"
void InitVels(void)
{
	int n;
	VZero (vSum);
	DO_MOL 
	{
		VRand(&mol[n].rv);
		/*randamrize the direction of the vector?*/
		VScale(mol[n].rv,velMag);
		/*set the vector with intial magnitude*/
		VVAdd(vSum, mol[n].rv);
	}
	DO_MOL VVSAdd(mol[n].rv, -1.0/nMol, vSum);
	/*adjust the velocity so that the velocities are adjusted to ensure tht the center of mass is stationary. HOW?*/
	/*after the upperstep, the vSum,if recalculated, the velocity of the system as a whole is zero. */
}
