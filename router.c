#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientSetup.h"
#include "common.h"
#include "router.h"



void mainRouter(char * data, Client * clientObj){




	char * temp = (char *)calloc(strlen(data)+1, sizeof(char));
	strncpy(temp, data, strlen(data));
	

	if(checkPrefix(temp, "NICK ",5)==1){
		char dataCheck[27];
		strncpy(dataCheck, temp, 26);
		dataCheck[26] = '\0';
		memmove (dataCheck, dataCheck+5, strlen (dataCheck+1) + 5);
		setNick(dataCheck, clientObj);

	}
	
	if(checkPrefix(temp, "USER ",5)==1){
		
		char * tempcopy = (char *)calloc(strlen(temp)+1, sizeof(char));
		strncpy(tempcopy, temp, strlen(temp));

		char * username = strToken(tempcopy, " ", 1);
		if(username != NULL){
			
			setUser(username, clientObj);
			printf("%s\n", clientObj->user);
		}
		free(tempcopy);
		free(username);
	}

	free(temp);
}

void lineFixer(char * userInput, Client * clientObj){
	
	char * temp = (char *)calloc(strlen(userInput)+1, sizeof(char));
	strncpy(temp, userInput, strlen(userInput));
	

	char* token = strtok(temp, "\n");
	while (token) {


		if(strlen(token) > 1){



			mainRouter(token, clientObj);
		}
		
		token = strtok(NULL, "\n");
	}
	free(temp);
	
}