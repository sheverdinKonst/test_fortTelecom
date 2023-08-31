//
// Created by konstantin on 31.08.23.
//

#include "server.h"
#include "string.h"

static unsigned char connectedClients;
static struct sockaddr_in server_addr, client_addr;
static int server_sock, client_sock;
static error_code errorCode;
int addr_len = sizeof(client_addr);
pthread_t threads[MAX_CLIENTS];

void* handle_client(void* arg) {
    client_sock = *((int*)arg);
    char buffer[1024] = {0};
    char* message = "Hello from server\n";

    // Прочитать данные от клиента
    ssize_t read_n;
    read_n = read(client_sock, buffer, sizeof(buffer));
    printf("Client message: %s\n", buffer);
    printf("read_n = %zd\n", read_n);
    // Отправить ответ клиенту
    ssize_t write_n;
    write_n = write(client_sock, message, strlen(message));
    printf("write_n = %zd\n", write_n);

    char encoded_message[200];
    receive_message(encoded_message);
    write_n = write(client_sock, encoded_message, strlen(encoded_message));

    // Закрыть сокет клиента
    //close(client_sock);

    //pthread_exit(NULL);

}

error_code serverInit(void)
{
    connectedClients = 0;

    // Создать серверный сокет
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        return server_error;
    }

    // Настроить параметры сервера
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Привязать серверный сокет к адресу и порту
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind");
        return server_error;
    }

    // Начать прослушивание входящих соединений
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Failed to listen");
        return server_error;
    }

    return no_error;
}

error_code serverHandler(unsigned char max_client)
{
    if ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len)) < 0) {
        perror("Failed to accept");
        return server_error;
    }

    printf("New connection accepted\n");

    // Создать поток для обработки клиента
    if (pthread_create(&threads[connectedClients], NULL, handle_client, &client_sock) != 0) {
        perror("Failed to create thread");
        return server_error;
    }

    // Увеличить индекс для следующего потока
    connectedClients++;
    // Ограничить количество одновременных подключений
    printf("Number clients connected: %d\n", connectedClients);
    if (connectedClients >= max_client) {
        connectedClients = 0;
        while (connectedClients < max_client) {
            pthread_join(threads[connectedClients++], NULL);
        }
        connectedClients = 0;
    }
    return no_error;
}
