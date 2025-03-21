/**********************************************************
* @file     main.c
* @brief    Trabalho trimestral - Resta Um
* @author   Davi Scunch, Edrick de Oliveira, Marcos Zuccolotto
* @date     jun/2024
* @version  1.2

* Fundacao Liberato - Curso de Eletronica
* Elementos de programacao  - prof. Marcos Zuccolotto
*
* Trabalho trimestral - Struct / enum / ponteiros
*
* Implemente as funcoes abaixo comforme especificacao,
* respeitando os parametros e tipos de dados definidos,
* seguindo as orientacoes dadas
* - qualJogada()
* - movimenta()
* - confereJogo()
*
* Equipe : Bancada (2 alunos)
**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "restaUm.h"

#define MAXMSG 100           // tamanho maximo de mensagens
unsigned int numJogadas = 0; // numero de jogadas realizadas

int main() {
    // Variaveis
    char tabRestaUm[NLIN][NCOL]; // tabuleiro
    status_t estado = OK;        // resultado da funcao
    movimento_t jogada;          // movimento a realizar
    char msg[MAXMSG];            // mensagem para usuario

    //deixa todas as coordenadas nulas
    jogada.origem.lin = -1;
    jogada.origem.col = -1;
    jogada.destino.lin = -1;
    jogada.destino.col = -1;
    
    // Inicializacao
    setlocale(LC_ALL, "");                 // caracteres da lingua portuguesa
    inicTab(*tabRestaUm);                  // preenche tabuleiro inicial
    system("clear");                       // limpa o terminal
    reloadTab(*tabRestaUm, 3, 3, &jogada); // exibe o tabulero

    // Laco principal
    do {
        //deixa todas as coordenadas nulas
        jogada.origem.lin = -1;
        jogada.origem.col = -1;
        jogada.destino.lin = -1;
        jogada.destino.col = -1;

        estado = qualJogada(*tabRestaUm, &jogada);
        if (estado != DERROTA) { // se nao pedir para sair, segue o jogo
            estado = movimenta(*tabRestaUm, &jogada);
            switch (estado) {
            case INVALIDO:
                system("clear"); //limpa o terminal
                reloadTab(*tabRestaUm, 3, 3, &jogada); // exibe o tabulero
                strncpy(msg, "Movimento invalido\nn", MAXMSG);
                break;
            case VAZIO:
                system("clear"); //limpa o terminal
                reloadTab(*tabRestaUm, 3, 3, &jogada); // exibe o tabulero
                strncpy(msg, "Sem pecas a mover\n", MAXMSG);
                break;
            case OCUPADO:
                system("clear"); //limpa o terminal
                reloadTab(*tabRestaUm, 3, 3, &jogada); // exibe o tabulero
                strncpy(msg, "Posicao destino ocupada\n", MAXMSG);
                break;
            default:
                system("clear"); //limpa o terminal
                reloadTab(*tabRestaUm, 3, 3, &jogada); // exibe o tabulero
                numJogadas++;
                estado = confereJogo(*tabRestaUm);
                switch (estado) {
                case VITORIA:
                    strncpy(msg, "Parabans, sobrou so um!\n", MAXMSG);
                    break;
                case DERROTA:
                    strncpy(msg, "Acabaram as jogadas!\n", MAXMSG);
                    break;
                default:
                    strncpy(msg, "Jogo continua...\n", MAXMSG);
                }
            }
            printf(msg);
        } // fim if derrota

    } while (estado != VITORIA && estado != DERROTA);
    printf("Fim de jogo com %d rodadas!\n", numJogadas);
} // fim main

void inicTab(char* tab) {
    for (int i = 0; i < NLIN; i++) {
        for (int j = 0; j < NCOL; j++) {
            *(tab + i * NLIN + j) = OC;

            if (i == 0 || i == 1 || i == 5 || i == 6) {
                if (j == 0 || j == 1 || j == 5 || j == 6) {
                    *(tab + i * NLIN + j) = NU;
                }
            }
        }
    }
    *(tab + 3 * NLIN + 3) = VZ;
}

void reloadTab(char* tab, int l, int c, movimento_t* jog){
    //posicoes/coordenadas de origem e destino
    int oLin = jog->origem.lin;
    int oCol = jog->origem.col;
    int dLin = jog->destino.lin;
    int dCol = jog->destino.col;
    
    printf("  A B C D E F G");
    printf("\n");
    for (int i = 0; i < NLIN; i++) {
        printf("%i ", i);
        for (int j = 0; j < NCOL; j++) {
            if (i == l && j == c) { //se estiver na posicao que o jogador esta
                printf("%c ", AC);  //printa como ponto atual de escolha
            } else {
                printf("%c ", *(tab + i * NLIN + j));
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("-> W(cima) A(esquerda) S(baixo) D(direita)\n");
    printf("-> Selecionar (Espaco)\n");
    printf("-> Desistir   (Esc)\n\n");
    
    printf("Rodada %i\n\n", numJogadas + 1);
    
    //se as coordenadas de origem foram selecionadas
    if (oLin != -1 && oCol != -1) {
        printf("Origem: %i, %i\n", oLin, oCol);
    } else {
        printf("Origem: ?, ?\n");
    }

    //se as coordenadas de destino foram selecionadas
    if (dLin != -1 && dCol != -1) {
        printf("Destino: %i, %i\n", dLin, dCol);
    } else {
        printf("Destino: ?, ?\n");
    }
    printf("\n");

}

status_t qualJogada(char *tab, movimento_t* jog) {
    char cha; //tecla digitada
    
    //linha atual; coluna atual; indice ascii da tecla digitada (necessario por causa do espaco e esc); status (-1 = fim, 0 & 1 = pecas sendo selecionadas, 2 = todas as pecas foram selecionadas)
    int l = 3, c = 3, ch, stat = 0; 

    //enquanto as pecas nao estiverem efetivamente movidas...
    do {
        cha = getchar();
        ch = cha;
        
        //apos digitado o comando, efetua a devida acao
        switch (ch) {
        case 'w':
        case 'W':
            if (l <= 0) break; //se estiver na primeira linha, cancela o movimento
            l--; //sobe uma linha (comeca em 0 e termina em 6)
            system("clear"); //limpa o terminal
            reloadTab(tab, l, c, jog); //re-printa o tabuleiro
            break;
        case 'a':
        case 'A':
            if (c <= 0) break; //se estiver na primeira coluna, cancela o movimento 
            c--; //move uma linha para a esquerda (comeca em 0 e termina em 6)
            system("clear"); //limpa o terminal
            reloadTab(tab, l, c, jog); //re-printa o tabuleiro
            break;
        case 's':
        case 'S':
            if (l >= 6) break; //se estiver na ultima linha, cancela o movimento
            l++; //desce uma linha (comeca em 0 e termina em 6)
            system("clear"); //limpa o terminal
            reloadTab(tab, l, c, jog); //re-printa o tabuleiro
            break;
        case 'd':
        case 'D':
            if (c >= 6) break; //se estiver na ultima coluna, cancela o movimento
            c++; //move uma coluna para a direita (comeca em 0 e termina em 6)
            system("clear"); //limpa o terminal
            reloadTab(tab, l, c, jog); //re-printa o tabuleiro
            break;
        case 27: //esc
            stat = -1; //cancela o jogo
            break;
        case 32: //espaco
            stat++; //adiciona uma peca selecionada a variavel de status (ao ter o valor de 2, sai do loop e efetua o movimento)
            if ((stat % 2) != 0) { //se somente o primeiro movimento foi realizado
                jog->origem.lin = l;
                jog->origem.col = c;
                system("clear"); //limpa o terminal
                reloadTab(tab, l, c, jog);
            } else { //se ambos foram realizados
                jog->destino.lin = l;
                jog->destino.col = c;
                reloadTab(tab, l, c, jog);
            }
            break;
        default:
            break;
        } 
    } while (stat != 2 && stat != -1);

    if (stat == 2) { //se os movimentos foram realizados
        return OK;
    } else { //se o jogo foi cancelado
        return DERROTA;
    }
}

status_t movimenta(char* tab, movimento_t* jog) {
    //definicao das variaveis
    int oLin, oCol, dLin, dCol, dfLin, dfCol;
    char d, o;

    //posicoes/coordenadas de origem e destino
    oLin = jog->origem.lin;
    oCol = jog->origem.col;
    dLin = jog->destino.lin;
    dCol = jog->destino.col;
    dfLin = dLin - oLin;
    dfCol = dCol - oCol;
    o = *(tab + oLin * NCOL + oCol);
    d = *(tab + dLin * NCOL + dCol);

    //invalido se o destino nao estiver a duas pecas da origem
    if (oLin == dLin && (dfCol != -2 && dfCol != 2)) return INVALIDO;
    if (oCol == dCol && (dfLin != -2 && dfLin != 2)) return INVALIDO;
    
    if (o == VZ) return VAZIO; //se a origem for vazia

    if (d == OC) return OCUPADO; //se o destino for ocupado

    if (*(tab + (oLin + (dfLin/2)) * NCOL + (oCol + (dfCol/2))) != OC) return INVALIDO; //se a peca intermediaria nao estiver ocupada

    if (d != VZ && o != OC) return INVALIDO; //se o destino ou origem estiverem fora dos parametros
    
    *(tab + oLin * NCOL + oCol) = VZ;                             // origem fica vazia
    *(tab + (oLin + (dfLin/2)) * NCOL + (oCol + (dfCol/2))) = VZ; // peca intemediaria fica vazia
    *(tab + dLin * NCOL + dCol) = OC;                             // destino fica ocupado
    return OK;
}

status_t confereJogo(char *tab) {
    char *elem;
    int qtd_pecas = 0;

    //itera atraves dos elementos no tabuleiro
    for(int i = 0; i < NLIN; i++) {
        for(int j = 0; j < NCOL; j++) {
            //para melhor legibilidade, assinala o elemento atual a um ponteiro
            elem = (tab + NCOL * i + j);

            //se o elemento for uma peca:
            if (*elem == OC) {
                //somar 1 a quantidade
                qtd_pecas++;
                //OK se houver uma peça adjacente seguida por um espaço vazio, sem que um destes ultrapasse a borda do tabuleiro
                if ((*(elem + 1) == OC && *(elem + 2) == VZ && j < 5) ||
                    (*(elem - 1) == OC && *(elem - 2) == VZ && j > 1) ||
                    (*(elem - NCOL) == OC && *(elem - NCOL * 2) == VZ && i > 1) ||
                    (*(elem + NCOL) == OC && *(elem + NCOL * 2) == VZ && i < 5)
                )   return OK;
            }
        }
    }

    //se nao e possivel executar mais jogadas:
    //VITORIA se ainda resta apenas 1 peca
    if(qtd_pecas == 1) return VITORIA;

    //DERROTA caso contrario
    return DERROTA;
}