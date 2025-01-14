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
extern VecI cells;
extern int *cellList; 
extern real virSum;
extern Prop pressure;
extern real *histVel, rangeVel;
extern real kinEnInitSum;
extern int stepInitlzTemp;

extern NameList nameList[8];
extern int countVel,limitVel,sizeHistVel,stepVel;
extern real dispHi, rNebrShell;
/*rNebrShell, rn
dispHi: accumulated maximum displacement*/
extern int *nebrTab, nebrNow, nebrTabFac,nebrTabLen, nebrTabMax;
/*nebrTab: storage for neighbor list
nebrNow: neighbor-list refresh due
nebrTabMax: maximum neighbor-list length
nebrTabLen: neighbor-list length
nebrTabFac: used to determine nebrTabMax
*/
extern char *fileNameR[] , fileName[5][20];
extern char *progId  ;
extern char *errorMsg[]  ;
#endif
