#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b = 0;
    for (a = 1; a <= 100; a++) {
        if (a % 10 == 9)
            b++;
        else if (a / 10 == 9)
            b++;
    }
    printf("%d", b);
    return 0;
}