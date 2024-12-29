#include "head.h"
void SetupJob(void)
{
	AllocArrays();
	stepCount=0;
	InitCoords();
	InitVels();
	InitAccels();
	AccumProps(0);
}
 
