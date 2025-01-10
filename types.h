#ifndef TYPE
#define TYPE
#include "macros.h"

typedef double real;
typedef struct {real x, y;} VecR2;
typedef struct {real x, y, z;} VecR3;
typedef struct {int x, y;} VecI2;
typedef struct {int x, y, z;} VecI3;


#if NDIM==3
typedef VecR3 VecR;
typedef VecI3 VecI;
#endif

#if NDIM==2
typedef VecR2 VecR;
typedef VecI2 VecI;
#endif

typedef struct{
	VecR r,rv,ra;
} Mol; /*molecule, r, rv and ra represents, respectively, coordinate, velocity and accerlation*/
typedef struct {
real val, sum, sum2;
}Prop; /*property measurements, val:the acutual measured value; sum:sum accumulated val over several measurements; sum2: a sum of squares ;*/
typedef enum{N_I,N_R} VType; 
/*the type of the vector*/
typedef struct{
	char *vName;
	void *vPtr;
	VType vType;
	int vLen,vStatus;
} NameList;
#endif
