// client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // 创建客户端���接字
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 连接到服务器
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        // 发送消息给服务器
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        // 接收消息从服务器
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
            perror("Error receiving message from server");
            break;
        }

        printf("Server: %s\n", buffer);

        if (strcmp(buffer, "end\n") == 0) {
            printf("Chat ended by server.\n");
            break;
        }
    }

    // 关闭套接字
    close(client_socket);

    return 0;
}
