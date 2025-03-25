#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ehTrIso(float ladoA, float ladoB, float ladoC);
float areaTrIso(float ladoA, float ladoB, float ladoC);
int trIso(float *ladoA, float *ladoB, float *ladoC);

int main() {
    float ladoA, ladoB, ladoC;
    
    printf("Digite o tamanho do lado A: ");
    scanf("%f", &ladoA);
    printf("Digite o tamanho do lado B: ");
    scanf("%f", &ladoB);
    printf("Digite o tamanho do lado C: ");
    scanf("%f", &ladoC);

    /*
        DISCLAIMER
        no enunciado, pode ser interpretado que a funcao
        trIso deva ser chamada antes da 
        verificacao se um dos lados eh ou nao zero

        para simplificacao do codigo, chamarei a funcao apenas
        caso um dos lados seja identificado como zero
        
        juntamente disso, o retorno -1 da funcao trIso
        se torna inutil e sera ignorado 
        (o retorno -2 tmb vai ser ignorado, 
        mas por motivos de muita mao (preguica))
    */

    if (ladoA == 0 || ladoB == 0 || ladoC == 0) {
        trIso(&ladoA, &ladoB, &ladoC);
        printf("Area: %.4f \r\n", areaTrIso(ladoA, ladoB, ladoC));
    } else {
        ehTrIso(ladoA, ladoB, ladoC);
    }
    printf("Lado A: %.2f \r\n", ladoA);
    printf("Lado B: %.2f \r\n", ladoB);
    printf("Lado C: %.2f \r\n", ladoC);
}

int trIso(float *ladoA, float *ladoB, float *ladoC) {
    float arr[3] = {*ladoA, *ladoB, *ladoC};
    for (int i = 0; i < 2; i++) {
        if (arr[i] > arr[i + 1]) {
            int aux = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = aux;
            i = -1;
        }
    }

    if (*ladoA == 0) *ladoA = arr[0];
    if (*ladoB == 0) *ladoB = arr[0];
    if (*ladoC == 0) *ladoC = arr[0];
    return 0;
}

int ehTrIso(float ladoA, float ladoB, float ladoC) {
    if ((ladoA == ladoB) || (ladoA == ladoC) || (ladoB == ladoC)) {
        return 1;
    } else return 0;
}

float areaTrIso(float ladoA, float ladoB, float ladoC) {
    float arr[3] = {ladoA, ladoB, ladoC};
    for (int i = 0; i < 2; i++) {
        if (arr[i] < arr[i + 1]) {
            int aux = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = aux;
            i = -1;
        }
    }
    
    float h = sqrt(pow(arr[0],2) - (pow(arr[2], 2)/4));
              //sqrt(pow(ladoA, 2) - (pow(ladoB,2)/4))
    float a = (h*arr[2])/2; //(h.ladoB)/2
    return a;
}