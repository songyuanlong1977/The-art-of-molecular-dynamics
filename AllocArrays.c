#include "head.h"
#include <stdlib.h>
void AllocArrays(void)
{
	AllocMem(mol,nMol,Mol);
	AllocMem(cellList, VProd(cells)+nMol, int);
	AllocMem(nebrTab, 2*nebrTabMax,int);
}

