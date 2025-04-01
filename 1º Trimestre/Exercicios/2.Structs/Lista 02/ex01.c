#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

typedef struct {
  double r; // parte real
  double i; // parte imaginaria
} complex_t;

void cpx_polar_in(complex_t *cpx, double mod, double ang) {

  double angInRad = ang * (M_PI / 180);
  cpx->r = mod * cos(angInRad);
  cpx->i = mod * sin(angInRad);

  printf("Sua notacao polar foi: %.2lf |%.2lf", mod, ang);
  printf("\nSua notacao retangular seria: ");
  if (cpx->i < 0) {
    double modulo = cpx->i * (-1);
    printf("%.2lf -j%.2lf", cpx->r, modulo);
  } else {
    printf("%.2lf +j%.2lf", cpx->r, cpx->i);
  }
}

int main() {
  double mod, ang;
  complex_t complex_t;

  printf("Entre com o modulo: ");
  scanf("%lf", &mod);
  printf("Entre com o angulo: ");
  scanf("%lf", &ang);

  cpx_polar_in(&complex_t, mod, ang);
}
