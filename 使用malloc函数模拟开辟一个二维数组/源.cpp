#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main() {
    int(*a)[5] = (int(*)[5])malloc(sizeof(int)*3*5);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%p\n", &a[i][j]); 
        }
    }
    return 0;
}