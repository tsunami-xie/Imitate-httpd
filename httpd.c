#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error_die(const char *sc)
{
 //包含于<stdio.h>,基于当前的 errno 值，在标准错误上产生一条错误消息。参考《TLPI》P49
 perror(sc); 
 exit(1);
}


int startup(u_short *port){
	
	int httpd=0;
	struct sockaddr_in name;
	
	httpd=socket(PF_INET,SOCK_STREAM,0);
	if(httpd==-1){
		error_die("socket");
	}
	
	memset(&name,0,sizeof(name));	
	name.sin_family = AF_INET;
 	name.sin_port = htons(*port);
 	name.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(httpd, (struct sockaddr *)&name, sizeof(name))<0){
		error_die("bind");
	}
	
}

int main(void){
	
	int server_sock = -1;
	u_short port = 0;
	
	server_sock = startup(&port);
	printf("httpd running on port %d\n", port);
	
	
 
 
	return 0;
}