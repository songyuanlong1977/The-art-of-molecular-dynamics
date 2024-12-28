#ifndef TYPE
#define TYPE
typedef double real;
typedef struct {
	real x,y;
} VecR; /*real type vector */
typedef struct{
	int x,y;
}VecI; /*integer vector*/
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
