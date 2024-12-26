#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("USAGE: ./cat FILENAME");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Could not open file!\n");
        return 2;
    }
    char c;
    while ((c = fgetc(f)) != EOF)
        putchar(c);
}
