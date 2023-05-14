//
// Created by Gabriele Vianello on 14/05/23.
//

#include <stdio.h>

#define offsetof(st, m) ((size_t)&(((st*)0)->m))

typedef struct myStructType{
    char b;
    int a;
    char c;
} myStruct;

int main(){
    printf("size: %ld\n", sizeof(myStruct));
    printf("off a: %ld\n", offsetof(myStruct,a));
    printf("off b: %ld\n", offsetof(myStruct,b));
    printf("off c: %ld\n", offsetof(myStruct,c));
    return 0;
}