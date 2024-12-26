#include <stdio.h>

#define STEP 20.0
#define LOWER 0.0
#define UPPER 150.0

int main(void)
{
    printf("%3c\t%5c\n", 'C', 'F');
    for (float c = LOWER; c < UPPER; c += STEP)
    {
        printf("%3.0f\t%6.1f\n", c, ((9.0 / 5.0) * c) + 32);
    }
}
