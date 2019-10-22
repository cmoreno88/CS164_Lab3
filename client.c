#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
//client.c
int main(int argc,char *argv[])
{
  char sendBuff[1025];
  int listenfd=0,sockfd = 0,n = 0,connfd=0;
  //char recvBuff[1024];
  struct sockaddr_in serv_addr;

  //memset(recvBuff, '0' ,sizeof(recvBuff));
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    }
  memset(sendBuff, '0' ,sizeof(sendBuff));
while(1){
  //memset(sendBuff, '0' ,sizeof(sendBuff));
strcpy(sendBuff, argv[1]);//just change hi to argv[1]
write(sockfd, sendBuff, strlen(sendBuff));
close(sockfd);
sleep(1);
 }

  return 0;
}
