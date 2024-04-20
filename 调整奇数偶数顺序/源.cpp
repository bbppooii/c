#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void func(int arr[], int sz,int qwe[]){
    int zx = 5, qw = 0;
    for (int i= 0; i < sz; i++){
        if (arr[i] % 2 == 1) {
            for (int j = qw; j < 5; j++) {
                if (j==0) {
                    qwe[j] = arr[i];
                    qw++;
                    break;
                }
                else if(qwe[j-1] < arr[i]) {
                    qwe[j] = arr[i];
                    qw++;
                    break;
                }
            }
        }
        if (arr[i] % 2 == 0) {
            for (int j = zx; j < 10; j++) {
                if (j == 5) {
                    qwe[j] = arr[i];
                    zx++;
                    break;
                }
                else if (qwe[j] < arr[i]) {
                    qwe[j] = arr[i];
                    zx++;
                    break;
                }
            }
        }
    }
}
int main(){
    int arr[] = { 2,5,7,8,9,4,6,1,3,10 }; 
    int qwe[10] = { 0 };
    int sz=sizeof(arr)/sizeof(arr[0]);
    func(arr, sz, qwe);
    for (int i = 0; i < sz; i++){
        printf("%d ", qwe[i]);
    }
    return 0;
}
