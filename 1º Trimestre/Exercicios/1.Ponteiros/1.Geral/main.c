#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*  1.
    i = 0 vet[0] = 1.1 *(f + 0) = 1.1 &vet[0] = "endereço de vet[0]" (f + 0) = "endereço de vet[0]"
    i = 1 vet[1] = 2.2 *(f + 1) = 2.2 &vet[1] = "endereço de vet[1]" (f + 1) = "endereço de vet[1]"
    i = 2 vet[2] = 3.3 *(f + 2) = 3.3 &vet[2] = "endereço de vet[2]" (f + 2) = "endereço de vet[2]"
    i = 3 vet[3] = 4.4 *(f + 3) = 4.4 &vet[3] = "endereço de vet[3]" (f + 3) = "endereço de vet[3]"
    i = 4 vet[4] = 5.5 *(f + 4) = 5.5 &vet[4] = "endereço de vet[4]" (f + 4) = "endereço de vet[4]"
*/

void troca(int* p1, int* p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;

    printf("primeiro: %i \n", *p1);
    printf("segundo: %i \n", *p2);
}

int ordena(int* n1, int* n2, int* n3, char ordem) {
    int sort[] = { *n1, *n2, *n3 };

    switch (ordem) {
    case 'C':
    case 'c':
        for (int i = 0; i < 2; i++) {
            if (sort[i] > sort[i + 1]) {
                int aux = sort[i];
                sort[i] = sort[i + 1];
                sort[i + 1] = aux;
                i = -1;
            }
        }

        for (int i = 0; i < 3; i++) {
            printf("%i ", sort[i]);
        }
        printf("\n");

        break;
    case 'D':
    case 'd':
        for (int i = 0; i < 2; i++) {
            if (sort[i] < sort[i + 1]) {
                int aux = sort[i];
                sort[i] = sort[i + 1];
                sort[i + 1] = aux;
                i = -1;
            }
        }

        for (int i = 0; i < 3; i++) {
            printf("%i ", sort[i]);
        }
        printf("\n");
        break;
    default:
        return -1;
        break;
    }
}

int sinal(float* f, float* p) {
    if (*f == 0 && *p == 0) {
        return -1;
    }
    else if (*f == 0) {
        *f = 1 / (*p);
        printf("\n%.2f Hz\n", *f);
    }
    else if (*p == 0) {
        *p = 1 / (*f);
        printf("\n%.2f s\n", *p);
    }
}

int trianguloRetangulo(float* co, float* ca, float* h) {
    if (*co == 0 && *ca == 0 && *h == 0) {
        return -1;
    }
    else if (*co == 0 && *ca != 0 && *h != 0) {
        *co = sqrtf(powf(*h, 2) - powf(*ca, 2));
        printf("\n%.2f\n", *co);
    }
    else if (*co != 0 && *ca == 0 && *h != 0) {
        *ca = sqrtf(powf(*h, 2) - powf(*co, 2));
        printf("\n%.2f\n", *ca);
    }
    else if (*co != 0 && *ca != 0 && *h == 0) {
        *h = sqrtf(powf(*ca, 2) + powf(*co, 2));
        printf("\n%.2f\n", *h);
    }
}

void divisorTensao(float *ve, float *vs, float *r1, float *r2) {
    float i, vr1;
    
    if (*vs > *ve) {
        return -2;
    } else if (r1 == 0 && r2 == 0) {
        return -1;
    } else {
        if (*r1 == 0) {
            *r1 = *r2;
        }
        if (*r2 == 0) {
            *r2 = *r1;
        }

        i = *ve / (*r1 + *r2);
        vr1 = *ve - *vs;
        
        printf("Tensao de entrada: %.2f V\n", *ve);
        printf("Tensao de saida (Vr2): %.2f V\n", *vs);
        printf("Tensao Vr1: %.2f V\n", vr1);
        printf("Corrente total: %.2f mA\n", ((i)*1000));
        printf("Resistencia R1: %.2f Ohms\n", *r1);
        printf("Resistencia R2: %.2f Ohms\n", *r2);

        return 0;
    }
}

void ordena_alfa(char *p1, char *p2) {
    if (strcmp(p1, p2) > 0) {
        printf("\n");
        for (int i = 0; *(p2 + i) != '\0'; i++) {
            printf("%c", *(p2 + i));
        }
        printf("\n");
        for (int i = 0; *(p1 + i) != '\0'; i++) {
            printf("%c", *(p1 + i));
        }
        printf("\n");
    }
    else {
        printf("\n");
        for (int i = 0; *(p1 + i) != '\0'; i++) {
            printf("%c", *(p1 + i));
        }
        printf("\n");
        for (int i = 0; *(p2 + i) != '\0'; i++) {
            printf("%c", *(p2 + i));
        }
        printf("\n");
    }
}

int main(void) {
    char str1[50], str2[50], lixo[50], o;
    int swipe[2], sort[3];
    float f, p, co, ca, h, ve, vs, r1, r2;

    printf("2. Digite dois numeros\n");
    for (int i = 0; i < 2; i++) {
        scanf_s("%i", &swipe[i]);
    }
    troca(&swipe[0], &swipe[1]);

    printf("3. Digite tres numeros\n");
    for (int i = 0; i < 3; i++) {
        scanf_s("%i", &sort[i]);
    }
    printf("\nDigite ''c'' para ordenar de forma crescente e ''d'' para decrescente\n");
    scanf_s(" %c", &o);
    ordena(&sort[0], &sort[1], &sort[2], o);

    printf("4. Digite uma frequencia e um periodo\n");
    scanf_s("%f %f", &f, &p);
    sinal(&f, &p);

    printf("5. Digite um cateto oposto, um cateto adjascente e uma hipotenusa\n");
    scanf_s("%f %f %f", &co, &ca, &h);
    trianguloRetangulo(&co, &ca, &h);

    printf("5. Digite a tensao de entrada\n");
    scanf_s("%f", &ve);
    printf("5. Digite a tensao de saida\n");
    scanf_s("%f", &vs);
    printf("5. Digite a resistencia do divisor\n");
    scanf_s("%f", &r1);
    printf("5. Digite a resistencia que sera analisada\n");
    scanf_s("%f", &r2);
    divisorTensao(&ve, &vs, &r1, &r2);
    printf("\n");

    printf("6. Digite duas palavras\n");
    gets_s(lixo, 50); //tava dando problema com a entrada
    gets_s(str1, 50);
    gets_s(str2, 50);
    ordena_alfa(str1, str2);
}