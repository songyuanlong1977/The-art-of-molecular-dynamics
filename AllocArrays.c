#include "head.h"
#include <stdlib.h>
void AllocArrays(void)
{
	AllocMem(mol,nMol,Mol);
	AllocMem(cellList, VProd(cells)+nMol, int);
}

