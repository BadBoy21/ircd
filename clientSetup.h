typedef struct Clients {
	char ip[21];
	char hostname[40];
	char nick[10];
	char user[8];
	char realname[30];
	int socketfd;
	int id;
	int recycle;
	int connected;
} Client;

void setNick(char * nicktoset, Client * clientObject);

void setUser(char * usertoset, Client * clientObject);

void setIp(char * iptoset, Client * clientObject);

void setHostname(char * hostnameToSet, Client * clientObject);

void setrealname(char * rntoset, Client * clientObject);

void toString(Client * clientObject);