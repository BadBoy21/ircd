#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int checkPrefix(char * fullString, char * substring, int size){

	
	char * myString = (char *)calloc(strlen(fullString)+1, sizeof(char));

	strncpy(myString, fullString, strlen(fullString));
	
	char * dest = (char *)calloc(size+1, sizeof(char));

	strncpy(dest, myString,size);
	
	
	if(strcmp(substring, dest) == 0){
		free(myString);
		free(dest);
		return 1;
	}

	free(myString);
	free(dest);
	return 0;
}



void strToken(char * input, char * delimiter, int  position){

	char*  clone = (char *)calloc(strlen(input) + strlen(delimiter) + 1, sizeof(char));;
	
	strncpy(clone, input, strlen(input));

	strncat(clone, delimiter, strlen(delimiter));

	
	int totalSize = strlen(clone);
	int delimSize = strlen(delimiter);

	int matchCount = 0;

	int i = 0;

	int currentPosition = -1;
	int lastCharPosition = 0;

	for(i =0;i<totalSize;i++){
		
		if(clone[i]==delimiter[0]){
			int j = 0;
			for(j=0;j<delimSize; j++){
				if(clone[i+j]==delimiter[j]){

					matchCount++;
				}
			}
			if(matchCount == delimSize){
				if(i ==0){

					position++;
					
				}
				currentPosition++;
				if(position == currentPosition){
					int k = lastCharPosition;
					for(k=lastCharPosition;k<i; k++){
						printf("%c\n", clone[k]);
					}
				}
				//printf("%i\n", lastCharPosition);
				lastCharPosition = i+delimSize;
			}
		}
		matchCount = 0;
	}
	

	free(clone);

}

