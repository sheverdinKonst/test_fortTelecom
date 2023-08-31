
#include "../modules/morseCode.h"
#include "../modules/utils.h"
#include "../modules/server.h"
#include "../modules/client.h"

int main(int argc, char **argv) {

    printf("Hello, client app with sending message in Morse code!\n");
    CURRENT_TYPE_APP_t currentTypeApp =
    {
        .appType = SERVER,
        .numClient = 1
    };

    getAppParam(argc, argv, &currentTypeApp);

    switch (currentTypeApp.appType)
    {
        case SERVER:
        {
            if (server_error == serverInit())
            {
                exit(server_error);
            }
            else
            {
                while(1)
                {
                    serverHandler(currentTypeApp.numClient);
                }
            }
        }
        break;

        case CLIENT:
        {
            if (client_error == clientApp())
            {
                exit(client_error);
            }
        }
        break;

        default:
            printf("Error Default state\n");
        break;
    }

    return 0;
}
