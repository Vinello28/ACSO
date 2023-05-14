//
// Created by Gabriele Vianello on 14/05/23.
//

#include "newlib.h"
#include "math.h"
#define HAT 777

int potenza(int base, int esponente){
    if(esponente==0)return 1;
    if(esponente<0) return 1/base*potenza(base, esponente+1);
    return base*potenza(base, esponente-1);
}

double radice(double x){
    if(x>=0)return sqrt(x);
    return HAT;
}

double log10(double x){
    return HAT;
}
