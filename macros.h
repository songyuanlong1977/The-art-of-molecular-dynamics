
#ifndef MACROS
#define MACROS
#include <math.h>
#define Sqr(x) ((x)*(x))
#define Cube(x)	((x)*(x)*(x))
#define Max(a,b) ((a>b)?(a):(b))
#define Min(a,b) ((a<b)?(a):(b))
#define VAdd(v1,v2,v3) \
	(v1).x=(v2).x+(v3).x, 	\
	(v1).y=(v2).y+(v3).y
#define VVAdd(v1,v2) \
	(v1).x=(v1).x+(v2).x, 	\
	(v1).y=(v1).y+(v2).y
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
#define VProd(v) ((v).x*(v).y)
#define VSet(v,sx,sy) 	\
	(v).x=sx, 			\
	(v).y=sy
#define VSetAll(v,s) 		VSet(v,s,s)
#define VZero(v)			VSetAll(v,0)
#define VVSAdd(v1,s2,v2)	VSAdd(v1,v1,s2,v2)
#define VLenSq(v)			VDot(v,v)
#define VLen(v)				sqrt(VDot(v,v))
#define STEPLIMIT 100
#define DELTA 0.01
#define NDIM 2 /*define the number of dimension*/
/*#define M_PI 3.1415926, is defined in c library <math.h>*/
#define VWrap(v,t) \
	if(v.t>=0.5*region.t) v.t-=region.t;	\
	else if(v.t<-0.5*region.t) v.t+=region.t
#define VWrapAll(v)	\
	{VWrap(v,x);	\
	VWrap(v,y);}
#define AllocMem(a,n,t) a=(t*)malloc((n)*sizeof(t))
#define DO_MOL for(n=0;n<nMol;n++)
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
