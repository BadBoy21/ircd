#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accountSetup.h"
#include "common.h"
#include "router.h"


void mainRouter(char * data, Client * clientObj){

	char temp[strlen(data)+1];
	strncpy(temp, data, strlen(data));
	temp[strlen(data)] = '\0';

	if(checkPrefix(temp, "NICK ",5)==1){
		char dataCheck[27];
		strncpy(dataCheck, temp, 26);
		dataCheck[26] = '\0';
		memmove (dataCheck, dataCheck+5, strlen (dataCheck+1) + 5);
		setNick(dataCheck, clientObj);

	}
	if(checkPrefix(temp, "USER ",5)==1){
		printf("%s\n", temp);
	}


}

void lineFixer(char * userInput, Client * clientObj){
	
	char temp[strlen(userInput)+1];
	strncpy(temp, userInput, strlen(userInput));
	temp[strlen(userInput)] = '\0';


	char* token = strtok(temp, "\n");
	while (token) {
		
		if(strlen(token) > 1){
			mainRouter(token, clientObj);
		}
		
		token = strtok(NULL, "\n");
	}
	
}