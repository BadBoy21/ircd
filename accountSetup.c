#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accountSetup.h"
#include "common.h"
#include "router.h"



void setNick(char * nicktoset, Client * clientObject){

	strncpy(clientObject->nick, nicktoset, strlen(nicktoset));
	clientObject->nick[strlen(nicktoset)] = '\0';

}

void setUser(char * usertoset, Client * clientObject){
	
}

void setIp(char * iptoset, Client * clientObject){
	
}

void setrealname(char * rntoset, Client * clientObject){
	
}

void toString(Client * clientObject){
//	printf("ip: %s nick: %s user: %s realname: %s socketfd: %i id: %i\n", clientObject->ip,clientObject->nick,clientObject->user,clientObject->realname,clientObject->socketfd,clientObject->id  );
	printf("ip: %s nick: %s user: %s realname: %s socketfd: %i id: %i\n", clientObject->ip,clientObject->nick );

}