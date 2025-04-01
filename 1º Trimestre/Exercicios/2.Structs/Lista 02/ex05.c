#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double r; // parte real
  double i; // parte imaginaria
} complex_t;

void cpx_mul(complex_t *op1) {
  printf("Insira a parte real do primeiro numero: ");
  scanf("%lf", &op1[0].r);
  printf("Insira a parte imaginaria do primeiro numero: ");
  scanf("%lf", &op1[0].i);

  printf("Insira a parte real do segundo numero: ");
  scanf("%lf", &op1[1].r);
  printf("Insira a parte imaginaria do segundo numero: ");
  scanf("%lf", &op1[1].i);

  op1[2].r = (op1[0].r * op1[1].r) - (op1[0].i * op1[1].i);
  op1[2].i = (op1[0].r * op1[1].i) + (op1[0].i * op1[1].r);

  printf("parte real: %lf\n", op1[2].r);
  printf("parte imaginaria: %lf\n", op1[2].i);
}

int main() {

  complex_t complex_t[3];

  cpx_mul(&complex_t);
}
