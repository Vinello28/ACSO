/**
 * Created by Gabriele Vianello on 31/05/23.
 */

#include <stdio.h>

int main (int argc, char** argv){
    int i;
    for(i = 0; i<argc; i++)printf("\nSecondary Program - print argument %d: %s\n", i, argv[i]);
}