
#ifndef MACROS
#define MACROS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>

#define NDIM 3
#define CHAR_MINUS  '-'
#define CHAR_ZERO   '0'

#define MOL_LIMIT  10000000

#define MAT(a, n, i, j)  (a)[(i) + n * (j)]

#define AllocMem(a,n,t) a=(t*)malloc((n)*sizeof(t))
#define AllocMem2(a, n1, n2, t)                             \
   AllocMem (a, n1, t *);                                   \
   AllocMem (a[0], (n1) * (n2), t);                         \
   for (k = 1; k < n1; k ++) a[k] = a[k - 1] + n2;

#define MAX_MPEX_ORD  2
#define I(i, j)  ((i) * ((i) + 1) / 2 + (j))
#define c(i, j)  c[I(i, j)]
#define s(i, j)  s[I(i, j)]

#define DO_MOL for(n=0;n<nMol;n++)
#define DO_CELL(j,m) for(j=cellList[m];j>=0;j=cellList[j])
#define VWrap(v,t) \
	while(v.t>=0.5*region.t) v.t-=region.t;	\
	while(v.t<-0.5*region.t) v.t+=region.t

#define VShift(v, t)                                        \
   if (v.t >= 0.5 * region.t)      shift.t -= region.t;     \
   else if (v.t < -0.5 * region.t) shift.t += region.t
#define VShiftWrap(v, t)                                    \
   if (v.t >= 0.5 * region.t) {                             \
     shift.t -= region.t;                                   \
     v.t -= region.t;                                       \
   } else if (v.t < -0.5 * region.t) {                      \
     shift.t += region.t;                                   \
     v.t += region.t;                                       \
   }
#define VCellWrap(t)                                        \
   if (m2v.t >= cells.t) {                                  \
     m2v.t = 0;                                             \
     shift.t = region.t;                                    \
   } else if (m2v.t < 0) {                                  \
     m2v.t = cells.t - 1;                                   \
     shift.t = - region.t;                                  \
   }

#if NDIM==2
#define VWrapAll(v)	\
	{VWrap(v,x);	\
	VWrap(v,y);}
#define VShiftAll(v)                                        \
   {VShift (v, x);                                          \
   VShift (v, y);}
#define VCellWrapAll()                                      \
   {VCellWrap (x);                                          \
   VCellWrap (y);}
#define OFFSET_VALS                                         \
   {{0,0}, {1,0}, {1,1}, {0,1}, {-1,1}}
#define N_OFFSET  5
#define VCopy(v1, v2)                                       \
   (v1).x = (v2).x,                                         \
   (v1).y = (v2).y
#define VSCopy(v2,s1,v1) \
	(v2).x=(s1)*(v1).x,	\
	(v2).y=(s1)*(v1).y
#define VLinear(p,s) \
	((p).y*(s).x+(p).x)
#define VAdd(v1,v2,v3) \
	(v1).x=(v2).x+(v3).x, 	\
	(v1).y=(v2).y+(v3).y
#define VSAdd(v1,v2,s3,v3) \
	(v1).x=(v2).x+(s3)*(v3).x, 	\
	(v1).y=(v2).y+(s3)*(v3).y
#define VSSAdd(v1, s2, v2, s3, v3)                          \
   (v1).x = (s2) * (v2).x + (s3) * (v3).x,                  \
   (v1).y = (s2) * (v2).y + (s3) * (v3).y
#define VSub(v1,v2,v3) \
	(v1).x=(v2).x-(v3).x, 	\
	(v1).y=(v2).y-(v3).y
#define VDiv(v1,v2,v3) \
	(v1).x=(v2).x/(v3).x, 	\
	(v1).y=(v2).y/(v3).y
#define VMul(v1,v2,v3) \
	(v1).x=(v2).x*(v3).x, 	\
	(v1).y=(v2).y*(v3).y
#define VScale(v,s)	\
	(v).x*=s,		\
	(v).y*=s
#define VSet(v,sx,sy) 	\
	(v).x=sx, 			\
	(v).y=sy
#define VSetAll(v,s) 		VSet(v,s,s)
#define VDot(v1, v2)                                        \
   ((v1).x * (v2).x + (v1).y * (v2).y)
#define VWDot(v1, v2, v3)                                   \
   ((v1).x * (v2).x * (v3).x + (v1).y * (v2).y * (v3).y)
#define VCross(v1, v2)                                      \
   ((v1).x * (v2).y - (v1).y * (v2).x)
#define VProd(v)                                            \
   ((v).x * (v).y)
#define VGe(v1, v2)                                         \
   ((v1).x >= (v2).x && (v1).y >= (v2).y)
#define VLt(v1, v2)                                         \
   ((v1).x < (v2).x && (v1).y < (v2).y)
#define VAddCon(v1, v2, s)                                  \
   (v1).x = (v2).x + (s),                                   \
   (v1).y = (v2).y + (s)
#define VComp(v, k)                                         \
   *((k == 0) ? &(v).x : &(v).y)
#define VToLin(a, n, v)                                     \
   a[(n) + 0] = (v).x,                                      \
   a[(n) + 1] = (v).y
#define VFromLin(v, a, n)                                   \
   VSet (v, a[(n) + 0], a[(n) + 1])
#define VCSum(v)                                            \
   ((v).x + (v).y)
#endif


#if NDIM==3
#define VWrapAll(v)	\
	{VWrap(v,x);	\
	VWrap(v,y);		\
	VWrap(v,z);}
#define VShiftAll(v)                                        \
   {VShift (v, x);                                          \
   VShift (v, y);                                           \
   VShift (v, z);}
#define VCellWrapAll()                                      \
   {VCellWrap (x);                                          \
   VCellWrap (y);                                           \
   VCellWrap (z);}
#define OFFSET_VALS                                           \
   { {0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {-1,1,0},            \
     {0,0,1}, {1,0,1}, {1,1,1}, {0,1,1}, {-1,1,1}, {-1,0,1},  \
     {-1,-1,1}, {0,-1,1}, {1,-1,1}                            \
   }
#define N_OFFSET  14
#define VLinear(p,s) \
	(((p).z*(s).y+(p).y)*(s).x+(p).x)
#define VAdd(v1,v2,v3) \
	(v1).x=(v2).x+(v3).x, 	\
	(v1).y=(v2).y+(v3).y, 	\
	(v1).z=(v2).z+(v3).z
#define VSub(v1,v2,v3) \
	(v1).x=(v2).x-(v3).x, 	\
	(v1).y=(v2).y-(v3).y, 	\
	(v1).z=(v2).z-(v3).z
#define VDiv(v1,v2,v3) \
	(v1).x=(v2).x/(v3).x, 	\
	(v1).y=(v2).y/(v3).y, 	\
	(v1).z=(v2).z/(v3).z
#define VMul(v1,v2,v3) \
	(v1).x=(v2).x*(v3).x, 	\
	(v1).y=(v2).y*(v3).y, 	\
	(v1).z=(v2).z*(v3).z
#define VScale(v,s)	\
	(v).x*=s,		\
	(v).y*=s,		\
	(v).z*=s
#define VSAdd(v1,v2,s3,v3) \
	(v1).x=(v2).x+(s3)*(v3).x, 	\
	(v1).y=(v2).y+(s3)*(v3).y, 	\
	(v1).z=(v2).z+(s3)*(v3).z
#define VSSAdd(v1, s2, v2, s3, v3)                          \
   (v1).x = (s2) * (v2).x + (s3) * (v3).x,                  \
   (v1).y = (s2) * (v2).y + (s3) * (v3).y,                  \
   (v1).z = (s2) * (v2).z + (s3) * (v3).z
#define VDot(v1, v2)                                        \
   ((v1).x * (v2).x + (v1).y * (v2).y + (v1).z * (v2).z)
#define VWDot(v1, v2, v3)                                   \
   ((v1).x * (v2).x * (v3).x + (v1).y * (v2).y * (v3).y +   \
   (v1).z * (v2).z * (v3).z)
#define VCross(v1, v2, v3)                                  \
   (v1).x = (v2).y * (v3).z - (v2).z * (v3).y,              \
   (v1).y = (v2).z * (v3).x - (v2).x * (v3).z,              \
   (v1).z = (v2).x * (v3).y - (v2).y * (v3).x
#define MVMul(v1, m, v2)                                         \
   (v1).x = (m)[0] * (v2).x + (m)[3] * (v2).y + (m)[6] * (v2).z, \
   (v1).y = (m)[1] * (v2).x + (m)[4] * (v2).y + (m)[7] * (v2).z, \
   (v1).z = (m)[2] * (v2).x + (m)[5] * (v2).y + (m)[8] * (v2).z
#define MVMulT(v1, m, v2)                                        \
   (v1).x = (m)[0] * (v2).x + (m)[1] * (v2).y + (m)[2] * (v2).z, \
   (v1).y = (m)[3] * (v2).x + (m)[4] * (v2).y + (m)[5] * (v2).z, \
   (v1).z = (m)[6] * (v2).x + (m)[7] * (v2).y + (m)[8] * (v2).z
#define VProd(v)                                            \
   ((v).x * (v).y * (v).z)
#define VGe(v1, v2)                                         \
   ((v1).x >= (v2).x && (v1).y >= (v2).y && (v1).z >= (v2).z)
#define VLt(v1, v2)                                         \
   ((v1).x < (v2).x && (v1).y < (v2).y && (v1).z < (v2).z)
#define VCopy(v1, v2)                                       \
   (v1).x = (v2).x,                                         \
   (v1).y = (v2).y,                                         \
   (v1).z = (v2).z
#define VSCopy(v2,s1,v1) \
	(v2).x=(s1)*(v1).x,	\
	(v2).y=(s1)*(v1).y,	\
	(v2).z=(s1)*(v1).z
#define VSet(v,sx,sy,sz) 	\
	(v).x=sx, 			\
	(v).y=sy, 			\
	(v).z=sz
#define VSetAll(v,s) 		VSet(v,s,s,s)
#define VAddCon(v1, v2, s)                                  \
   (v1).x = (v2).x + (s),                                   \
   (v1).y = (v2).y + (s),                                   \
   (v1).z = (v2).z + (s)
#define VComp(v, k)                                         \
   *((k == 0) ? &(v).x : ((k == 1) ? &(v).y : &(v).z))
#define VToLin(a, n, v)                                     \
   a[(n) + 0] = (v).x,                                      \
   a[(n) + 1] = (v).y,                                      \
   a[(n) + 2] = (v).z
#define VFromLin(v, a, n)                                   \
   VSet (v, a[(n) + 0], a[(n) + 1], a[(n) + 2])
#define VCSum(v)                                            \
   ((v).x + (v).y + (v).z)
#endif


#define PropZero(v) \
	v.sum=0.,	\
	v.sum2=0.
/*initialize the accumulated sums*/
#define PropAccum(v) 	\
	v.sum+=v.val,	\
	v.sum2+=Sqr(v.val)
/*accuumlate the current values*/
#define PropAvg(v,n)	\
	v.sum/=n,		\
	v.sum2=sqrt(Max(v.sum2/n-Sqr(v.sum),0.))
/*produce the final averaged estimates*/
#define PropEst(v) v.sum, v.sum2
#define NameVal(x)                                          \
   if (! strncmp (bp, #x, strlen (#x))) {                   \
     bp += strlen (#x);                                     \
     x = strtod (bp, &bp);                                  \
   }

#define NHIST  (NDIM + 2)

#define ReadF(x)       fread  (&x, sizeof (x), 1, fp)
#define WriteF(x)      fwrite (&x, sizeof (x), 1, fp)
#define ReadFN(x, n)   fread  (x, sizeof (x[0]), n, fp)
#define WriteFN(x, n)  fwrite (x, sizeof (x[0]), n, fp)


#define Sqr(x) ((x)*(x))
#define Cube(x)	((x)*(x)*(x))
#define Sgn(x, y)  (((y) >= 0) ? (x) : (- (x)))
#define IsEven(x)  ((x) & ~1)
#define IsOdd(x)   ((x) & 1)
#define Nint(x)                                             \
   (((x) < 0.) ? (- (int) (0.5 - (x))): ((int) (0.5 + (x))))
#define Max(a,b) ((a>b)?(a):(b))
#define Min(a,b) ((a<b)?(a):(b))
#define Min3(x1, x2, x3) \
   (((x1) < (x2)) ? (((x1) < (x3)) ? (x1) : (x3)) :         \
                    (((x2) < (x3)) ? (x2) : (x3)))
#define Max3(x1, x2, x3) \
   (((x1) > (x2)) ? (((x1) > (x3)) ? (x1) : (x3)) :         \
                    (((x2) > (x3)) ? (x2) : (x3)))
#define Clamp(x, lo, hi)                                    \
   (((x) >= (lo) && (x) <= (hi)) ? (x) :                    \
   (((x) < (lo)) ? (lo) : (hi)))


#define STEPLIMIT 100
#define DELTA 0.01
/*#define M_PI 3.1415926, is defined in c library <math.h>*/


#define VZero(v)  VSetAll (v, 0)
#define VLenSq(v)  VDot (v, v)
#define VWLenSq(v1, v2)  VWDot(v1, v2, v2)
#define VLen(v)  sqrt (VDot (v, v))
#define VVAdd(v1, v2)  VAdd (v1, v1, v2)
#define VVSub(v1, v2)  VSub (v1, v1, v2)
#define VVSAdd(v1, s2, v2) VSAdd (v1, v1, s2, v2)
#define VInterp(v1, s2, v2, v3)                             \
   VSSAdd (v1, s2, v2, 1. - (s2), v3)

#define QSet(q, s1, s2, s3, s4)                             \
   (q).u1 = s1,                                             \
   (q).u2 = s2,                                             \
   (q).u3 = s3,                                             \
   (q).u4 = s4
#define QZero(q)  QSet (q, 0, 0, 0, 0)
#define QScale(q, s)                                        \
   (q).u1 *= s,                                             \
   (q).u2 *= s,                                             \
   (q).u3 *= s,                                             \
   (q).u4 *= s
#define QSAdd(q1, q2, s3, q3)                               \
   (q1).u1 = (q2).u1 + (s3) * (q3).u1,                      \
   (q1).u2 = (q2).u2 + (s3) * (q3).u2,                      \
   (q1).u3 = (q2).u3 + (s3) * (q3).u3,                      \
   (q1).u4 = (q2).u4 + (s3) * (q3).u4
#define QLenSq(q)                                           \
   (Sqr ((q).u1) + Sqr ((q).u2) + Sqr ((q).u3) +            \
   Sqr ((q).u4))
#define QMul(q1, q2, q3)                                    \
   (q1).u1 =   (q2).u4 * (q3).u1 - (q2).u3 * (q3).u2 +      \
               (q2).u2 * (q3).u3 + (q2).u1 * (q3).u4,       \
   (q1).u2 =   (q2).u3 * (q3).u1 + (q2).u4 * (q3).u2 -      \
               (q2).u1 * (q3).u3 + (q2).u2 * (q3).u4,       \
   (q1).u3 = - (q2).u2 * (q3).u1 + (q2).u1 * (q3).u2 +      \
               (q2).u4 * (q3).u3 + (q2).u3 * (q3).u4,       \
   (q1).u4 = - (q2).u1 * (q3).u1 - (q2).u2 * (q3).u2 -      \
               (q2).u3 * (q3).u3 + (q2).u4 * (q3).u4

#define CSet(a, x, y)                                       \
   a.R = x,                                                 \
   a.I = y
#define CAdd(a, b, c)                                       \
   a.R = b.R + c.R,                                         \
   a.I = b.I + c.I
#define CSub(a, b, c)                                       \
   a.R = b.R - c.R,                                         \
   a.I = b.I - c.I
#define CMul(a, b, c)                                       \
  a.R = b.R * c.R - b.I * c.I,                              \
  a.I = b.R * c.I + b.I * c.R
  
#define NameI(x) {#x,&x,N_I,sizeof(x)/sizeof(int)}
#define NameR(x) {#x,&x,N_R,sizeof(x)/sizeof(real)}

#define ValI(x)  {&x, N_I, sizeof (x) / sizeof (int)}
#define ValR(x)  {&x, N_R, sizeof (x) / sizeof (real)}

#define NP_I ((int *)(nameList[k].vPtr)+j)
#define NP_R  ((real *) (nameList[k].vPtr) + j)
#define PCR4(r, ro, v, a, a1, a2, t)                        \
   r.t = ro.t + deltaT * v.t +                              \
   wr * (cr[0] * a.t + cr[1] * a1.t + cr[2] * a2.t)
#define PCV4(r, ro, v, a, a1, a2, t)                        \
   v.t = (r.t - ro.t) / deltaT +                            \
   wv * (cv[0] * a.t + cv[1] * a1.t + cv[2] * a2.t)

#define PR(t)                                               \
   PCR4 (mol[n].r, mol[n].r, mol[n].rv,                     \
   mol[n].ra, mol[n].ra1, mol[n].ra2, t)
#define PRV(t)                                              \
   PCV4 (mol[n].r, mol[n].ro, mol[n].rv,                    \
   mol[n].ra, mol[n].ra1, mol[n].ra2, t)
#define CR(t)                                               \
   PCR4 (mol[n].r, mol[n].ro, mol[n].rvo,                   \
   mol[n].ra, mol[n].ra1, mol[n].ra2, t)
#define CRV(t)                                              \
   PCV4 (mol[n].r, mol[n].ro, mol[n].rv,                    \
   mol[n].ra, mol[n].ra1, mol[n].ra2, t)
#endif
