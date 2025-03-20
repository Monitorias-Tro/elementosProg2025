#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função que distingue um número impar de um par
void first(int mode) {
	int num;
	
	printf("Digite um numero inteiro\n");
	scanf_s("%i", &num);

	//if usado para reaproveitamento da função na questão 5
	if (mode == 0) { //se o modo for 0, significa que está sendo usado para a questão 1
		if (num > 0) { //se o número for maior que par será feita a diferenciação
			int r = num % 2; //divide o número por 2 e guarda o resto
			if (r == 0) { //se o resto for 0 é par
				printf("Esse nemero e PAR\n");
			}
			else { //se o resto não for 0 é impar
				printf("Esse numero e IMPAR\n");
			}
		}
		else { //caso o numero seja menor que 0 será dito que ele é negativo
			printf("Esse numero nao e positivo\n");
		}
	}
	else { //senão, está sendo usado para a questão 5
		if (num > 0) { //mesma lógica acima...
			int r = num % 2;
			if (r == 0) {
				printf("Esse nemero e PAR\n");
			}
			else {
				printf("Esse numero e IMPAR\n");
			}
		}
		else if (num == 0) { //caso o número seja exatamente zero será exibido a mensagem extra
			printf("0\n");
		}
		else {
			printf("Esse numero nao e positivo\n");
		}
	}
}

//funcao que calcula a media de um aluno
void second(int mode) {
	int selec = 0, con;

	do { //loopa o usuario até que o mesmo escolha uma das opcoes possiveis
		printf("Selecione o modo de selecao...\n");
		printf("1. If\n2. Switch\n");
		scanf_s("%i", &selec);
	} while (selec != 1 && selec != 2);

	printf("Digite o conceito de um aluno: \n");
	scanf_s("%i", &con);

	//novamente, if usado para reaproveitamento da função na questão 5
	if (mode == 0) { //se o modo for 0, significa que está sendo usado para a questão 2
		switch (selec) { //muda entre o codigo com if else e switch case
		case 1: //efetua a avaliacao conforme o solicitado utilizando if else
			if (con <= 3) {
				printf("Conceito E \n");
			}
			else if (con > 3 && con <= 5) {
				printf("Conceito D \n");
			}
			else if (con > 5 && con <= 7) {
				printf("Conceito C \n");
			}
			else if (con > 7 && con <= 9) {
				printf("Conceito B \n");
			}
			else if (con == 10) {
				printf("Conceito A \n");
			}
			break;
		case 2: //efetua a avaliacao conforme o solicitado switch case
			switch (con) {
			case 1:
				printf("Conceito E \n");
				break;
			case 2:
				printf("Conceito E \n");
				break;
			case 3:
				printf("Conceito D \n");
				break;
			case 4:
				printf("Conceito D \n");
				break;
			case 5:
				printf("Conceito D \n");
				break;
			case 6:
				printf("Conceito C \n");
				break;
			case 7:
				printf("Conceito C \n");
				break;
			case 8:
				printf("Conceito B \n");
				break;
			case 9:
				printf("Conceito B \n");
				break;
			case 10:
				printf("Conceito A \n");
				break;
			}
			break;
		}
	}
	else { //senão, está sendo usado para a questão 5
		if (con <= 0 || con > 10) { //caso a nota esteja fora dos parametros printa 0
			printf("0");
		}
		else { //segue a mesma logica explicada acima
			switch (selec) {
			case 1:
				if (con <= 3) {
					printf("Conceito E \n");
				}
				else if (con > 3 && con <= 5) {
					printf("Conceito D \n");
				}
				else if (con > 5 && con <= 7) {
					printf("Conceito C \n");
				}
				else if (con > 7 && con <= 9) {
					printf("Conceito B \n");
				}
				else if (con == 10) {
					printf("Conceito A \n");
				}
				break;
			case 2:
				switch (con) {
				case 1:
					printf("Conceito E \n");
					break;
				case 2:
					printf("Conceito E \n");
					break;
				case 3:
					printf("Conceito D \n");
					break;
				case 4:
					printf("Conceito D \n");
					break;
				case 5:
					printf("Conceito D \n");
					break;
				case 6:
					printf("Conceito C \n");
					break;
				case 7:
					printf("Conceito C \n");
					break;
				case 8:
					printf("Conceito B \n");
					break;
				case 9:
					printf("Conceito B \n");
					break;
				case 10:
					printf("Conceito A \n");
					break;
				}
				break;
			}
		}
	}
}

/* funcao para as questoes 3 e 4
por ter muitas semelhanças entre os códigos para a questao 3 e 4,
optei por colocar ambas na mesma funcao, utilizando do 'mode' */
void thirdAndForth(int mode) {
	int val[3], a, b;

	//recebe os 3 valores
	printf("Digite tres valores quaisquer: \n");
	for (int i = 0; i < 3; i++) {
		printf("%i valor: ", i + 1);
		scanf_s("%i", &val[i]);
		printf("\n");
	}

	//ordena-os em ordem crescente
	for (int i = 0; i < 2; i++) {
		if (val[i] > val[i + 1]) {
			int aux = val[i];
			val[i] = val[i + 1];
			val[i + 1] = aux;
			i = -1;
		}
	}

	switch (mode) { //muda entre a questao 3 e 4
	case 1: //questao 3
		printf("%i ", val[2]); //printa o maior valor
		printf("\n");

		break;
	case 2: //questao 4
		for (int i = 0; i < 3; i++) { //printa os valores em ordem
			printf("%i ", val[i]);
		}
		printf("\n");
		break;
	}
}

//codigo do primeiro desafio
void challengeOne() {
	int i;
	float values[3];

	//recebe os valores
	printf("Digite um numero inteiro (I)\n");
	scanf_s("%i", &i);
	printf("Digite três numeros reais (A, B e C)\n");
	scanf_s("%f %f %f", &values[0], &values[1], &values[2]);

	switch (i) { //seleciona entre os modos de ordenação
	case 1: //ordena de forma crescente
		for (int j = 0; j < 2; j++) { 
			if (values[j] > values[j + 1]) {
				float aux = values[j];
				values[j] = values[j + 1];
				values[j + 1] = aux;
				j = -1;
			}
		}

		for (int j = 0; j < 3; j++) {
			printf("%.2f ", values[j]);
		}
		printf("\n");
		break;
	case 2: //ordena de forma decrescente
		for (int j = 0; j < 2; j++) {
			if (values[j] < values[j + 1]) {
				float aux = values[j];
				values[j] = values[j + 1];
				values[j + 1] = aux;
				j = -1;
			}
		}

		for (int j = 0; j < 3; j++) {
			printf("%.2f ", values[j]);
		}
		printf("\n");

		break;
	case 3: //ordena de forma crescente, colocando o maior valor no meio
		for (int j = 0; j < 2; j++) {
			if (values[j] < values[j + 1]) {
				float aux = values[j];
				values[j] = values[j + 1];
				values[j + 1] = aux;
				j = -1;
			}
		}

		float aux = values[2];
		values[2] = values[1];
		values[1] = aux;

		for (int j = 0; j < 3; j++) {
			printf("%.2f ", values[j]);
		}
		printf("\n");

		break;
	default:
		printf("Parametro invalido\n");
		break;
	}
}

//codigo do segundo desafio
void challengeTwo() {
	int t;
	float values[3], m, s;

	//recebe os valores
	printf("Digite tres notas\n");
	scanf_s("%f %f %f", &values[0], &values[1], &values[2]);

	printf("Selecione o tipo de media que deseja calcular\n");
	printf("1) Aritmetica\n");
	printf("2) Ponderada\n");
	printf("3) Harmonica\n");
	printf("4) Geometrica\n");
	scanf_s("%i", &t);

	switch (t) { //seleciona entre o tipo de media a ser calculada
	case 1: //calcula a media aritmetica
		m = (values[0] + values[1] + values[2]) / 3; //calcula a media
		printf("Media aritmetica: \n");
		for (int i = 0; i < 3; i++) { //printa os valores
			printf("%.2f ", values[i]);
		}
		printf("%.2f ", m); //printa a media
		break;
	case 2: //calcula a media ponderada
		for (int j = 0; j < 2; j++) { //ordena os valores, para utilizar os pesos devidamente
			if (values[j] > values[j + 1]) {
				float aux = values[j];
				values[j] = values[j + 1];
				values[j + 1] = aux;
				j = -1;
			}
		}
		m = ((values[0] * 3) + (values[1] * 3) + (values[2] * 4)) / 10; //calcula a media
		printf("Media ponderada: \n");
		for (int i = 0; i < 3; i++) { //exibe os valores
			printf("%.2f ", values[i]);
		}
		printf("%.2f ", m); //exibe a media
		break;
	case 3: //calcula a media harmonica
		m = 3 / ((1 / values[0]) + (1 / values[1]) + (1 / values[2])); //calcula a media
		printf("Media harmonica: \n");
		for (int i = 0; i < 3; i++) { //exibe os valores
			printf("%.2f ", values[i]);
		}
		printf("%.2f ", m); //exibe a media
		break;
	case 4: //calcula a media geometrica
		s = (values[0] + values[1] + values[2]); //calcula a soma dos valores
		m = cbrtf(s); //utiliza a funcao que calcula a raiz cubica de um valor para obter a media
		printf("Media geometrica: \n");
		for (int i = 0; i < 3; i++) { //exibe os valores
			printf("%.2f ", values[i]);
		}
		printf("%.2f ", m); //exibe a media
		break;
	default:
		printf("Parametro invalido\n");
		break;
	}
}

int main() {
	printf("1.\n");
	first(0);
	printf("\n");

	printf("2.\n");
	second(0);
	printf("\n");

	printf("3.\n");
	thirdAndForth(1);
	printf("\n");

	printf("4.\n");
	thirdAndForth(2);
	printf("\n");

	printf("5.\n");
	first(1);
	printf("\n");
	second(1);
	printf("\n");

	printf("Desafio 1.\n");
	challengeOne();
	printf("\n");

	printf("Desafio 2.\n");
	challengeTwo();
}