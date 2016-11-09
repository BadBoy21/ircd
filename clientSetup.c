#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clientSetup.h"
#include "common.h"
#include "router.h"



void setNick(char * nicktoset, Client * clientObject){

	strncpy(clientObject->nick, nicktoset, 9);
	clientObject->nick[9] = '\0';

}

void setUser(char * usertoset, Client * clientObject){
	strncpy(clientObject->user, usertoset, 7);
	clientObject->user[7] = '\0';
}

void setIp(char * iptoset, Client * clientObject){
	strncpy(clientObject->ip, iptoset, 20);
	clientObject->ip[20] = '\0';
}

void setHostname(char * hostnameToSet, Client * clientObject){
	strncpy(clientObject->hostname, hostnameToSet, 7);
	clientObject->hostname[7] = '\0';
}

void setrealname(char * rntoset, Client * clientObject){
	strncpy(clientObject->realname, rntoset, 29);
	clientObject->realname[29] = '\0';
}

void toString(Client * clientObject){
//	printf("ip: %s nick: %s user: %s realname: %s socketfd: %i id: %i\n", clientObject->ip,clientObject->nick,clientObject->user,clientObject->realname,clientObject->socketfd,clientObject->id  );
	printf("ip: %s\n", clientObject->ip);
	printf("nick: %s\n",clientObject->nick );
	printf("user: %s\n", clientObject->user );
	printf("realname: %s\n", clientObject->realname );

}