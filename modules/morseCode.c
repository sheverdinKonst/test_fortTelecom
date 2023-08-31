//
// Created by konstantin on 30.08.23.
//

#include "morseCode.h"

#define MORSE_TABLE_SIZE (36)
#define MORSE_WORD_LENGHT (6)

const char morseTable[MORSE_TABLE_SIZE][MORSE_WORD_LENGHT] =
{
    {".-"},   {"-..."}, {"-.-."}, {"-.."},  {"."},    {"..-."},  // A-F
    {"--."},  {"...."}, {".."},   {".---"}, {"-.-"},  {".-.."},  // G-L
    {"--"},   {"-."},   {"---"},  {".--."}, {"--.-"}, {".-."},   // M-R
    {"..."},  {"-"},    {"..-"},  {"...-"}, {".--"},  {"-..-"},  // S-X
    {"-.--"}, {"--.."}, {"-----"},{".----"},{"..---"},{"...--"}, // Y-3
    {"....-"},{"....."},{"-...."},{"--..."},{"---.."},{"----."}  // 4-9
};

void decryptChar(const char* morseChar, char* decryptChar)
{
    //*decryptChar = '?'; // character not found
    *decryptChar = *morseChar;
    for (int i = 0; i < MORSE_TABLE_SIZE; i++)
    {
        if (strcmp(morseChar, morseTable[i]) == 0)
        {
            if (i <= 26)
            {
                *decryptChar = (char)('A' + i);
                //return 'A' + i; // Возвращаем соответствующую латинскую букву
            }
            else
            {
                *decryptChar = (char)(i + DIGIT_OFFSET);
                //return '0' + i; // Возвращаем соответствующую цифру
            }
            i = MORSE_TABLE_SIZE;
        }
    }
}

void encodeToMorse(char* input, char* output) {

    printf("num of symbols = %lu\n", strlen(input));

    for (int i = 0; i < strlen(input); i++)
    {
        printf("input[i] = %d\n", input[i]);

        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            strcat(output, "|");
            strcpy(output, morseTable[input[i] - 'A']);
            strcat(output, "|");
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            strcat(output, "|");
            strcpy(output, morseTable[input[i] - 'a']);
            strcat(output, "|");
            printf("morseTable[input[i]] = %s\n", morseTable[input[i] - 'a']);
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            strcat(output, "|");
            strcpy(output, morseTable[input[i] - DIGIT_OFFSET]);
            strcat(output, "|");
            printf("morseTable[input[i]] = %s\n", morseTable[input[i] - DIGIT_OFFSET]);
        }
        else if (input[i] == 32)
        {
            printf("PROBEL\n");
            //output[0] = ' ';
            strcat(output, "  |");
        }
        else if (input[i] == 10)
        {
            output[0] = '\0';
            strcat(output,  " ");
        }
        else
        {
            //output[0] = '\0';
           strcpy(output, "?|");
           //strcat(output, "?");
        }
        output += strlen(output);
    }
}


