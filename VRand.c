#include "head.h"
#include <math.h>
void VRand(VecR *p)
{
	real s;
	s=2.0*M_PI*RandR();
	p->x=cos(s);
	p->y=sin(s);
}
