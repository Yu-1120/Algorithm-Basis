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
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
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
	printf("bind OK!\n");
	

	char buf[1000] = {};
	struct sockaddr_in from;
	socklen_t len;

	//5.反复通信
	while(1){
		len = sizeof(from);

		//接受数据
		res = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&from, &len);
		if(res<=0){
			perror("recvfrom");
			continue;
		}

		printf("%s发来%d字节,内容为:%s\n", inet_ntoa(from.sin_addr), res, buf);
		//原路发回
		sendto(sockfd, buf, res, 0, (struct sockaddr *)&from, len);
	}


	close(sockfd);
	return 0;
}

