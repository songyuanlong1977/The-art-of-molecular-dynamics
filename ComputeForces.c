#include "head.h"
void ComputeForces()
{
	VecR dr;
	real fcVal, rr, rrCut, rri, rri3;
	int j1,j2, n;
	rrCut=Sqr(rCut);/*rrCut is the square of rCut*/
	DO_MOL VZero(mol[n].ra);
	uSum=0;  	/* */
	virSum=0; 	/* */
	for (j1=0;j1<nMol-1;j1++)
	{
		for(j2=j1+1;j2<nMol;j2++)
		{
		VSub(dr,mol[j1].r,mol[j2].r); /*dr is now the vector pointing from j2 to j1 */
		VWrapAll(dr); /*correct the possible  wraparound problem of dr*/
		rr=VLenSq(dr); /*rr is the square of |dr|*/
		if(rr<rrCut)
			{
				rri=1./rr; /*rri=|dr|^(-2)*/
				rri3=Cube(rri); /*rri3=|dr|^(-6)*/
				fcVal=48.0*rri3*rri*(rri3-0.5);
				/*the force value=48(|dr|^(-14)-1/2*|dr|^(-8)*/
				VVSAdd(mol[j1].ra,fcVal,dr);
				VVSAdd(mol[j2].ra,-fcVal,dr);
				/*the summed acceleration of j1=ra+fcVal.dr*/
				/*the summed accelatation of j2 is identical to j1 except the oppostion of the direction*/
				uSum+=4.0*rri3*(rri3-1.0)+1.0; 
				/*the summed potential energy=4*(|dr|^(-12)-|dr|^(-6))+1.0; 
				is illustrated in equation 2.2.9, apart from the ' +1.0'				WHY?*/
				virSum+=fcVal*rr;
				/*virSum, the virial sum+=48*(|dr|^(-12)-1/2*|dr|^(-6))*/
				}
			}
		}
}
	

