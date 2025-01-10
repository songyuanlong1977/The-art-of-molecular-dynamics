#include "head.h"
#include <stdio.h>
#include <stdlib.h>
char *errorMsg[] = {"", "bond snapped", "read checkpoint data",
   "write checkpoint data", "copy buffer full", "empty event pool",
   "message buffer full", "outside region", "read snap data",
   "write snap data", "subdivision unfinished", "too many cells",
   "too many copied mols", "too many layers", "too many levels",
   "too many mols", "too many moved mols", "too many neighbors",
   "too many replicas"};
void ErrExit(int code)
{
	printf("Error: %s\n",errorMsg[code]);
	exit(0);
}
