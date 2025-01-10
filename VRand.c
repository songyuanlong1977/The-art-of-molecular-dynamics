#include "head.h"
#include <math.h>
#if NDIM==2
void VRand(VecR *p)
{
	real s;
	s=2.0*M_PI*RandR();
	p->x=cos(s);
	p->y=sin(s);
}
#endif

#if NDIM==3
void VRand (VecR *p)
{
  real s, x, y;

  s = 2.;
  while (s > 1.) {
    x = 2. * RandR () - 1.;
    y = 2. * RandR () - 1.;
    s = Sqr (x) + Sqr (y);
  }
  p->z = 1. - 2. * s;
  s = 2. * sqrt (1. - s);
  p->x = s * x;
  p->y = s * y;
}
#endif
