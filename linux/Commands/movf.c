#include "../include/sysincludes.h"
#include "../include/Variables.h"

int movf(char *FileName){
	/**Variables**/
	char FNT[10000]; //File Name Temp
	char FD[10000]; //File Directory
	char FND[10000]; //File Name Directory
	char OFD[10000]; //Original File Directory
	char FC[1000]; //File Contents
	char FileDirectory[10000];
	FILE *f; //TempFile
	FILE *g; //Read Original File
	printf("File Directory Destination: ");
	fgets(FileDirectory,sizeof(FileDirectory),stdin);
	FileDirectory[strcspn(FileDirectory,"\r\n")]=0;
	sprintf(FNT,"%s.temp",FileName);
	sprintf(FD,"%s",FileDirectory);
	sprintf(OFD,"%s/%s",CurrentDirectory,FileName);
	/************/
	if(chdir(FD)==0){
		f=fopen(FNT,"w");
		g=fopen(OFD,"r");
		if(g&&f){
			while(fgets(FC,sizeof(FC),g)){
				fprintf(f,"%s",FC);
			}
			remove(OFD);
			rename(FNT,FileName);
		}
		else{
			if(f){
				remove(FNT);
			}
			PRINTERROR("UNABLE TO CREATE OR READ FILE");
			return 1;
		}
		fclose(g);
		fclose(f);
		chdir(CurrentDirectory);
		return 0;
	}
	else{
		PRINTERROR("Unable to find directory! Oof");
		chdir(CurrentDirectory);
		return 1;
	}
}
