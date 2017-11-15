/***** CLIENT SIDE CODE *****/

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
  char address[50];
  struct sockaddr_in source, destination;
  int sock_desc;
  int x = sizeof(destination);
  sock_desc = socket(AF_INET,SOCK_DGRAM,0);
  if (sock_desc == -1)
       {
		printf("Error creating socket.");
		return 1;
	}

  source.sin_family=AF_INET;
  source.sin_addr.s_addr=INADDR_ANY;
  source.sin_port=htons(4444);
	if (bind(sock_desc,(struct sockaddr *)&source, sizeof(source))<0) 
        {
		printf("Binding unsuccessful.\n");
		return 1;
	}
  printf("binding successful.\n");

  destination.sin_family=AF_INET;
  destination.sin_addr.s_addr=INADDR_ANY;
  destination.sin_port=htons(8888);

  printf("enter the address whose ip you seek : ");
  scanf("%s", address);

  if(sendto(sock_desc,address,50,0,(struct sockaddr *)&destination, sizeof(destination))<0) 
        {
		printf("Sending Failed.\n");
		return 1;
	}
  
  printf(" the requested address is : \n");

 recvfrom(sock_desc, address, 50, 0, (struct sockaddr *)&destination,&x);
	puts(address);	
	return 0;
}
  
   
