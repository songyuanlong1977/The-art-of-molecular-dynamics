#ifndef VARIABLE
#define VARIABLE
#include "types.h"
#include "macros.h"
extern Mol *mol;
extern VecR region ,  vSum;
/*region: region size*/

extern VecI initUcell;
/*size of unit cell array for initial state*/
extern real deltaT, density, rCut, temperature, timeNow, uSum, velMag,  vvSum;
extern Prop kinEnergy ,totEnergy;
/*kinEnergy, the kinetic energy*/

/*uSum, the summed potential Energy*/
/*virSum, virial sum. WHAT IS THIS?*/
/*vSum: velocity sum*/
/*vvSUM, velocity squared sum*/
/*density, */
/*velMag,initial velocity value*/
extern int moreCycles, nMol, stepAvg, stepCount, stepEquil, stepLimit;
extern int randSeed;
extern VecI cells;
extern int *cellList; 
extern real dispHi, rNebrShell;
extern real *histVel, rangeVel;
extern int *nebrTab, nebrNow, nebrTabFac,nebrTabLen, nebrTabMax;
/*nebrTab: storage for neighbor list
nebrNow: neighbor-list refresh due
nebrTabMax: maximum neighbor-list length
nebrTabLen: neighbor-list length
nebrTabFac: used to determine nebrTabMax
*/
extern real virSum;
extern Prop pressure;
extern real kinEnInitSum;
extern int stepInitlzTemp;

extern int countVel,limitVel,sizeHistVel,stepVel;
/*nMol, the total number of molecules in clcuded in the system*/
extern NameList nameList[10];
extern char *fileNameR[] , fileName[5][20];
extern char *progId  ;
extern char *errorMsg[]  ;
#endif
