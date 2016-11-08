#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "router.h"


void mainRouter(char * data, int outSocketHandle){

	char temp[strlen(data)+1];
	strncpy(temp, data, strlen(data));
	temp[strlen(data)] = '\0';

	if(checkPrefix(temp, "NICK",4)==1){
		
	}

}

void lineFixer(char * userInput, int outSocketHandle){
	
	char temp[strlen(userInput)+1];
	strncpy(temp, userInput, strlen(userInput));
	temp[strlen(userInput)] = '\0';


	char* token = strtok(temp, "\n");
	while (token) {
		
		if(strlen(token) > 1){
			mainRouter(token, outSocketHandle);
		}
		
		token = strtok(NULL, "\n");
	}
	
}