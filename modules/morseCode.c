//
// Created by konstantin on 30.08.23.
//

#include "morseCode.h"

void encodeToMorse(char* input, char* output) {
    int i;
    char morse[36][6] = {
            {".-"},   {"-..."}, {"-.-."}, {"-.."},  {"."},    {"..-."},  // A-F
            {"--."},  {"...."}, {".."},   {".---"}, {"-.-"},  {".-.."},  // G-L
            {"--"},   {"-."},   {"---"},  {".--."}, {"--.-"}, {".-."},   // M-R
            {"..."},  {"-"},    {"..-"},  {"...-"}, {".--"},  {"-..-"},  // S-X
            {"-.--"}, {"--.."}, {"-----"},{".----"},{"..---"},{"...--"}, // Y-3
            {"....-"},{"....."},{"-...."},{"--..."},{"---.."},{"----."}  // 4-9
    };

    printf("num of symbols = %lu\n", strlen(input));

    for (i = 0; i < strlen(input); i++) {
        printf("input[i] = %d\n", input[i]);


        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            strcpy(output, morse[input[i] - 'A']);
            strcat(output, "|");
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            strcpy(output, morse[input[i] - 'a']);
            strcat(output, "|");
            printf("morse[input[i]] = %s\n", morse[input[i] -'a']);
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            strcpy(output, morse[input[i] - 22]);
            strcat(output, "|");
            printf("morse[input[i]] = %s\n", morse[input[i] - 22]);
        }
        else if (input[i] >= ' ')
        {
            printf("PROBEL\n");
            output[0] = ' ';
            strcat(output, " ");
        }
        else
        {
            output[0] = '\0';
            strcat(output, " ");
        }
        output += strlen(output);
    }
}
