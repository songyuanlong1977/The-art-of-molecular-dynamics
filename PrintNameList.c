#include "head.h"
#include <stdio.h>
#include <string.h>
void PrintNameList(FILE *fp)
{
	int j,k;
	fprintf(fp,"NameList -- data\n");
	for(k=0;k<sizeof(nameList)/sizeof(NameList);k++)
	{
		fprintf(fp,"%s\t",nameList[k].vName);
		if(strlen(nameList[k].vName)<8) fprintf(fp,"\t");
		if(nameList[k].vStatus>0)
		{
			for(j=0;j<nameList[k].vLen;j++)
			{
				switch(nameList[k].vType)
				{
					case N_I:
						fprintf(fp,"%d ",*NP_I);
						break;
					case N_R:
						fprintf(fp,"%#g ",*NP_R);
						break;
				}
			}
		}
		switch (nameList[k].vStatus)
		{
			case 0:
				fprintf(fp,"** no data");break;
			case 1:
				break;
			case 2:
				fprintf(fp,"** missing data");break;
			case 3:
				fprintf(fp,"** extra data");break;
			case 4:
				fprintf(fp,"** multiply defined");break;
		}
			fprintf(fp,"\n");
	}
		fprintf(fp,"----\n");
}
