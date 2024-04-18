#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int find_single(int arr[], int sz){
    int ret = 0;
    int i = 0;
    for (i = 0; i < sz; i++){
        ret ^= arr[i];
    }
    return ret;
}
int main(){
    int arr[] = { 1,2,3,5,1,2,3,4,4,6,6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int single = find_single(arr, sz);
    printf("%d\n", single);
    return 0;
}