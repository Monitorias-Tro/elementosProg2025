#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct aluno {
  int matricula;
  char nome[MAX];
  float trimestrais[3];
  float resultado_anual;
  char conceito;
} t_aluno;

/*
 * t_aluno *a - 'struct t_aluno' onde mudaremos o valor do 'resultado_anual'
 * int pesos[3] - lista de pesos para realizar a media ponderada
 * Retornos:
 *    -1 - Parametros invalidos
 *     0 - Retorno valido
 */
int set_resultado_anual(t_aluno *a, int pesos[3]) {
  // Lista das avaliacoes trimestrais nao foi preenchido corretamente
  if (a->trimestrais[0] < 0 || a->trimestrais[1] < 0 || a->trimestrais[2] < 0) {
    return -1;
  }
  // Lista das pesos nao foi preenchido corretamente
  if (pesos[0] <= 0 || pesos[1] <= 0 || pesos[2] <= 0) {
    return -1;
  }
  a->resultado_anual =
      ((a->trimestrais[0] * pesos[0] + a->trimestrais[1] * pesos[1] +
        a->trimestrais[2] * pesos[2]) /
       (pesos[0] + pesos[1] + pesos[2]));
  return 0;
}

/*
 * t_aluno *a - 'struct t_aluno' onde mudaremos o valor do 'conceito'
 */
void set_conceito(t_aluno *a) {
  if (a->resultado_anual >= 9) {
    a->conceito = 'A';
  } else if (a->resultado_anual >= 7.5) {
    a->conceito = 'B';
  } else if (a->resultado_anual >= 6) {
    a->conceito = 'C';
  } else {
    a->conceito = 'R';
  }
}

int main() {
  t_aluno a;
  int pesos[] = {25, 35, 40};
  printf("\nNome do Aluno: ");
  fgets(a.nome, MAX, stdin);
  printf("\nMatricula: ");
  scanf("%i", &a.matricula);
  printf("\nColocar respectivamente os valores da 1a, 2a e 3a avaliacao "
         "trimestral:\n");
  scanf("%f %f %f", &a.trimestrais[0], &a.trimestrais[1], &a.trimestrais[2]);

  set_resultado_anual(&a, pesos);
  set_conceito(&a);

  printf("\nNome do Aluno: %s", a.nome);
  printf("Matricula: %i", a.matricula);
  printf("\nResultado Anual: %f", a.resultado_anual);
  printf("\nConceito: %c", a.conceito);
}
