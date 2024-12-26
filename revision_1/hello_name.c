#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: ./hello_name FIRST_NAME LAST_NAME\n");
        return 1;
    }

    printf("Hello, %s %s\n", argv[1], argv[2]);
}
