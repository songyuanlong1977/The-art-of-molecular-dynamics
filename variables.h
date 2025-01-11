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
extern real *histVel, rangeVel;

extern int moreCycles, nMol, stepAvg, stepCount, stepEquil, stepLimit;
extern int countVel,limitVel,sizeHistVel,stepVel;
/*nMol, the total number of molecules in clcuded in the system*/
extern NameList nameList[13];
/*added for the list of cell list*/
extern VecI cells;
/*size of the cells*/
extern int *cellList; 
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
#endif
