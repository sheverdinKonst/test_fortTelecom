//
// Created by konstantin on 31.08.23.
//

#include "client.h"


int clientDescriptor;
struct sockaddr_in adr = {0};

error_code clientApp(void)
{
    adr.sin_family = AF_INET;
    adr.sin_port = htons(8080);

    clientDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (clientDescriptor == -1) {
        perror("socket failed");
        return client_error;
    }

    int res = inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    if (res == 0) {
        printf("inet_pton failed: src does not contain a character"
               " string representing a valid network address in the specified"
               " address family\n");
        return client_error;
    }
    if (res == -1) {
        perror("inet_pton failed");
        return client_error;
    }

    res = connect(clientDescriptor, (struct sockaddr *) &adr, sizeof adr);
    if (res == -1) {
        perror("connect failed");
        return client_error;
    }
    while(1)
    {
        write(clientDescriptor, "hello from client\n", 18);
        char buf[256];
        ssize_t nread;
        nread = read(clientDescriptor, buf, 256);
        if (nread == -1) {
            perror("read failed");
            return client_error;
        }
        if (nread == 0) {
            printf("EOF occurred\n");
        }
        write(STDOUT_FILENO, buf, nread);
        //sleep(10);
    }
    //close(clientDescriptor);
    return 0;
}


