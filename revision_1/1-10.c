#include <stdio.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\\')
            printf("%s", "\\\\");
        else if (c == '\t')
            printf("%s", "\\t");
        else if (c == '\b')
            printf("%s", "\\b");
        else
            printf("%c",c);
    }
}
