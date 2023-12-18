#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>

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
	int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
	if(res==-1){
		perror("bind");
		exit(-1);
	}

	//4.listen
	listen(sockfd,100);

	//准备描述符集合
	fd_set set;
	//存入所有连上来的客户端描述符
	int *fds = malloc(1000*sizeof(int));
	//设置所有的描述符值为-1
	memset(fds, -1, 1000*sizeof(int));
	int maxfd;//最大描述符值
	char msg[1000] = {};
	int i;

	//5.等待客户端连接
	while(1){
		maxfd = sockfd;
		FD_ZERO(&set);
		FD_SET(sockfd, &set);

		//将连上来的客户端描述符加入set
		for(i=0; i<1000; i++){
			if(fds[i]!=-1){
				FD_SET(fds[i], &set);
				//记录最大描述符值
				if(fds[i]>maxfd)
					maxfd = fds[i];
			}
		}

		//select
		select(maxfd+1, &set, NULL, NULL, NULL);


		//1.有客户端连上来
		if(FD_ISSET(sockfd, &set)){
			struct sockaddr_in cilent;
			socklen_t len = sizeof(cilent);

			int newfd = accept(sockfd, (struct sockaddr *)&cilent, &len);
			if(newfd==-1){
				perror("accept");
				continue;
			}

			//将新连接上来的客户端的描述符加入到fds中
			for(i=0; i<1000; i++){
				if(fds[i]==-1)
					break;
			}
			fds[i] = newfd;

			printf("%s到此一游!\n",inet_ntoa(cilent.sin_addr));
		}

		//2.客户端发送消息
		for(i=0; i<1000; i++){
			if(fds[i]!=-1 && FD_ISSET(fds[i], &set)){
				int res = read(fds[i], msg, sizeof(msg));
				if(res<=0){
					close(fds[i]);
					fds[i] = -1;
					continue;
				}
				printf(":%s\n", msg);

				if(strcmp(msg, "quit")==0){
					close(fds[i]);
					fds[i] = -1;
					continue;
				}

				//原路发回
				write(fds[i], msg, res);
			}
		}

	}

	close(sockfd);
	return 0;
}

