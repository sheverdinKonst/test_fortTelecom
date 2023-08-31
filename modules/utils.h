//
// Created by konstantin on 31.08.23.
//

#ifndef CLIENT_UTILS_H
#define CLIENT_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint-gcc.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

typedef enum
{
    CLIENT,
    SERVER,
    MAX_APP_TYPE
}APP_TYPE_e;

typedef struct
{
    APP_TYPE_e appType;
    unsigned char numClient;
}CURRENT_TYPE_APP_t;

typedef enum
{
    no_error,
    error,
    server_error,
    client_error
}error_code;

typedef struct
{
    int id;
    const char *msg;
    int out;
}msg_struct;

void getAppParam(int argc, char **argv, CURRENT_TYPE_APP_t* currentTypeApp);
void receive_message(char* encodedMassage);
void getDecodeMsg(char* input);


#endif //CLIENT_UTILS_H
