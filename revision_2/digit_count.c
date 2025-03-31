#include <stdio.h>

int main(void)
{
    int nwhite, nother;
    int ndigit[10];
    // Initialization
    nwhite = nother = 0;
    for (int i = 0; i < 10; i++)
        ndigit[i] = 0;
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ndigit[c - '0']++;
        else if (c == ' ' || c == '\t' || c == '\n')
            nwhite++;
        else
            nother++;
    }

    printf("No. of each digit:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", i, ndigit[i]);
    }

    printf("No. of whitespace characters: %d\nNo. of other characters: %d\n", nwhite, nother);

}
