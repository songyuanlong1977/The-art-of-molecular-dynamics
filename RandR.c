/*a random number generation, that will producing uniformly distributed values in (0,1)*/
#include "head.h"
#define IADD 453806245
#define IMUL 314159269
#define MASK 2147483647
#define SCALE 0.4656612873e-9
int randSeedP=17;
real RandR()
{
	randSeedP=(randSeedP*IMUL+IADD)&MASK;
	return (randSeedP*SCALE);
}
