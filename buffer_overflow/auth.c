#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char password[16];
    int passcheck = 0;
    int penalty = 0;

    FILE *creds;
    creds = fopen("./credentials.txt","r");
    char pass[18];
    fgets(pass,18,creds);

    while(1) {

        printf("\n$Password:\t");
        gets(password);
        
        if(strcmp(password, pass) == 0) 
        {
            printf("\nAccess Granted\n");
            passcheck = 1;
        } else {
            printf("\nAccesso negato\n\nRitenta tra poco\n");
            penalty = 1;
        }

        if(passcheck) 
        {
            // system("cat ./flag.txt");
            FILE *flag = fopen("./flag.txt","r");
            char buff[40];
            fgets(buff,40,flag);
            printf("%s\n",buff);
            break;
        }

        if(penalty == 1) {
            sleep(10);
            penalty = 0;
        }
    }

    return EXIT_SUCCESS;

}