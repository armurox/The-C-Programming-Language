#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./cat [FILENAME]\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not find / open file %s!\n", argv[1]);
        return 2;
    }

    char c;
    while ((c = fgetc(f)) != EOF)
        putchar(c);
}
