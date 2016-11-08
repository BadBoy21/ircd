typedef struct Clients {
	char ip[21];
	char nick[20];
	char user[20];
	char realname[20];
	int socketfd;
	int id;
	
} Client;

void setNick(char * nicktoset, Client * clientObject);

void setUser(char * usertoset, Client * clientObject);

void toString(Client * clientObject);