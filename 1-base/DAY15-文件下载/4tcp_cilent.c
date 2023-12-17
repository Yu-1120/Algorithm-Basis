
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc,char **argv)
{
	if(argc!=3){
		printf("Usage:%s ip port\n",argv[0]);
		exit(-1);
	}

	//1.创建socket描述符
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		perror("socket");
		exit(-1);
	}

	//2.准备通信地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[2]));//端口号
	addr.sin_addr.s_addr = inet_addr(argv[1]);//IP


	//3.connect
	int res = connect(sockfd, (struct sockaddr *)&addr,sizeof(addr));
	if(res==-1){
		perror("connect");
		exit(-1);
	}

	//反复通信
	char buf[1000] = {};

	while(1){
		printf("请输入:");
		fgets(buf, 1000, stdin);
		buf[strlen(buf)-1] = 0;//去掉\n

		write(sockfd, buf, strlen(buf)+1);
		int res = read(sockfd, buf, sizeof(buf));
		if(res<=0)
			break;

		printf("%s\n", buf);

	}

	close(sockfd);

	return 0;
}

