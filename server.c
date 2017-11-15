/***** SERVER SIDE PROGRAM *****/

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{

  char address[50], buffer[50];
  struct sockaddr_in source, destination;
  int sock_desc;
  int x = sizeof(source);
  int flag = 0;
  
  sock_desc = socket(AF_INET,SOCK_DGRAM,0);
  if (sock_desc == -1) 
        {
		printf("Error creating socket.");
		return 1;
	}
  
  destination.sin_family=AF_INET;
  destination.sin_addr.s_addr=INADDR_ANY;
  destination.sin_port=htons(8888);
  if (bind(sock_desc,(struct sockaddr *)&destination, sizeof(destination))<0) 
        {
		printf("Binding unsuccessful.\n");
		return 1;
	}
	        printf("Binding successful.\n");

  if(recvfrom(sock_desc, address, 50, 0, (struct sockaddr *)&source,&x)<0) {
		puts("Receiving Failed");
		return 1;
	}

  FILE *fp;
  fp = fopen("hosts.txt","r");
  if(!fp){
		puts("Could not open file!");
		return 1;
	 }
  
  while(!feof(fp)) {
		fscanf(fp,"%s",buffer);
		if(flag==1) {
			sendto(sock_desc,buffer,50,0,(struct sockaddr *)&source, sizeof(source));
			puts("Address successfully resolved.");
			return 1;
		}
		if(strcmp(address,buffer)==0) {
			flag=1;
		}
	}
	strcpy(buffer,"invalid address.\n");
	sendto(sock_desc,buffer,50,0,(struct sockaddr *)&source, sizeof(source));
	return 0;
}
