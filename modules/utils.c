//
// Created by konstantin on 31.08.23.
//

#include "utils.h"
#include "../modules/morseCode.h"

void getAppParam(int argc, char **argv, CURRENT_TYPE_APP_t* currentTypeApp)
{
    for (int i=1; i<(argc); i++)
    {
        if (argv[i]==NULL || argv[i][0] != '-')
            break;
        switch (argv[i][1])
        {
            case 'c':
            case 'C':
            {
                currentTypeApp->appType = CLIENT;
                currentTypeApp->numClient = 0;
            }
            break;

            case 's':
            case 'S':
            {
                currentTypeApp->appType = SERVER;

                if (argv[2] == NULL)
                {
                    fprintf(stderr,"NEEDED set Number of Client, by default set to 1:\n");
                    currentTypeApp->numClient = 1;
                }
                else
                {
                    long numClient = strtol(argv[2],  NULL, 10);

                    if (numClient <= 0 || numClient > 255)
                    {
                        printf("Number of client is wrong, possible value is: 1...255\n");
                        exit(1);
                    }
                    else
                    {
                        currentTypeApp->numClient = (unsigned char)numClient;
                    }
                }
            }
            break;

            default:
                fprintf(stderr,"%s: %c: unknown option (possible 's' or 'c')\n",argv[0], argv[i][1]);
                exit(1);
        }
    }
    printf("type = %d \t clients = %d \n", currentTypeApp->appType, currentTypeApp->numClient);
}

void receive_message(char* encodedMassage)
{
    char message[100];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    //printf("Received message: %s\n", message);
    //strcat(message, "\0");
    encodeToMorse(message, encodedMassage);
    printf("Результат шифрования: %s\n", encodedMassage);

}

void getDecodeMsg(char* input)
{
    const char charDelimiter[] = "|";
    const char worldDelimiter[] = " ";

    char findCharacter;
    char* token = strtok((char*)input, charDelimiter); // Разбиваем строку на символы морзе по разделителю
    printf("\nFind character \n");
    while (token != NULL)
    {
        decryptChar(token, &findCharacter);
        token = strtok(NULL, charDelimiter); // Получаем следующий символ морзе
        printf("%c", findCharacter);
    }

    printf("\n"); // Переходим на новую строку после дешифрования
}


