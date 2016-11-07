#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "common.h"


int socketHandle;

int clientSocketArray[10000];
int totalClients = 0;

Client * clientObjs[10000];

Client * createClientObject(char * ip, int socketfd, int id){
	Client * newClient = malloc(sizeof(Client));

	strncpy(newClient->ip, ip, strlen(ip));
	newClient->id = id;
	newClient->socketfd = socketfd;
	return newClient;
}

void sendToClient (char * someMessage, int clientHandle){

	if (write(clientHandle,someMessage,strlen(someMessage)) < 0) {
		perror("ERROR writing to socket");
		exit(1);
	}

}

void * clientThread(void * clientIDVoid){
	printf("THREAD CREATED\n");

	int clientID = (int *) clientIDVoid;
	printf("%i\n", clientID);

	char buffer[256];
	bzero(buffer,256);
	

	while(read( clientObjs[clientID]->socketfd,buffer,255 ) > 0){

		printf("%s\n", buffer);

		bzero(buffer,256);

	}

}


void clientConnection (){

	
	int newsockfd;

	while(1){
		struct sockaddr_in cli_addr;
		socklen_t clilen = sizeof(cli_addr);
		newsockfd = accept(socketHandle, (struct sockaddr *)&cli_addr, &clilen);
		
		

		if (newsockfd < 0) {
			perror("ERROR on accept");
			exit(1);
		}
		printf("ACCEPTED\n");

		struct sockaddr_in* pV4Addr = (struct sockaddr_in*)&cli_addr;
		struct in_addr ipAddr = pV4Addr->sin_addr;

		char str[INET_ADDRSTRLEN];
		inet_ntop( AF_INET, &ipAddr, str, INET_ADDRSTRLEN );

		
		

		clientObjs[totalClients] = createClientObject(str, newsockfd, totalClients);
		int clientID = totalClients;

		totalClients++;


		

		pthread_t newClientThread;

		int rc = pthread_create(&newClientThread, NULL, clientThread, (void *)clientID);
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
		
	}
	
	

}

void bindSocketHandle(){

	int portno;
	
	
	struct sockaddr_in serv_addr;
	

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(1);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = 5001;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);


	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		exit(1);
	}


	
	listen(sockfd, 10000);
	socketHandle = sockfd;
	

	clientConnection();

}



int main(){

	


	bindSocketHandle();

	
//	for (;;) pause();



	return 1;
}