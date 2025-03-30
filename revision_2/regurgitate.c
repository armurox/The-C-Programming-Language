#include <stdio.h>

int main(void)
{
    char c;
    while ((c = getchar()) != EOF)
        putchar(c);
    printf("The program has been terminated!\n");
}
