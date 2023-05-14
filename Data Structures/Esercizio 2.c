//
// Created by Gabriele Vianello on 14/05/23.
//

#include <stdio.h>
#include <stdint.h>

#define offsetof(st,m) ((size_t)&(((st*)0)->m))

typedef union myUnionType{
    int i;
    char b[4];
    float f;
}myUnion;

int main(){
    myUnion u;

    printf("size: %ld\n", sizeof(myUnion));
    printf("off a: %ld\n", offsetof(myUnion,i));
    printf("off b: %ld\n", offsetof(myUnion ,b));
    printf("off c: %ld\n", offsetof(myUnion ,f));

    u.i = 0x11223344;
    printf("I: 0x%02X 0x%02X 0x%02X 0x%02X\n",
           (uint8_t)u.b[0],
           (uint8_t)u.b[1],
           (uint8_t)u.b[2],
           (uint8_t)u.b[3]
           );
    return 0;
}