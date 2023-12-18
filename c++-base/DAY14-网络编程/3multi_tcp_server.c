#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>

typedef struct {  //多任务多写这个函数
    int fd;//通信socket
    char ip[100];//IP
} Param;

void *task(void *arg)  //多任务多写这个函数
{
    char msg[1000] = {};
    Param *p = (Param *) arg;

    while (1) {
        int res = read(p->fd, msg, sizeof(msg));
        if (res <= 0)
            break;
        printf("%s:%s\n", p->ip, msg);
        if (strcmp(msg, "byebye") == 0)
            break;

        //原路发回
        write(p->fd, msg, res);
    }

    close(p->fd);
    free(p);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage:%s ip port\n", argv[0]);
        exit(-1);
    }

    //1.创建socket描述符
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //这里要改单任务的是
    if (sockfd == -1) {
        perror("socket");
        exit(-1);
    }

    //2.准备通信地址
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));//端口号
    addr.sin_addr.s_addr = inet_addr(argv[1]);//IP


    //3.bind
    int res = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (res == -1) {
        perror("bind");
        exit(-1);
    }

    //4.listen
    listen(sockfd, 100);

    //5.等待客户端连接
    while (1) {
        struct sockaddr_in cilent;
        socklen_t len = sizeof(cilent);


        int newfd = accept(sockfd, (struct sockaddr *) &cilent, &len);
        if (newfd == -1) {
            perror("accept");
            exit(-1);
        }
        printf("%s到此一游!\n", inet_ntoa(cilent.sin_addr));

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

