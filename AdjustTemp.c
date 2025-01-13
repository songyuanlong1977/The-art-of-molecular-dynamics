#include "head.h"
void AdjustTemp()
{
	real vFac;
	int n;
	vvSum=0;
	DO_MOL vvSum+=VLenSq(mol[n].rv);
	vFac=velMag/sqrt(vvSum/nMol);
	DO_MOL VScale (mol[n].rv,vFac);
}
