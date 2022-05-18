#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define SERV_TCP_PORT 8000 
int main(int argc, char *argv[])
{
int sockfd;
struct sockaddr_in serv_addr;
char *serv_host = "localhost";
struct hostent *host_ptr;
int port;
int buff_size = 0;
if(argc >= 2)
serv_host = argv[1]; 
if(argc == 3)
sscanf(argv[2], "%d", &port); 
else
port = SERV_TCP_PORT;
if((host_ptr = gethostbyname(serv_host)) == NULL) {
perror("gethostbyname error");
exit(1);
}
if(host_ptr->h_addrtype != AF_INET) {
perror("unknown address type");
exit(1);
}
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr =
((struct in_addr *)host_ptr->h_addr_list[0])->s_addr;
serv_addr.sin_port = htons(port);
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
perror("can't open stream socket");
exit(1);
if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
perror("can't connect to server");
exit(1);
}
write(sockfd, "hello world connetion established", sizeof("hello world connetion established"));
close(sockfd);
}}
