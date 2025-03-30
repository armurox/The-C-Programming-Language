#include <stdio.h>

#define MIN_C -17.8
#define MAX_C 148.9
#define STEP_SIZE 11.1

int main(void)
{
    printf("%5c %4c\n", 'F', 'C');
    for (float c = MIN_C; c <= MAX_C; c += STEP_SIZE)
        printf("%5.1f %4.0f\n", c, (int) ((9.0 / 5.0) * c) + 32.0);
}
