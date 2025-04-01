#include <stdio.h>
#include <stdlib.h>

typedef struct dma {
  int dia;
  int mes;
  int ano;
  int feriado;
  char efemeride[50];
} dma;

void pegarData(dma *dma) {
  int diaMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  printf("Insira o ano: ");
  scanf("%i", &dma->ano);
  while (dma->ano < 1901 || dma->ano > 2100) {
    printf("Ano fora de escala, insira novamente: ");
    scanf("%i", &dma->ano);
  }

  if (dma->ano % 4 == 0) {
    diaMeses[1] = 29;
  }

  printf("Insira o mes: ");
  scanf("%i", &dma->mes);
  while (dma->mes < 1 || dma->mes > 12) {
    printf("Mes fora de escala, insira novamente: ");
    scanf("%i", &dma->mes);
  }

  printf("Insira o dia: ");
  scanf("%i", &dma->dia);
  while (dma->dia < 1 || dma->dia > diaMeses[dma->mes - 1]) {
    printf("Dia fora de escala, insira novamente: ");
    scanf("%i", &dma->dia);
  }

  printf("Insira se e feriado: ");
  scanf("%i", &dma->feriado);
  while (dma->feriado != 0 && dma->feriado != 1) {
    printf("Feriado fora de escala, insira novamente: ");
    scanf("%i", &dma->feriado);
  }

  if (dma->feriado == 1) {
    printf("Insira qual feriado: ");
    gets(dma->efemeride);
    gets(dma->efemeride);
  }
}

void mostrarData(dma *dma) {

  char meses[12][3] = {"jan", "fev", "mar", "abr", "mai", "jun",
                       "jul", "ago", "set", "out", "nov", "dez"};
  printf("%i/", dma->dia);
  for (int i = 0; i < 3; i++) {
    printf("%c", meses[dma->mes - 1][i]);
  }
  printf("/%i\n", dma->ano);
  if (dma->feriado == 1) {
    printf("Feriado: %s", dma->efemeride);
  }
}

int main() {

  dma dma;
  pegarData(&dma);
  mostrarData(&dma);
}
