#include <stdio.h>
#include <string.h>


int main()
{
    char buff[20];
    printf("Password:\t");
    gets(buff);
    printf("%d",strcmp(buff,"salve"));

    if (strcmp(buff,"salve")) {
        printf("Correct");
    } else {
        printf("Wrong");
    }

    return 0;

}