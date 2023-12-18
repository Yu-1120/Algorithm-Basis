
// server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // 创建服务器套接字
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地��
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 绑定套接字
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding server socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // 监听连接请求
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for connections");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // 接受客户端连接
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
    if (client_socket == -1) {
        perror("Error accepting client connection");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    while (1) {
        // 接收消息从客户端
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
            perror("Error receiving message from client");
            break;
        }

        printf("Client: %s\n", buffer);

        // ���送消息给客户端
        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "end\n") == 0) {
            printf("Chat ended by server.\n");
            break;
        }
    }

    // 关闭套接字
    close(client_socket);
    close(server_socket);

    return 0;
}
