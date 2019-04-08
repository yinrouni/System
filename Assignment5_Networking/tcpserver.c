// Compile with: gcc tcpserver.c -o tcpserver
//
// Implement tcp server below.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some types and unix operations
#include <sys/types.h>
#include <unistd.h>

// A sockets library and internet protocol library
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

	// Create the server socket
	int server_socket;

	//			domain, type 	    ,protocol
	//domain = AF_INET(IPv4) or AF_INET6			
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// define the server address format
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002); // 9002 is choosen arbitrarily. Try other ports if this does not work
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	printf("Server bind()\n");

	listen(server_socket, 27);

	// Integer to hold a potential client socket
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	// send a message from the server
	char server_message[256] = "You have reached the server";

	send(client_socket, server_message, sizeof(server_message), 0);

	// Close the socket
	close(server_socket);
	
	return 0;
}
