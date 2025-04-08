#include <stdio.h>
#include <math.h>

int main(void)
{
    char c;
    unsigned char uc = 0;
    unsigned char prev_uc = uc;
    signed char sc;
    unsigned int ui = 0;
    unsigned int prev_ui = ui;
    signed int si;
    unsigned short usi = 0;
    unsigned int prev_usi = usi;
    signed short ssi;
    unsigned long uli = 0;
    unsigned long prev_uli = uli;
    signed long sli;
    float f = 0;
    for (c = 0; c >= 0; c++)
        ;
    for (uc = 0; uc >= prev_uc; uc++)
        prev_uc = uc;
    for (sc = 0; sc >= 0; sc++)
        ;
    for (ui = 0; ui >= prev_ui; ui++)
        prev_ui = ui;
    for (usi = 0; usi >= prev_usi; usi++)
        prev_usi = usi;
    for (si = 0; si >= 0; si++)
        ;
    printf("char range is: %d to %d\n", c, (char) (c - 1));
    printf("unsigned char range is: %d to %d\n", (unsigned char) (uc), (unsigned char) prev_uc);
    printf("signed char range is: %d to %d\n", sc, (unsigned char) (sc - 1));
    printf("unsigned int range is: %u to %u\n", ui, prev_ui);
    printf("unsigned short range is: %u to %u\n", usi, prev_usi);
    printf("signed int range is: %d to %d\n", si, si - 1);
    printf("unsigned long range is: %lu to %lu\n", (unsigned long) 0, (unsigned long) pow(2, (8 * sizeof(unsigned long))));  // To avoid a very long runtime

}
