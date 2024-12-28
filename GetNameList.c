#include "head.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int GetNameList(int argc,char **argv)
{
	int id,j,k,match,ok;
	char buff[80], *token;
	FILE *fp;
	strcpy(buff,argv[0]); /*copy the file name*/
	strcat(buff,".in"); 	/*add file extension .in*/
	if ((fp=fopen(buff,"r"))==0) return (0); 
	/*if failed to open the file, exit*/
	for (k=0;k<sizeof(nameList)/sizeof(NameList);k++)
		nameList[k].vStatus=0;
	/*nameList is an external variable,
	initialize the record vStatus to zero
	*/
	ok=1;
	while(1)
	{
		fgets(buff,80,fp);
		/*read 80 chars from fp, and keep in buff*/
		if (feof(fp)) break; /*exit if the end of the file reached*/
		token=strtok(buff," \t\n");
		/*split the string in buff by space, tab or newline
		token keep the first token encounted in the string
		token will be NULL if no tokens were found
		*/
		if (!token) break; /*if no token was found, exit the program*/
		match=0;
		for(k=0;k<sizeof(nameList)/sizeof(NameList);k++)
		{
			/*process the nameList*/
			if(strcmp(token,nameList[k].vName)==0)
			/*if toke is the vName*/
			{
				match=1; /*found proper tokens*/
				if(nameList[k].vStatus==0) /*the record has not been processed */
				{
					nameList[k].vStatus=1;/*mark as processed*/
					for (j=0;j<nameList[k].vLen;j++)
					{
						token=strtok(NULL," ,\t\n");
						if (token) /*if token is not NULL*/
						/*now token is a void type pointer*/
						{
							switch(nameList[k].vType)
								{
									case N_I:
										*NP_I=atol(token);
										/*assign value long type integer to nameList[k].vPtr*/
										break;
										/*convert the pointer to proper type*/
									case N_R:
										*NP_R=atof(token);
										break;
								}
						}
						else /*if token is NULL*/
						{
							nameList[k].vStatus=2;
							ok=0;
						}
					}
					/*the upper code process the pointer*/
					token=strtok(NULL," ,\t\n");
					if(token)
					{
						nameList[k].vStatus=3;
						ok=0;
					}
						break;
				}
				else
				{
					nameList[k].vStatus=4;
					ok=0;
				}
			}
		}
		if (!match) ok=0;
	}
	fclose(fp);
	for(k=0;k<sizeof(nameList)/sizeof(NameList);k++)
	{
		if(nameList[k].vStatus!=1) ok=0;
	}
	return (ok);
}
