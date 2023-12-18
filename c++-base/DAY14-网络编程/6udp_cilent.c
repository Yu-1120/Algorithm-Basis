
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage:%s ip port\n", argv[0]);
        exit(-1);
    }

    //1.创建socket描述符
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(-1);
    }

    //2.准备通信地址
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));//端口号
    addr.sin_addr.s_addr = inet_addr(argv[1]);//IP


    //和服务器通信
    char buf[1000] = {};
    char r_buf[1000] = {};
    printf("请输入要发送的数据:");
    fgets(buf, 1000, stdin);
    //The function is to read data from the specified stream, one line at a time.
    //fgets函数功能为从指定的流中读取数据，每次读取一行。
    struct sockaddr_in from;
    socklen_t len = sizeof(from);
    sendto(sockfd, buf, strlen(buf) + 1, 0, (struct sockaddr *) &addr, sizeof(addr));
    int res = recvfrom(sockfd, r_buf, sizeof(r_buf), 0, (struct sockaddr *) &from, &len);
    printf("%s:%s\n", inet_ntoa(from.sin_addr), r_buf);

    close(sockfd);

    return 0;
}

