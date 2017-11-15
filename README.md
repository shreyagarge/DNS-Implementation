# DNS-Implementation
1.create two socket descriptor and two addresses, a source and one destination.
2.the source address is used to bind the client to a port and destination is used to bind it to the server.
3.source structure will have port address of the client, not same as the server and the destination structure will have address of the server in it
4.once all bindings are done successfully, prompt the user to enter the address he wishes to resolve.
5. Send the address to the server using the sendto command.
6.	recieve the address in the server using receivefrom command
7.	Using the fscanf function, compare the address with the hosts file for a match in the server program.
8.	If a match is found, use fscanf again to read the corresponding IP address and store it into a string.
9.	Return the result to the client.
