#include "head.h"
void InitAccels(void)
{
	int n; 
	DO_MOL
	{
		VZero(mol[n].ra);
		VZero(mol[n].ra1);
		VZero(mol[n].ra2);
	}
}
