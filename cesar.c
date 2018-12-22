#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LEN 100

int key;

char encrypt(char *text);
char decrypt(char *text);

int main(int argc, const char *argv[])
{
    char text[STR_LEN];
    char (*fun_ptr) (char[]);

    if (argc != 3) {
        printf("Usage: ./cesar int <e/d>\n");
        return 1;
    }

    switch (argv[2][0]) {
        case 'e':
                fun_ptr = &encrypt;
                break;
        case 'd':
                fun_ptr = &decrypt;
                break;
        default:
            printf("Usage: ./cesar int <e/d>\n");
            return 1;
    }

    key = atoi(argv[1]);
    printf("Please enter a text[%d]:\n", STR_LEN);
    fgets(text, STR_LEN, stdin);
    char output = (*fun_ptr)(text);
    printf("%s\n", text);


    return 0;
}

char encrypt(char *text)
{
    char output[STR_LEN];
    for (int i = 0; i < STR_LEN; ++i)
    {
        if (text[i] != '\0') {
            output[i] = text[i];
        } else {
            break;
        }
    }
    return *output;
}

char decrypt(char *text)
{


}