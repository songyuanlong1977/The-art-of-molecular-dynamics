#include "head.h"
#include <math.h>
void AccumProps(int icode)
/*collect the results of the measurements 
evaluates:
means and standard deviations upon requests
*/
{
	if(icode==0)
	{
		PropZero(totEnergy);
		PropZero(kinEnergy);
		PropZero(pressure);
	}
	else if(icode==1)
	{
		PropAccum(totEnergy);
		PropAccum(kinEnergy);
		PropAccum(pressure);
	}
	else if(icode==2)
	{
		PropAvg(totEnergy,stepAvg);
		PropAvg(kinEnergy,stepAvg);
		PropAvg(pressure,stepAvg);
	}

}
