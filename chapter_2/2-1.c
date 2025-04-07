#include <stdio.h>

int main(void)
{
    char c;
    unsigned char uc = 0;
    unsigned char prev_uc = uc;
    signed char sc;
    unsigned int ui;
    signed int si;
    unsigned short usi;
    signed short ssi;
    unsigned long uli;
    signed long sli;
    for (c = 0; c >= 0; c++)
        ;
    for (uc = 0; uc >= prev_uc; uc++)
        prev_uc = uc;
    for (sc = 0; sc >= 0; sc++)
        ;
    printf("char range is: %d to %d\n", c, (char) (c - 1));
    printf("unsigned char range is: %d to %d\n", (unsigned char) (uc), (unsigned char) prev_uc);
    printf("unsigned char range is: %d to %d\n", sc, (unsigned char) (sc - 1));
}
