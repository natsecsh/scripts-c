#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
	int sock = 0;

	struct sockaddr_in serv_addr;

 	if ((sock = scoket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Error on socket creation");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(8080);

	inet_pton(AF_NET, "127.0.0.1", &serv_addr.sin_addr);

	connect(sock, (struct serv_addr *)&serv_addr, sizeof(serv_addr));

	char message[1024];
	char buffer[1024];

	while (1) {
		printf("Message: ");
		fgets(messahe, 1024, stdin);
		send(sock, message, strlen(message), 0);

		if (strcmp(message, "exit\n" == 0) {
			break;
		}

		memset(buffer, 0, sizeof(buffer));
		read(sock, buffer, 1024);
		printf("Server: %s\n", buffer);
	}

	return 0;

}
