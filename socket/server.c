#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>


int main(void)
{
	int sock, client_sock;
	struct sockaddr_in server, client;
	unsigned int len;
	int sent;
	char* msg = "hello world!";	

	if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket: ");
		exit(-1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(13245);
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero, 8);
	
	len = sizeof(struct sockaddr_in);

	if((bind(sock, (struct sockaddr *)&server, len))==-1)	
	{
		perror("bind ");
		exit(-1);
	}
	
	if((listen(sock, 5))==-1)
	{
		perror("listen ");
		exit(-1);
	}


	while(1)
	{
		
		if((client_sock = accept(sock, (struct sockaddr *)&client, &len))==-1)
		{
			perror("accept : ");
			exit(-1);
		}

		sent = send(client_sock, msg, strlen(msg),0);
		printf("sent %d bytes to client  : %s\n", sent, inet_ntoa(client.sin_addr));

	close(client_sock);


}

return 0;
}