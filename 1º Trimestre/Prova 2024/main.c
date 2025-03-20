/*
Elementos de Programacao - prof. Marcos Zuccolotto
Avaliacao Individual 1 - 1o tri 2024 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCH 100

/* Implemente o codigo que realiza a funcao especificada a segur :
  Evite utilizar as funções de string.h ou ctype.h */
// prototipo
int strfun(char *str, int max);

/*
NAO MODIFIQUE O main()
NAO MODIFIQUE O main()
NAO MODIFIQUE O main()
*/
int main()
{
   char palavra[MAXCH];
   int retorno;

   // entrada de dados
   printf("Palavra?:\n");
   scanf("%s",palavra);

   // executando a funcao
   retorno = strfun(palavra, MAXCH);

   // Saida de dados
   printf("Resultado:\n");
   printf("%s\n",palavra);
   printf("Retorno:\n");
   printf("%d\n",retorno);

}

/*
Implemente aqui as funcionalidades especificadas
A versao final da funcao NAO DEVE gerar saidas no console (printf ou equivalente)
*/

int strfun(char *str, int max) {
    //variável da quantidade de valores modificados
    int modified = 0;

    //loop que percorre cada item da string
    for (int i = 0; *(str + i) != '\0'; i++) {
        //primeira letra, terceira, quinta, etc.
        if ((i % 2) == 0) {
            int ch = 0;
            char result;
            ch  = *(str + i);

            //se a letra for minuscula, tranforma em maiuscula
            if (ch >= 97 && ch <= 122) {
                ch -= 32;
                result = ch;
                *(str + i) = result;
                modified += 1;
            }
        }
        //segunda letra, quarta, sexta, etc.
        else {
            int ch = 0;
            char result;
            ch  = *(str + i);

            //se a letra for maiuscula, transforma em minuscula
            if (ch >= 65 && ch <= 90) {
                ch += 32;
                result = ch;
                *(str + i) = result;
                modified += 1;
            }
        }
    }
    return modified;
}

//maiusculas ascii: 65 - 90
//minusculas ascii: 97 - 122
