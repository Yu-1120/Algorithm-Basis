#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>

typedef struct{
	int fd;//通信socket
	char ip[100];//IP
}Param;

//消息结构
typedef struct{
	char type;//消息类型  1-文件名 2-文件内容 3-错误消息
	char buf[1000];//消息内容
	int len;//消息长度
	int flag;//标志 0-无标志  1-文件传输完成 2-下载文件 4-上传文件 
}Msg;


void *task(void *arg)
{
	char filepath[1000] = {};
	char buffer[1000] = {};
	Msg msg;
	Param *p = (Param *)arg;

	int res = read(p->fd, &msg, sizeof(msg));
	if(res<=0){
		perror("read");
		close(p->fd);
		free(p);
		return NULL;
	}
	//取出文件名
	strncpy(filepath, msg.buf, msg.len);

	if(msg.flag==2 && msg.type==1){//下载文件
		//打开文件
		int fd = open(filepath,O_RDWR);
		if(fd==-1){
			//发送错误消息
			msg.type=3;
			msg.flag=0;
			strcpy(msg.buf,"open file failed!");
			msg.len = strlen(msg.buf)+1;
			write(p->fd, &msg, sizeof(msg));

			close(p->fd);
			free(p);
			return NULL;
		}

		//读取文件内容并发送
		while(1){
			res = read(fd, buffer, sizeof(buffer));
			if(res<sizeof(buffer)){
				//发送完成
				msg.type = 2;
				msg.flag = 1;
				strncpy(msg.buf, buffer, res);
				msg.len = res;
				write(p->fd, &msg, sizeof(msg));
				break;
			}

			//发送文件内容
			msg.type = 2;
			msg.flag = 0;
			strncpy(msg.buf, buffer, res);
			msg.len = res;
			write(p->fd, &msg, sizeof(msg));
		}

		//关闭文件
		close(fd);
	}
	else if(msg.flag==4 && msg.type==1){//上传文件
		//打开文件
		int fd = open(filepath,O_RDWR|O_CREAT|O_TRUNC,0666);
		if(fd==-1){
			//发送错误消息
			msg.type=3;
			msg.flag=0;
			strcpy(msg.buf,"open file failed!");
			msg.len = strlen(msg.buf)+1;
			write(p->fd, &msg, sizeof(msg));

			close(p->fd);
			free(p);
			return NULL;
		}

		//接收文件内容并写入文件
		while(1){
			res = read(p->fd, &msg, sizeof(msg));
			if(res<=0){
				perror("read");
				close(p->fd);
				free(p);
				return NULL;
			}

			write(fd, msg.buf, msg.len);
			if(msg.type==2 && msg.flag==1){//传输完成
				break;
			}
		}

		//关闭文件
		close(fd);
	}
	else{
		//发送错误消息
		msg.type=3;
		msg.flag=0;
		strcpy(msg.buf,"unkonw type msg!");
		msg.len = strlen(msg.buf)+1;
		write(p->fd, &msg, sizeof(msg));
	}


	close(p->fd);
	free(p);
}

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
		Param *p = malloc(sizeof(Param));
		p->fd = newfd;
		strcpy(p->ip, inet_ntoa(cilent.sin_addr));

		//开线程
		pthread_t id;
		pthread_create(&id, NULL, task, p);
		//将子线程设置为分离模式
		pthread_detach(id);
	}


	close(sockfd);
	return 0;
}

