#include "../include/sysincludes.h"
#include "../include/stdfunctions.h"
int mf(char *FileName){
	DIR *CurrDirectory=opendir(".");
	struct dirent *ep;
	if(CurrDirectory!=NULL){
		while(ep=readdir(CurrDirectory)){
			if(ep->d_type==DT_REG){
				if(ep->d_name==FileName){
					PRINTERROR("FILE ALREADY EXISTS!");
					return 1;
				}
				if(ep->d_name!=FileName){
					FILE *f=fopen(FileName,"w");
					fclose(f);
					return 0;
				}		
			}
		}
	}
	else{
		PRINTERROR("ERROR!");
		printf("Error code: %d",errno);
		return 1;
	}
}
