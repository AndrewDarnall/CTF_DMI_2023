#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 3334
#define BUFFLEN 30
#define MAX_CONN 10

int main(int argc, char** argv)
{

    int sockfd, newsockfd, n;
    struct sockaddr_in remote_addr;
    socklen_t len;
    char sendline[BUFFLEN];
    char recvline[BUFFLEN];

    printf("Server listening on port [%d]\n",PORT);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&remote_addr, 0, sizeof(struct sockaddr_in));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    remote_addr.sin_port = htons(PORT);

    if(bind(sockfd, (struct sockaddr*)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("bind");
        exit(1);
    }


    listen(sockfd, MAX_CONN);

    while(1) {

        len = sizeof(remote_addr);
        if((newsockfd = accept(sockfd, (struct sockaddr*)&remote_addr, &len)) < 0) {
            perror("accept");
            exit(1);
        }

        if(fork() == 0) {

            close(sockfd);

            //Non ho messo un loop poiche' so di dover ricevere una sola stringa!
            while(1)
            {
                strcpy(sendline,"$Password:");
                strcat(sendline,"\r\n");
                send(newsockfd, sendline, strlen(sendline), 0);
                n = recv(newsockfd, recvline, BUFFLEN, 0);
                recvline[n] = '\0';

                char pass[18];
                gets()
                if(strcmp(recvline,"close\r\n") == 0) {
                    strcpy(sendline,"Connection Closed");
                    strcat(sendline,"\r\n");
                    send(newsockfd, sendline, strlen(sendline), 0);
                    close(newsockfd);
                    exit(0);
                }

                // char password[16];
                int passcheck = 0;

                FILE *creds;
                creds = fopen("./credentials.txt","r");
                char pass[18];
                fgets(pass,18,creds);

                if(strcmp(recvline, pass) == 0) 
                {
                    printf("strcmp(%s,%s) = %d",recvline,pass,strcmp(recvline,pass));
                    // printf("\nAccesso negato\n\nRitenta tra poco\n");
                    strcpy(sendline,"Access Granted");
                    strcat(sendline,"\r\n");
                    send(newsockfd, sendline, strlen(sendline), 0);
                    passcheck = 1;
                } else {
                    strcpy(sendline,"Ritenta tra poco");
                    strcat(sendline,"\r\n");
                    send(newsockfd, sendline, strlen(sendline), 0);
                    sleep(10);
                    // printf("\nAccess Granted\n");
                }

                if(passcheck) 
                {
                    system("cat ./flag.txt");
                    printf("\n");
                    char buff[20];
                    FILE *fh;
                    fh = fopen("./flag.txt","r");
                    fgets(buff,20,fh);
                    strcpy(sendline,buff);
                    strcat(sendline,"\r\n");
                    send(newsockfd, sendline, strlen(sendline), 0);
                }

                printf("From:\t%s\t%s\n",inet_ntoa(remote_addr.sin_addr),recvline);
                // strcpy(sendline,"OK");
                // strcat(sendline,"\r\n");
                // send(newsockfd, sendline, strlen(sendline), 0);
            }

            exit(0);

        } else {

            close(newsockfd);

        }

    }


    return EXIT_SUCCESS;
}