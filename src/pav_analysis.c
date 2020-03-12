#include <math.h> 
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) { 
    float suma = 0;
    float resultado=0;
    for (int i=0; i<N; i++) {
        suma = suma + x[i]*x[i];
    }
    resultado = 10*log10(1.0/N*suma);
    return resultado;
}
float compute_am(const float *x, unsigned int N) { 
    float suma = 0;
    for(int i=0; i<N; i++){
        if(x[i] >= 0){
            suma += x[i];
        }
        else{
            suma += x[i]*(-1.0);
        }
    }
    float resultado = (1.0/N)*suma;
    return resultado;
}
float compute_zcr(const float *x, unsigned int N, float fm) { 
    int suma = 0;
    for(int i=0; i<N; i++){
        if((x[i-1]*x[i])<0){
            suma += 1;
        }
    }
    float resultado = ((8000/(N-1)))*suma;
    return resultado;
}

