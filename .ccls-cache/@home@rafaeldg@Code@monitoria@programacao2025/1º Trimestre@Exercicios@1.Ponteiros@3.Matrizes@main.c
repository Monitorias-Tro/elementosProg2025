#include <stdio.h>

/*
 * Função: Multiplica a matriz mat pelo escalar k. Armazena na própria matriz
 * mat - ponteiro para matriz origem
 * k - valor escalar multiplicando de mat
 * lin,col - numero de linhas e colunas da matriz mat
 */
void m_escala(int *mat, int k, int lin, int col);

/*
 * Função: Preenche a matriz mat como matriz identidade (diagonal principal = 1
 * e demais = 0) mat - ponteiro para a area de armazenamento da matriz quadrada
 * ordem - tamanho da matriz (num linhas = num colunas)
 */
void m_identidade(int *mat, int ordem);

/*
 * Função: Gera a matriz transposta da matriz de entrada mat
 * mat_t - ponteiro para a area da matriz transposta
 * mat - ponteiro para area da matriz de entrada/origem
 * lin,col - numero de linhas e colunas da matriz origem
 */
int m_transposta(int *mat_t, int *mat, int lin, int col);

/*
 * Função: Ordena em ordem crescente os valores de cada linha da matriz dados.
 * Cada linha deve ser ordenada independente das demais. dados - ponteiro para
 * vetor a ser ordenado lin,col - numero de linhas e colunas de dados
 */
void m_ordena_linha(int *dados, int lin, int col);

void printMat(int *mat, int lin, int col);

int main() {
  // Entrada exercicio 1
  int m1[3][3] = {{1, 2, 3}, {3, 2, 1}, {2, 3, 1}};
  m_escala(m1[0], 2, 3, 3);
  printMat(m1[0], 3, 3);

  // Entrada exercicio 2
  int m2[4][4] = {};
  m_identidade(m2[0], 4);
  printMat(m2[0], 4, 4);

  // Entrada exercicio 3
  int m3[3][2] = {{1, 2}, {2, 1}, {2, 2}};
  int m3_t[2][3] = {};
  if (m_transposta(m3_t[0], m3[0], 3, 2) == 0) {
    printf("Deu xabu\n");
  }
  printMat(m3_t[0], 2, 3);

  // Entrada exercicio 4
  int m4[3][3] = {{1, 2, 3}, {3, 2, 1}, {2, 1, 3}};
  m_ordena_linha(m4[0], 3, 3);
  printMat(m4[0], 3, 3);
}

void m_escala(int *mat, int k, int lin, int col) {
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      *(mat + (i * col) + j) = *(mat + (i * col) + j) * k;
    }
  }
}

void m_identidade(int *mat, int ordem) {
  for (int i = 0; i < ordem; i++) {
    for (int j = 0; j < ordem; j++) {
      if (i == j) {
        *(mat + (i * ordem) + j) = 1;
      } else {
        *(mat + (i * ordem) + j) = 0;
      }
    }
  }
}

int m_transposta(int *mat_t, int *mat, int lin, int col) {
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      *(mat_t + j * lin + i) = *(mat + i * col + j);
    }
  }
}

void m_ordena_linha(int *dados, int lin, int col) {
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < (col - 1);
         j++) { // Implementação do algoritmo bubble sort
      if (*(dados + (i * col) + j) > *(dados + (i * col) + j + 1)) {
        int aux = *(dados + (i * col) + j + 1);
        *(dados + (i * col) + j + 1) = *(dados + (i * col) + j);
        *(dados + (i * col) + j) = aux;
        j = -1;
      }
    }
  }
}

void printMat(int *mat, int lin, int col) {
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      printf("%i ", *(mat + (i * col) + j));
    }
    printf("\n");
  }
}
