/* Code from Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        error("Can't talk to the server");

    return result;
}

int main(int argc, char *argv[])
{
    
    int valread;
    int sock = 0;

    char *hello = "Hello from client\0";
    char buffer[1024] = {0};

    struct sockaddr_in si;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\n Error in creating socket \n");
        return -1;
    }
    
    memset(&si, 0, sizeof(si));
    si.sin_family = AF_INET;
    //si.sin_addr.s_addr = inet_addr("127.0.0.1");
    si.sin_port = htons(30001);

    if(inet_pton(AF_INET, "127.0.0.1", &si.sin_addr)<=0)
    {
        printf("\n Invalid address/ Address not supported \n");
        return -1;
    }


    if (connect(sock, (struct sockaddr *)&si, sizeof(si)) < 0)
    {
        printf("\nConnection has Failed \n");
        return -1;
    }

    say(sock, hello);
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return 0;

}
