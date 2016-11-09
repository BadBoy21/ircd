#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>


int main(){


	return 1;
}


/*

	if(checkPrefix(temp, "USER ",5)==1){
		
		char dataCheck[512];
		strncpy(dataCheck, temp, strlen(temp));
		dataCheck[ strlen(temp)] = '\0';
		

		char* token = strtok(dataCheck, " ");

		printf("%s\n",token );
		
		char * username = strtok(NULL, " ");
		

		setUser(username, clientObj);
		
		memset(dataCheck, 0, sizeof dataCheck);

		
		strncpy(dataCheck, temp, 512);
		dataCheck[511] = '\0';

		char* token2 = strtok(dataCheck, ":");

		printf("%s\n",token2 );
		char * realname = strtok(NULL, ":");
		

		setrealname(realname, clientObj);

		
	}


*/