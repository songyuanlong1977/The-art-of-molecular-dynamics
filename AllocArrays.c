#include "head.h"
#include <stdlib.h>
void AllocArrays(void)
{
	AllocMem(mol,nMol,Mol);
	AllocMem(histVel,sizeHistVel,real);
	/*allocate memory for the histogram array*/
	AllocMem(cellList, VProd(cells)+nMol, int);
	/*cellList point to cells.x*cells.y+nMol of int*/
	AllocMem(nebrTab, 2*nebrTabMax,int);
}

