#include <stdio.h>

/*counts digits, whitespaces and other characters */
int main(void)
{
    int c, nw, no;
    nw = no = 0;
    int ndig[10];
    for (int i = 0; i < 10; i++)
        ndig[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
            ndig[c-'0']++;
        else if (c == ' ' || c == '\n' || c == '\t')
            nw++;
        else
            no++;
    }

    printf("No. of each digit: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d:%d\n", i, ndig[i]);
    }

    printf("Whitespace: %d\nOther: %d\n", nw, no);
}
