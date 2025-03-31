#include <stdio.h>

#define MIN_F 0
#define MAX_F 300
#define STEP_SIZE 20

float f_to_c(float f);

int main(void)
{
    for (float f = MIN_F; f <= MAX_F; f += STEP_SIZE)
    {
        printf("%3.0f %6.1f\n", f, f_to_c(f));
    }

}

float f_to_c(float f)
{
    return (5.0 * (f - 32.0)) / 9.0;
}
