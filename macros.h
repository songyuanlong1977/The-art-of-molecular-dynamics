
#ifndef MACROS
#define MACROS
#include <math.h>
#define Sqr(x) ((x)*(x))
#define Cube(x)	((x)*(x)*(x))
#define Max(a,b) ((a>b)?(a):(b))
#define Min(a,b) ((a<b)?(a):(b))
#define STEPLIMIT 100
#define DELTA 0.01
/*#define M_PI 3.1415926, is defined in c library <math.h>*/
#define NDIM 3 /*define the number of dimension*/

#if NDIM==3

#define VLinear(p,s) \
	(((p).z*(s).y+(p).y)*(s).x+(p).x)
	#define VProd(v) ((v).x*(v).y*(v).z)
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
#define VDot(v1,v2)	\
	((v1).x*(v2).x+(v1).y*(v2).y+(v1).z*(v2).z)
#define VScale(v,s)	\
	(v).x*=s,		\
	(v).y*=s,		\
	(v).z*=s
#define VSAdd(v1,v2,s3,v3) \
	(v1).x=(v2).x+(s3)*(v3).x, 	\
	(v1).y=(v2).y+(s3)*(v3).y, 	\
	(v1).z=(v2).z+(s3)*(v3).z
#define VSCopy(v2,s1,v1) \
	(v2).x=(s1)*(v1).x,	\
	(v2).y=(s1)*(v1).y,	\
	(v2).z=(s1)*(v1).z
#define VSet(v,sx,sy,sz) 	\
	(v).x=sx, 			\
	(v).y=sy, 			\
	(v).z=sz
#define VSetAll(v,s) 		VSet(v,s,s,s)
#define OFFSET_VALS                                           \
   { {0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {-1,1,0},            \
     {0,0,1}, {1,0,1}, {1,1,1}, {0,1,1}, {-1,1,1}, {-1,0,1},  \
     {-1,-1,1}, {0,-1,1}, {1,-1,1}                            \
   }

#define N_OFFSET  14
#define VCellWrapAll()                                      \
   {VCellWrap (x);                                          \
   VCellWrap (y);                                           \
   VCellWrap (z);}
#define VWrapAll(v)	\
	{VWrap(v,x);	\
	VWrap(v,y);		\
	VWrap(v,z);}
#endif
#if NDIM==2
#define VLinear(p,s) \
	((p).y*(s).x+(p).x)
	#define VProd(v) ((v).x*(v).y)
#define VAdd(v1,v2,v3) \
	(v1).x=(v2).x+(v3).x, 	\
	(v1).y=(v2).y+(v3).y
#define VSub(v1,v2,v3) \
	(v1).x=(v2).x-(v3).x, 	\
	(v1).y=(v2).y-(v3).y
#define VDiv(v1,v2,v3) \
	(v1).x=(v2).x/(v3).x, 	\
	(v1).y=(v2).y/(v3).y
#define VMul(v1,v2,v3) \
	(v1).x=(v2).x*(v3).x, 	\
	(v1).y=(v2).y*(v3).y
#define VDot(v1,v2)	\
	((v1).x*(v2).x+(v1).y*(v2).y)
#define VScale(v,s)	\
	(v).x*=s,		\
	(v).y*=s
#define VSAdd(v1,v2,s3,v3) \
	(v1).x=(v2).x+(s3)*(v3).x, 	\
	(v1).y=(v2).y+(s3)*(v3).y
#define VSCopy(v2,s1,v1) \
	(v2).x=(s1)*(v1).x,	\
	(v2).y=(s1)*(v1).y
#define VSet(v,sx,sy) 	\
	(v).x=sx, 			\
	(v).y=sy
#define VSetAll(v,s) 		VSet(v,s,s)
#define OFFSET_VALS                                         \
   {{0,0}, {1,0}, {1,1}, {0,1}, {-1,1}}
#define N_OFFSET  5
#define VCellWrapAll()                                      \
   {VCellWrap (x);                                          \
   VCellWrap (y);}
#define VWrapAll(v)	\
	{VWrap(v,x);	\
	VWrap(v,y);}
#endif

#define VZero(v)  VSetAll (v, 0)
#define VLenSq(v)  VDot (v, v)
#define VLen(v)  sqrt (VDot (v, v))
#define VVAdd(v1, v2)  VAdd (v1, v1, v2)
#define VVSub(v1, v2)  VSub (v1, v1, v2)
#define VVSAdd(v1, s2, v2) VSAdd (v1, v1, s2, v2)

#define VCellWrap(t)                                        \
   if (m2v.t >= cells.t) {                                  \
     m2v.t = 0;                                             \
     shift.t = region.t;                                    \
   } else if (m2v.t < 0) {                                  \
     m2v.t = cells.t - 1;                                   \
     shift.t = - region.t;                                  \
   }
#define VWrap(v,t) \
	if(v.t>=0.5*region.t) v.t-=region.t;	\
	else if(v.t<-0.5*region.t) v.t+=region.t
#define AllocMem(a,n,t) a=(t*)malloc((n)*sizeof(t))
#define DO_MOL for(n=0;n<nMol;n++)
#define DO_CELL(j,m) for(j=cellList[m];j>=0;j=cellList[j])
#define NameI(x) {#x,&x,N_I,sizeof(x)/sizeof(int)}
#define NameR(x) {#x,&x,N_R,sizeof(x)/sizeof(real)}
#define NP_I ((int *)(nameList[k].vPtr)+j)
#define NP_R ((real *)(nameList[k].vPtr)+j)
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
#define VCSum(v) ((v).x+(v).y)
#endif
