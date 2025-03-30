#include <stdio.h>

#define MIN_F 0
#define MAX_F 300
#define STEP_SIZE 20

int main(void)
{
    printf("%3c %5c\n", 'C', 'F');
    for (float f = MIN_F; f <= MAX_F; f += STEP_SIZE)
    {
        printf("%3.0f %6.1f\n", f, (5.0 * (f - 32.0)) / 9.0);
    }

}
