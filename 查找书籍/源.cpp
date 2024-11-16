#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
typedef struct {
    char name[31];
    float price;
} Book;
int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input for n\n");
        return 1;
    }
    Book books[10];
    for (int i = 0; i < n; i++) {
        getchar(); 
        if (fgets(books[i].name, 31, stdin) == NULL) {
            fprintf(stderr, "Error reading book name\n");
            return 1;
        }
        books[i].name[strcspn(books[i].name, "\n")] = '\0'; 
        if (scanf("%f", &books[i].price) != 1) {
            fprintf(stderr, "Invalid input for book price\n");
            return 1;
        }
    }
    int maxi = 0, mini = 0;
    for (int i = 1; i < n; i++) {
        if (books[i].price > books[maxi].price) {
            maxi = i;
        }
        if (books[i].price < books[mini].price) {
            mini = i;
        }
    }
    printf("%.2f, %s\n", books[maxi].price, books[maxi].name);
    printf("%.2f, %s\n", books[mini].price, books[mini].name);
    return 0;
}
