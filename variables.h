#ifndef VARIABLE
#define VARIABLE
#include "types.h"
#include "macros.h"
extern Mol *mol;
extern VecR region ,  vSum;
/*region: region size*/

extern VecI initUcell;
/*size of unit cell array for initial state*/
extern Prop kinEnergy ,pressure ,totEnergy;
/*kinEnergy, the kinetic energy*/

extern real deltaT, density, rCut, temperature, timeNow, uSum, velMag, virSum, vvSum;
/*uSum, the summed potential Energy*/
/*virSum, virial sum. WHAT IS THIS?*/
/*vSum: velocity sum*/
/*vvSUM, velocity squared sum*/
/*density, */
/*velMag,initial velocity value*/

extern int moreCycles, nMol, stepAvg, stepCount, stepEquil, stepLimit;
/*nMol, the total number of molecules in clcuded in the system*/
extern NameList nameList[7];
#endif
