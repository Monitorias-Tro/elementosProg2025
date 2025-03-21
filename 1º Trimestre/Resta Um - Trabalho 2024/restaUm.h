/**********************************************************
* @file     restaUm.h
* @brief    Resta Um - defines, tipos dados e prototipos
* @author   Davi Scunch, Edrick de Oliveira, Marcos Zuccolotto
* @date     jun/2024
* @version  1.2
**********************************************************/
#ifndef _RESTA_UM_H_   // Declaracao de guarda
#define _RESTA_UM_H_

// Dimensoes da matriz que guarda o tabuleiro
#define NCOL 7
#define NLIN 7

// Marcadores do tabuleiro
#define NU ' '  // Ponto invalido/proibido
#define OC 'o'  // Ponto ocupado
#define VZ '-'  // Ponto livre/vazio
#define AC '*'  // Ponto atual

/* Tipos de dados */
// Posicao da peca no tabuleiro
typedef struct {
    int lin; // Posicao linha
    int col; // Posicao destino
} posTab_t;

// Movimento a ser realizado
typedef struct {
    posTab_t origem;   // Posicao inicio/origem
    posTab_t destino; // Posicao fim
} movimento_t;

// Retornos
typedef enum {
    OK = 0,   // 0 - movimento executado, segue o jogo
    INVALIDO, // 1 - n�o existe peca a pular sobre/retira/fora tabuleiro/movimento longo, curto ou em diagonal
    OCUPADO,  // 2 - posicao destino ocupada
    VAZIO,    // 3 - posicao origem vazia
    VITORIA,  // 4 - vitoria - fim jogo
    DERROTA   // 5 - nao tem mais o que fazer
} status_t;

/* Prototipos */
/*
* @brief  Inicializa tabuleiro
* @param  tabuleiro
* @retval none
*/
void inicTab(char* tab);

/*
* @brief  Exibe o tabuleiro
* @param  tabuleiro
* @retval none
*/
void reloadTab(char* tab, int l, int c, movimento_t* jog);

/*
* @brief  Entrada dados da jogada
* @param  tabuleiro, movimentacao a realizar
* @retval OK - jogador definiu a movimentacao
*         DERROTA - jogador desistiu do jogo
*/
status_t qualJogada(char *tab, movimento_t* jog);

/*
* @brief  Executa a movimentacao solicitada
* @param  tabuleiro
* @param  movimentacao a realizar
* @retval OK - movimento executado, segue o jogo
          INVALIDO - movimento invalido
          OCUPADO - posicao destino ocupada
          VAZIO - posicao origem vazia
*/
status_t movimenta(char* tab, movimento_t* jog);

/*
* @brief  Confere possibilidades de continuacao
* @param  tabuleiro
* @retval OK - segue o jogo
          VITORIA - restou um, acabou
          DERROTA - nada mais a fazer, fim de jogo
*/
status_t confereJogo(char *tab);

#endif //_RESTA_UM_H_