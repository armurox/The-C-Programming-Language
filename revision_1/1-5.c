#include <stdio.h>

#define STEP 20.0
#define LOWER 0.0
#define UPPER 300

int main(void)
{
    printf("%3c\t%5c\n", 'F', 'C');
    for (float c = UPPER; c >= LOWER; c -= STEP)
    {
        printf("%3.0f\t%6.1f\n", c, (5.0 / 9.0) * (c - 32));
    }
}
