#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LEN 100

int key;

char* encrypt(char* text);
char* decrypt(char* text);

int main(int argc, const char* argv[])
{
    char text[STR_LEN];
    char* (*fun_ptr) (char*);

    if (argc != 3) {
        printf("Usage: ./cesar +int <e/d>\n");
        return 1;
    }

    key = atoi(argv[1]);

    if (key < 1) {
        printf("Key must be positive!\n");
        return 1;
    }

    switch (argv[2][0]) {
        case 'e':
                fun_ptr = encrypt;
                break;
        case 'd':
                fun_ptr = decrypt;
                break;
        default:
            printf("Usage: ./cesar int <e/d>\n");
            return 1;
    }

    printf("Please enter a text[%d]:\n", STR_LEN);
    fgets(text, STR_LEN, stdin);

    char *output = { (fun_ptr)(text) };
    printf("%s\n", output);


    return 0;
}

char* encrypt(char* text)
{
    int ascii_start_number;
    static char output[STR_LEN];
    int raw_char;

    for (int i = 0; i < STR_LEN; ++i)
    {
        raw_char = text[i];
        if (isalpha(raw_char)) {
            ascii_start_number = isupper(raw_char) ? 65 : 97;
            output[i] = (((raw_char - ascii_start_number) + key) % 26) + ascii_start_number;
        } else {
            output[i] = raw_char;
        }
    }

    return output;
}

char* decrypt(char* text)
{
    int ascii_start_number;
    static char output[STR_LEN];
    int raw_char;

    for (int i = 0; i < STR_LEN; ++i)
    {
        raw_char = text[i];
        if (isalpha(raw_char)) {
            ascii_start_number = isupper(raw_char) ? 65 : 97;
            output[i] = (((raw_char - ascii_start_number) - (key % 26) + 26) % 26) + ascii_start_number;
        } else {
            output[i] = raw_char;
        }
    }

    return output;
}