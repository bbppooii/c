#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main() {
    char name[100]; 
    int votesLi = 0, votesZhang = 0, votesFun = 0;
    int n;
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    while (scanf("%s", name) != EOF) {
        if (strcmp(name, "Li") == 0) {
            votesLi++;
        }
        else if (strcmp(name, "Zhang") == 0) {
            votesZhang++;
        }
        else if (strcmp(name, "Fun") == 0) {
            votesFun++;
        }
    }
    printf("Li:%d\n", votesLi);
    printf("Zhang:%d\n", votesZhang);
    printf("Fun:%d\n", votesFun);
    return 0;
}
