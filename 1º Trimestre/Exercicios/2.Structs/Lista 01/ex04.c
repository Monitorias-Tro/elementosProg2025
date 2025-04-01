#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 2

typedef struct informacoesPessoas {
  int idade;
  char sexo;
  char corOlhos;
  char corCabelo;
} infoPessoa;

int pegarInfo(infoPessoa *lista, int tam) {

  if (tam > CAPACIDADE) {
    return -1;
  }
  printf("\nInsira a idade: ");
  scanf("%i", &lista[tam - 1].idade);
  printf("\nInsira o sexo (M/F): ");
  scanf(" %c", &lista[tam - 1].sexo);
  printf("\nInsira a cor dos olhos: ");
  scanf(" %c", &lista[tam - 1].corOlhos);
  printf("\nInsira a cor do cabelo: ");
  scanf(" %c", &lista[tam - 1].corCabelo);
  return 1;
}

void relatorio(infoPessoa *lista, int tam) {
  float mediaIdadeGeral = 0, mediaIdadeFem = 0, mediaIdadeMas = 0;
  int quantidadeFem = 0, quantidadeMas = 0, quantidadeCabeloLoiro = 0;

  if ((tam - 1) == 0) {
    printf("Valores ainda nao foram adicionados\n");
    return;
  }
  printf("Numero de individuos pesquisados: %i\n", tam - 1);
  for (int i = 0; i < tam; i++) {

    if (lista[i].sexo == 'M') {
      mediaIdadeMas = mediaIdadeMas + lista[i].idade;
      quantidadeMas++;
    } else if (lista[i].sexo == 'F') {
      mediaIdadeFem = mediaIdadeFem + lista[i].idade;
      quantidadeFem++;
    }
  }

  mediaIdadeGeral = (mediaIdadeFem + mediaIdadeMas) / (tam - 1);
  mediaIdadeFem = mediaIdadeFem / quantidadeFem;
  mediaIdadeMas = mediaIdadeMas / quantidadeMas;

  printf("Media de Idade Geral: %.2f\n", mediaIdadeGeral);
  printf("Media de Idade Masculina: %.2f\n", mediaIdadeMas);
  printf("Media de Idade Feminina: %.2f\n", mediaIdadeFem);
}

int main() {

  infoPessoa infoPessoa[10];
  bool sairMenu = true;
  int selecaoMenu, tam = 1, ret;

  do {
    printf("Bem Vindo ao Censo Demografico!\n");
    printf("Menu de Opcoes:\n");
    printf("1 - Realizar pesquisa\n");
    printf("2 - Exibir Relatorio\n");
    printf("3 - Sair\n");
    printf("Insira sua opcao: ");
    scanf("%i", &selecaoMenu);

    while (selecaoMenu != 1 && selecaoMenu != 2 && selecaoMenu != 3) {
      printf("Selecao invalida! Insira uma nova opcao: ");
      scanf("%i", &selecaoMenu);
    }

    switch (selecaoMenu) {
    case 1:
      ret = pegarInfo(infoPessoa, tam);
      if (ret == 1) {
        tam++;
        printf("tam: %i\n", tam);
      } else {
        printf("Erro\n");
      }
      break;
    case 2:
      relatorio(infoPessoa, tam);
    default:
      break;
    }

  } while (sairMenu == true);
}
