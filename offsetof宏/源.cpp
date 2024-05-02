#define _CRT_SECURE_NO_WARNINGS 1 
#define OFFSET_OF(type, member) ((size_t)(&((type *)0)->member))  
#include <stdio.h>
struct ExampleStruct {
    int var1;
    char var2;
    float var3;
};
int main() {
    printf("Offset of var1: %zu bytes\n", OFFSET_OF(struct ExampleStruct, var1));
    printf("Offset of var2: %zu bytes\n", OFFSET_OF(struct ExampleStruct, var2));
    printf("Offset of var3: %zu bytes\n", OFFSET_OF(struct ExampleStruct, var3));
    return 0;
}
