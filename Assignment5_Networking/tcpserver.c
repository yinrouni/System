// Compile with: gcc tcpserver.c -o tcpserver
//
// Implement tcp server below.
// Our standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some types and unix operations
#include <sys/types.h>
#include <unistd.h>

// A sockets library and internet protocol library
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>

int doCommand(char* command);
int main(){
    
    // Create the server socket
    int server_socket;
    
    //            domain, type         ,protocol
    //domain = AF_INET(IPv4) or AF_INET6
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // define the server address format
    struct sockaddr_in server_address;
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(7002); // 9002 is choosen arbitrarily. Try other ports if this does not work
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    printf("Server bind()\n");
    
    listen(server_socket, 27);
    
    // Integer to hold a potential client socket
    int client_socket;
    while(1){
        client_socket = accept(server_socket, NULL, NULL);
        
        // send a message from the server
        char server_message[256] = "You have reached the server";
        
        send(client_socket, server_message, sizeof(server_message), 0);
        printf("Client has joined: %d\n", server_socket);
        
        char username[128];
        recv(client_socket, &username, sizeof(username), 0);
        printf(">%s\n", username);
        
        while(1){
            char command[128];
            recv(client_socket, &command, sizeof(command), 0);
            printf("%s\n", command);
            if (strcmp("exit", command) == 0){
                    break;
            }
            system(command);
    }
    }
    
    // Close the socket
    close(server_socket);
    
    return 0;
}

int doCommand(char* command){
            if (fork() == 0){
                    system(command);
                    exit(1);
            }
            else{
                wait(NULL);
                return 1;
            }
}
