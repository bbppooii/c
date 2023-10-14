#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    float b, sum = 0;
    for (a = 1; a <= 100; a++) {
        b = 1.0 / a;
        if (a % 2 == 0)
            sum = sum + b;
        else
            sum = sum - b;
    }
    printf("%f\n", sum);
    return 0;
}