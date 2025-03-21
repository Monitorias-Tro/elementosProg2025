/*
Fundação Liberato - Curso de eletronica
Elementos de programacao
prof. Marcos Zuccolotto
*/

/* Recuperação de nota - 1o trimestre */
#include <stdio.h>
#include <stdlib.h>

/* O vetor Chuva contém medicões de pluviosidade feitas por uma
  estação metereológica automática localizada no Jardim Botânico de Porto Alegre.
  Estas medições foram realizadas nos primeiros 7 dias do mes de maio/2024
  O vetor dia armazena o dia em que a respectiva medida foi feita.

  Elabore um programa que:
  Calcule a média de chuva neste período
  Indique qual dia foi o mais chuvoso no período, apresentando o valor acumulado no dia
  Indique quantos dias não registraram chuva no período.

  Para isto, utilize TODAS as funções propostas e construa
  a exibição do relatório na função main()
*/

/* Headers */
void consolida(float *chuvaDia, float *chuva, int *dias, int nDados);
float mediaChuva(float *chuvaDia, int nDias);
int maisChuvoso(float *chuvaDia, int nDias);
int semChuva(float *chuvaDia, int nDias, float limite);

/* Quantidade de chuva [mm] */  //Obs: 24 medicoes por dia
float Chuva[]={2.4,3.6,7.2,0,0,0,2.4,2.6,3,1.8,0,0,0.2,0.8,5.8,7.4,7.6,2.6,1,3.2,2,0.6,1,0.2,6.4,4.6,17.2,13.8,14.2,9.2,6.2,3.8,0.6,0.2,0,0,0,0.4,1.6,6.6,2.4,1.2,1.6,1,0.6,0.6,1.2,1,0.2,0,0,0.4,0.2,0.6,0,0.2,0,0,0,0.2,0,0,0,0,0,0,0,0.6,0.2,0.2,0,0.6,1.2,1.4,0,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2.8,0.6,0.6,7.2,1.8,1,0.2,0.8,3.2,4.8,1,0,1.2,0.0,0.4,0,0,0,0.2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
/* dia em que ocorreu a medida */
int dia[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
int nDados = sizeof(Chuva)/sizeof(Chuva[0]); //quantidade de dados
float chuva_dia[7] = {0, 0, 0, 0, 0, 0, 0};  //vetor de valores diarios

int main() {
    //variaveis utilizadas
    int maisChuva, sem_chuva;
    float media;

    //chamada das funcoes
    consolida(&chuva_dia, &Chuva, &dia, nDados);
    media = mediaChuva(&chuva_dia, 7);
    maisChuva = maisChuvoso(&chuva_dia, 7);
    sem_chuva = semChuva(&chuva_dia, 7, 0);
    
    //retorno
    printf("A media de chuva foi: %.2f.\n", media);
    printf("O dia mais chuvoso foi o %iº, tendo %.2fmm de chuva.\n", maisChuva, chuva_dia[maisChuva - 1]);
    printf("%i dias nao registraram chuvas.\n", sem_chuva);
}

/*
@brief consolida dados quantidade de chuva por dia
       totaliza quantidade de chuva medida em um dia - indice do vetor = dia-1
@param vetor recebe dados consolidados (chuvaDia)
@param vetor contendo medicao pluviosidade (chuva)
@param vetor contendo dia que foi feita a medida (dias)
@param quantidade de dados contida nos vetores chuva e dias
*/
void consolida(float *chuvaDia, float *chuva, int *dias, int nDados) {
    for (int i = 0; i < nDados; i++) { //itera por todos os dados do vetor
        int index = *(dias + i) - 1;   //guarda o valor que sera usado como indice no vetor chuva_dias (ex.: dia 1 -> indice 0)
        chuvaDia[index] += chuva[i];   //adiciona a quantidade de chuva media ao total diario
    }
}

/*
@brief Calcula chuva media no periodo
@param vetor de dados consolidados de pluviosidade (chuvaDia)
@param quantidade de dias medidos
*/
float mediaChuva(float *chuvaDia, int nDias) {
    float total = 0;                  //variavel com o total de chuva do periodo
    for (int i = 0; i < nDias; i++) { //itera por todos os valores diarios
        total += chuvaDia[i];         //adiciona o total diario ao total do periodo 
    }
    float media = total/7;            //calcula a media
    return media;                     //retorna a media
}

/*
@brief Identifica dia mais chuvoso
@param vetor de dados consolidados de pluviosidade (chuvaDia)
@param quantidade de dias medidos
*/
int maisChuvoso(float *chuvaDia, int nDias) {
    int anterior = 0;                           //indice do maior valor anterior (padrao = valor inicial)
    for (int i = 0; i < nDias; i++) {           //itera por todos os valores diarios
        if (chuvaDia[i] > chuvaDia[anterior]) { //se o valor atual for maior que o valor anterior
            anterior = i;                       //o dia que teve mais chuva é o atual
        }
    }
    return anterior + 1;                        //retorna o dia mais chuvoso (+1 para melhor legibilidade)
}

/*
@brief Calcula quantidade de dias sem chuva
@param vetor de dados consolidados de pluviosidade (chuvaDia)
@param quantidade de dias medidos
@param valor minimo para ser considerado dia chuvoso
*/
int semChuva(float *chuvaDia, int nDias, float limite) {
    int total = 0;                    //total de dias sem chuva
    for (int i = 0; i < nDias; i++) { //itera por todos os valores diarios
        if (chuvaDia[i] <= limite) {  //se a quantidade de chuva do dia for menor ou igual ao limite para se considerar sem chuva
            total++;                  //aumenta em um o total de dias sem chuva
        }
    }
    return total;                     //retorna o total de dias sem chuva
}