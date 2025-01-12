#ifndef TYPE
#define TYPE
#include "macros.h"

typedef double real;
typedef struct {real x, y;} VecR2;
typedef struct {real x, y, z;} VecR3;
typedef struct {int x, y;} VecI2;
typedef struct {int x, y, z;} VecI3;

enum {ERR_NONE, ERR_BOND_SNAPPED, ERR_CHECKPT_READ, ERR_CHECKPT_WRITE,
   ERR_COPY_BUFF_FULL, ERR_EMPTY_EVPOOL, ERR_MSG_BUFF_FULL,
   ERR_OUTSIDE_REGION, ERR_SNAP_READ, ERR_SNAP_WRITE,
   ERR_SUBDIV_UNFIN, ERR_TOO_MANY_CELLS, ERR_TOO_MANY_COPIES,
   ERR_TOO_MANY_LAYERS, ERR_TOO_MANY_LEVELS, ERR_TOO_MANY_MOLS,
   ERR_TOO_MANY_MOVES, ERR_TOO_MANY_NEBRS, ERR_TOO_MANY_REPLICAS};

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
	VecR r0,rv0,ra1,ra2;
	/*r0, rv0: r and rv one time step before*/
	/*ra1, and ra2, acceleration 1 and 2 time steps befoe ra*/
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
