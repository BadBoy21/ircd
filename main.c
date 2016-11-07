#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

int bindSocketHandle(){

	int sockfd, newsockfd, portno, clilen;
	
	struct sockaddr_in serv_addr, cli_addr;
	

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(1);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = 5000;

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);


	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		exit(1);
	}

	listen(sockfd,5);
	clilen = sizeof(cli_addr);


	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	
	if (newsockfd < 0) {
		perror("ERROR on accept");
		exit(1);
	}
	return newsockfd;
}

int main(){

	int socketHandle = bindSocketHandle();


	char buffer[256];

	bzero(buffer,256);
	

	if (read( socketHandle,buffer,255 ) < 0) {
		perror("ERROR reading from socket");
		exit(1);
	}

	printf("Here is the message: %s\n",buffer);



/*
   
	n = write(newsockfd,"I got your message",18);

	if (n < 0) {
		perror("ERROR writing to socket");
		exit(1);
	}

	*/

	return 1;
}