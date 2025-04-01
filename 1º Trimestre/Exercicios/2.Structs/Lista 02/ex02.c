#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

typedef struct {
  double r; // parte real
  double i; // parte imaginaria
} complex_t;

void cpx_polar_out(complex_t *cpx, double *mod, double *ang) {

  double aux = (cpx->i / cpx->r);

  *mod = sqrt(pow(cpx->r, 2) + pow(cpx->i, 2));
  *ang = atan(aux);

  double angInDegree = (*ang) * (180 / M_PI);

  printf("Modulo: %.2lf\n", *mod);
  printf("Angulo: %.2lf\n", angInDegree);
}

int main() {
  double mod, ang;
  complex_t complex_t;

  printf("Entre com o valor real: ");
  scanf("%lf", &complex_t.r);
  printf("Entre com o valor imaginario: ");
  scanf("%lf", &complex_t.i);

  cpx_polar_out(&complex_t, &mod, &ang);
}
