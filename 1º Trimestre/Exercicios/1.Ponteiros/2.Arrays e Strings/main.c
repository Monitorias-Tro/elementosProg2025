#include <stdio.h>
#include <stdlib.h>

void inverte(char* str) {
	int s = 1, i, j;
	char strcpy[50];
	
	for (int i = 0; s == 1; i++) {
		if (*(str + i) == '\0') {
			j = i - 1;
			s = 0;
		}
	}
	for (i = 0; j >= 0; i++) {
		strcpy[i] = *(str + j);
		j--;
	}
	strcpy[i] = '\0';

	for (int k = 0; strcpy[k] != '\0'; k++) {
		*(str + k) = strcpy[k];
	}
}

int vetorPares(int *vetor, int t, int *p) {
	int s = 0, pp = 0;
	
	for (int i = 0; i < t; i++) {
		if ((*(vetor + i) % 2) == 0) {
			*(p + pp) = *(vetor + i);
			s++;
			pp++;
		}
	}
	return s;
}

void parImpar(int* vetor, int t, int* par, int* npar, int* impar, int* nimpar) {
	for (int i = 0; i < t; i++) {
		if ((*(vetor + i) % 2) == 0) {
			*(par + (*npar)) = *(vetor + i);
			*npar += 1;
		} else {
			*(impar + (*nimpar)) = *(vetor + i);
			*nimpar += 1;
		}
	}
}

void ordenaC(int *vetor, int t) {
	for (int i = 0; i < t - 1; i++) {
		if (*(vetor + i) > *(vetor + i + 1)) {
			int aux = *(vetor + i);
			*(vetor + i) = *(vetor + i + 1);
			*(vetor + i + 1) = aux;
			i = -1;
		}
	}
}

void ordena(int *vetor, int t, char ordem) {
	switch (ordem) {
	case 'C':
	case 'c':
		for (int i = 0; i < t - 1; i++) {
			if (*(vetor + i) > *(vetor + i + 1)) {
				int aux = *(vetor + i);
				*(vetor + i) = *(vetor + i + 1);
				*(vetor + i + 1) = aux;
				i = -1;
			}
		}

		for (int i = 0; i < t; i++) {
			printf("%i ", *(vetor + i));
		}
		printf("\n");

		break;
	case 'D':
	case 'd':
		for (int i = 0; i < t - 1; i++) {
			if (*(vetor + i) < *(vetor + i + 1)) {
				int aux = *(vetor + i);
				*(vetor + i) = *(vetor + i + 1);
				*(vetor + i + 1) = aux;
				i = -1;
			}
		}

		for (int i = 0; i < t; i++) {
			printf("%i ", *(vetor + i));
		}
		printf("\n");
		break;
	default:
		break;
	}
}

int main() {
	int num[50], pair[50], t, s, pair2[50], odd[50], np = 0, no = 0, m;
	char str[50], o;
	
	printf("1. Digite uma frase\n");
	gets_s(str, 50);
	inverte(str);
	printf("%s \n", str);

	printf("2. Digite o numero de valores que deseja inserir (max 50)\n");
	scanf_s("%i", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%i", &num[i]);
	}
	s = vetorPares(num, t, pair);
	printf("O numeros de valores pares e: %i\n", s);
	printf("Eles são: ");
	for (int i = 0; i < s; i++) {
		printf("%i ", pair[i]);
	}
	printf("\n");

	printf("3. Digite o numero de valores que deseja inserir (max 50)\n");
	scanf_s("%i", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%i", &num[i]);
	}
	parImpar(num, t, pair2, &np, odd, &no);
	printf("O numeros de valores pares e: %i\n", np);
	printf("Eles são: ");
	for (int i = 0; i < np; i++) {
		printf("%i ", pair2[i]);
	}
	printf("\n");
	printf("O numeros de valores impares e: %i\n", no);
	printf("Eles são: ");
	for (int i = 0; i < no; i++) {
		printf("%i ", odd[i]);
	}
	printf("\n");

	printf("4. Digite o numero de valores que deseja inserir (max 50)\n");
	scanf_s("%i", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%i", &num[i]);
	}
	ordenaC(num, t);
	printf("\n");
	for (int i = 0; i < t; i++) {
		printf("%i ", num[i]);
	}
	printf("\n");

	printf("5. Digite o numero de valores que deseja inserir (max 50)\n");
	scanf_s("%i", &t);
	for (int i = 0; i < t; i++) {
		scanf_s("%i", &num[i]);
	}
	printf("\nDigite ''c'' para ordenar de forma crescente e ''d'' para decrescente\n");
	scanf_s(" %c", &o);
	ordena(num, t, o);
}