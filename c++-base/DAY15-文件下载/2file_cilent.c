
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

//消息结构
typedef struct{
	char type;//消息类型  1-文件名 2-文件内容 3-错误消息
	char buf[1000];//消息内容
	int len;//消息长度
	int flag;//标志 0-无标志  1-文件传输完成 2-下载文件 4-上传文件 
}Msg;

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


	char buf[1000] = {};
	Msg msg;
	//选择功能
	int choice = 0;
	int fd;
	printf("1-下载文件\n");
	printf("2-上传文件\n");
	printf("0-退出\n");
	scanf("%d", &choice);
	getchar();

	switch(choice){
		case 1:
			//下载文件
			printf("请输入文件名:");
			fgets(buf,sizeof(buf),stdin);
			buf[strlen(buf)-1] = 0;
			//发送文件名
			msg.type = 1;
			msg.flag = 2;
			strcpy(msg.buf, buf);
			msg.len = strlen(buf)+1;
			write(sockfd, &msg ,sizeof(msg));

			fd = open(buf, O_RDWR|O_CREAT|O_TRUNC, 0666);
			if(fd==-1){
				perror("open");
				close(sockfd);
				exit(-1);
			}
			
			//读取文件内容写入文件
			while(1){
				res = read(sockfd, &msg ,sizeof(msg));
				if(res<=0){
					perror("read");
					close(fd);
					close(sockfd);
					exit(-1);
				}

				//处理错误消息
				if(msg.type==3){
					printf("error:%s\n", msg.buf);
					close(fd);
					exit(-1);
				}

				write(fd, msg.buf, msg.len);
				if(msg.type==2 && msg.flag==1){//传输完成
					break;
				}
			}

			printf("下载成功!\n");
			close(fd);
			break;
		case 2:
			//上传文件
			printf("请输入文件名:");
			fgets(buf,sizeof(buf),stdin);
			buf[strlen(buf)-1] = 0;
			//发送文件名
			msg.type = 1;
			msg.flag = 4;
			strcpy(msg.buf, buf);
			msg.len = strlen(buf)+1;
			write(sockfd, &msg ,sizeof(msg));

			fd = open(buf, O_RDWR);
			if(fd==-1){
				perror("open");
				close(sockfd);
				exit(-1);
			}
			
			//读取文件内容通过网络发出
			while(1){
				res = read(fd, msg.buf, sizeof(msg.buf));
				if(res<0){
					perror("read");
					close(fd);
					close(sockfd);
					exit(-1);
				}
				msg.type = 2;
				msg.len = res;
				if(res==sizeof(msg.buf)){
					msg.flag = 0;
					//网络发送
					write(sockfd, &msg, sizeof(msg));
				}
				else{
					msg.flag = 1;
					write(sockfd, &msg, sizeof(msg));
					break;
				}
			}
			
			printf("上传成功!\n");
			close(fd);
			break;
		case 0:
			break;
		default:
			printf("错误选择!\n");
			break;
	}


	close(sockfd);

	return 0;
}

