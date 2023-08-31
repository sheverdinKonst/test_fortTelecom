//
// Created by konstantin on 30.08.23.
//
#include <string.h>
#include <stdio.h>

#ifndef CLIENT_MORSECODE_H
#define CLIENT_MORSECODE_H

#define DIGIT_OFFSET (22)
void encodeToMorse(char* input, char* output);
void decryptChar(const char* morseChar, char* decryptChar);



#endif //CLIENT_MORSECODE_H
