#include <stdio.h>
#include <stdlib.h>
int main()
{
    int b, a, max = 0;
    for (a = 1; a <= 10; a++) {
        b = rand() % 100;
        printf("%d  ", b);
        if (b > max)
            max = b;
    }
    printf("\n");
    printf("%d\n", max);
    return 0;
}