#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <cstring>
void qwe(char *in, int q,int z) {
    for (int i=0;i<q;i++) {
        in[z + i] = in[i];
    }
}
int main() {
    int a, b;
    char in[10000];
    gets_s(in);
    printf("¼¸¸ö");
    scanf("%d",&a);
    b = strlen(in);
    qwe(in, a, b);
    for (int i = a;i<b+a;i++) {
            printf("%c ", in[i]);
    }
    return 0;
}