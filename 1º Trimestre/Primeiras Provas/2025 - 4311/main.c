#include <stdio.h>
#include <stdlib.h>

float saidaVDiv(float Vin, float R1, float R2);
float caldRVDiv(float Vin, float Vout, float R1);
float VDiv(float *Vin, float *Vout, float *R1, float *R2);

int main() {
    float vin, vout, r1, r2, on = 1;

    do {
        printf("Digite o valor da tensao da fonte: ");
        scanf("%f", &vin);
        printf("Digite o valor do resistor r1: ");
        scanf("%f", &r1);
        printf("Digite o valor do resistor r2: ");
        scanf("%f", &r2);
        printf("Digite o valor da tensao de saida: ");
        scanf("%f", &vout);

        if (VDiv(&vin, &vout, &r1, &r2) == 0) {
            printf("Tensao da fonte: %.2f \r\n", vin);
            printf("R1: %.2f \r\n", r1);
            printf("R2: %.2f \r\n", r2);
            printf("Tensao de saida: %.2f \r\n", vout);

            on = 0;
        } else if (VDiv(&vin, &vout, &r1, &r2) == -1) {
            printf("Tensao da fonte: %.2f \r\n", vin);
            printf("R1: %.2f \r\n", r1);
            printf("R2: %.2f \r\n", r2);
            printf("Tensao de saida: %.2f \r\n", vout);
            printf("Vout in X Vout Calc: %.2f X %.2f \r\n", vout, saidaVDiv(vin, r1, r2));

            on = 0;
        } else if (VDiv(&vin, &vout, &r1, &r2) == -2) {
            printf("Os valores de R1 e R2 nao foram digitados, por favor, digite novamente! \r\n");
        } else if (VDiv(&vin, &vout, &r1, &r2) == -3) {
            printf("Nao ha informacoes suficientes para o calculo, por favor, digite novamente! \r\n");
        }
    } while (on == 1);

    return 0;
}

float saidaVDiv(float Vin, float R1, float R2) {
    return (Vin * (R2 / (R1 + R2)));
}

float caldRVDiv(float Vin, float Vout, float R1) {
    return (Vout * (R1 / (Vin - Vout)));
}

float VDiv(float *Vin, float *Vout, float *R1, float *R2) {
    //errors
    if ((*Vin == 0 && *Vout == 0) || (*Vout == 0 && *R2 == 0) || *Vin == 0 || *R1 == 0) return -3;
    else if (*R1 == 0 && *R2 == 0) return -2; 
    else if (*Vin != 0 && *Vout != 0 && *R1 != 0 && *R2 != 0) return -1;
    
    else if (*Vout == 0) *Vout = saidaVDiv(*Vin, *R1, *R2);
    else if (*R2 == 0) *R2 = caldRVDiv(*Vin, *Vout, *R1);

    // extras
    // se esses forem adicionados, tem que verificar se so um
    // dos outros campos foi deixado como zero
    
    //else if (*Vin == 0) *Vin = (*Vout / (*R2 / (*R1 + *R2)));
    //else if (*R1 == 0) *R1 = ((*R2 * (*Vin - *Vout)) / *Vout);
    
    return 0;
}