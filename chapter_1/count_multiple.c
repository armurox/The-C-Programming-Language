#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    long nl, nw, nc;
    int state = OUT;
    nl = nw = nc = 0;
    int c;
    while ((c = getchar()) != EOF)
    {   
        nc++;
        if (c == '\n')
        {
            nl++;
            if (state == IN)
                nw++;
                state = OUT;
        }
        else if (c != '\t' && c != ' ')
            state = IN;
        else if (state == IN)
        {
            nw++;
            state = OUT;
        }
            
    }

    printf("%ld %ld %ld\n", nl, nw, nc);
}
