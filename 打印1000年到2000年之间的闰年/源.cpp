#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;
    for (a = 1000; a <= 2000; a++) {
        if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
            printf("%d ", a);
    }
    return 0;
}