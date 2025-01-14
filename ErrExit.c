#include "head.h"
#include <stdio.h>
#include <stdlib.h>
void ErrExit(int code)
{
	printf("Error: %s\n",errorMsg[code]);
	exit(0);
}
