#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "router.h"

int tokenCount = 0;

void mainRouter(char * data, int outSocketHandle){

	char temp[strlen(data)+1];
	strncpy(temp, data, strlen(data));
	temp[strlen(data)+1] = '\0';

//	printf("%i\n", tokenCount);
	tokenCount++;
//	printf("%s\n", temp);

}

void lineFixer(char * userInput, int outSocketHandle){
	
	char temp[strlen(userInput)+1];
	strncpy(temp, userInput, strlen(userInput));
	temp[strlen(userInput)+1] = '\0';


	char* token = strtok(temp, "\n");
	while (token) {
		printf("NUMBER %i\n", strlen(token));
		mainRouter(token, outSocketHandle);
		token = strtok(NULL, "\n");
	}
	
}