typedef struct Clients {
	char ip[20];
	int socketfd;
	int id;
} Client;

void sendToClient (char * someMessage, int clientHandle);
