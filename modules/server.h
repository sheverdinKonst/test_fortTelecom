//
// Created by konstantin on 31.08.23.
//

#ifndef CLIENT_SERVER_H
#define CLIENT_SERVER_H

#include "utils.h"

#define MAX_CLIENTS (255)
#define PORT (8080)

error_code serverInit(void);
error_code serverHandler(unsigned char n);

#endif //CLIENT_SERVER_H
