#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

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


	//3.bind
	int res = bind(sockfd, (struct sockaddr *)&addr,sizeof(addr));
	if(res==-1){
		perror("bind");
		exit(-1);
	}

	//4.listen
	listen(sockfd,100);

	//5.等待客户端连接
	while(1){
		struct sockaddr_in cilent;
		socklen_t len = sizeof(cilent);

		int newfd = accept(sockfd, (struct sockaddr *)&cilent, &len);
		if(newfd==-1){
			perror("accept");
			exit(-1);
		}
		printf("%s到此一游!\n",inet_ntoa(cilent.sin_addr));

		//6.和客户端通信
		char buf[100] = {};
		res = read(newfd, buf, sizeof(buf));
		if(res<=0)
			break;

		printf("%s说:%s\n", inet_ntoa(cilent.sin_addr), buf);
		close(newfd);
	}


	close(sockfd);
	return 0;
}

