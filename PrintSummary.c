#include "head.h"
#include <stdio.h>
void PrintSummary(FILE *fp)
{
	if (stepCount==stepAvg) 
	{
		
			fprintf(fp,
			"steps\ttime\tv\t<E>\tstd(E>)\t<EK>\tstd<Ek>\t<P>\tstd<P>\t\n");
	}
	fprintf(fp,
	"%5d %8.4f %7.4f %7.4f %7.4f %7.4f %7.4f %7.4f %7.4f\n",
	stepCount,
	timeNow,
	VCSum(vSum)/nMol,
	PropEst(totEnergy),
	PropEst(kinEnergy),
	PropEst(pressure)
	);
}
