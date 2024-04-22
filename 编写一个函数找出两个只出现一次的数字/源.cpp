#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void finddog(int a[], int sz, int* num){
    int i = 0;
    int pos = 0;
    int ret = 0;
    for (i = 0; i < sz; i++){
        ret ^= a[i];
    }
    for (pos = 0; pos < 32; pos++){
        if (((ret >> pos) & 1) == 1){
            break;
        }
    }
    for (i = 0; i < sz; i++){
        if (((a[i] >> pos) & 1) == 1)
        {
            num[1] ^= a[i];
        }
        else{
            num[0] ^= a[i];
        }
    }
}
int main(){
    int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
    int num[2] = { 0 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    finddog(arr, sz, num);
    printf("%d %d\n", num[0], num[1]);
    return 0;
}
