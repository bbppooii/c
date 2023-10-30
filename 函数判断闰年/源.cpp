#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int m(int year) {
   
    if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0) {
        return 1;
    }
    

    return 0;

}
   
int main() {

    int q = 0;

    scanf("%d", &q);

    int x=m(q);
    if (x == 1) {
        printf("ÊÇ");
    }
    else
        printf("²»ÊÇ");
    return 0;

}