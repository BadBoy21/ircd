#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int checkPrefix(char * fullString, char * substring, int size){

	char myString[strlen(fullString)+1];
	strncpy(myString, fullString, strlen(fullString));
	myString[strlen(fullString)] = '\0';

	char dest[size+1];
	strncpy(dest, myString,size);
	dest[size] = '\0'; 

	
	if(strcmp(substring, dest) == 0){
		return 1;
	}


	return 0;
}

