#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int t(int x[],int z) {
    for (int i = 0; i < z;i++) {
        x[i] = 0;  
    }
    return 0;
}
int print(int a[],int z) {
    for (int i = 0; i < z; i++) {
        printf("%d ", a[i]);
    } 
    return 0;
}
int reverse(int x[], int z) {
    int b[20];
    for (int i = 0; i < z; i++) {
        b[z - i - 1] = x[i];   
    }
    for (int i = 0; i < z; i++) {
        x[i] = b[i];
    }
    return 0;
}
int main() {
    int a[5] = {1,2,3,4,5};
    print(a, sizeof(a) / sizeof(a[0]));
    printf("\n");
    reverse(a, sizeof(a) / sizeof(a[0]));
    print(a, sizeof(a) / sizeof(a[0]));
    printf("\n");
    t(a, sizeof(a)/sizeof(a[0]));
    print(a, sizeof(a) / sizeof(a[0]));
    return 0;
}