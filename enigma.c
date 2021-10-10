#include <stdio.h>
#include <string.h>

#define MAXIMO 10500


int main(void)
{
    char cribs[MAXIMO];
    char cifrada[MAXIMO];

    
    unsigned short iniciacao = 0;   /*Iniciador utilizado para mudar o inicio de comparação*/
    unsigned short posicao = 0;     /*posições que podem estar as letras*/
    unsigned short limitador = 0;   /*limita o tempo de execucao do teste*/

    

    scanf("%s %s", cifrada, cribs);

    unsigned short limite = strlen(cifrada) - strlen(cribs);


    unsigned short i = 0;
    unsigned short j = 0;

    /*Inicio das comparações*/
    while(limitador <= limite)
    {
        /*verifico se cada letra de cribs é igual a letra da cifrada nas posicoes respecitbvas*/
        if (cribs[i] == cifrada[j])
        {
            iniciacao++;    /*Toda vez que verifico a igualdade, a posicao nao me serve mais e pulo de linha*/
            j = iniciacao;  /*retorno esse valor para J*/
            i = 0;          /*reseto a posicao de i para sair comparando na minha proxima posicao com os caractere de cifrada*/
            limitador++;    /*Somo meu limiador, porque eu pulei de linha*/

        }

        /*Caso nao forem iguais*/
        else
        {
            
            /*pule de caractere e verifica se eu estou no final do caractere*/
            i++;
            /*Caso eu esteja no final do caractere, volto para o inicio do while*/
            if (cribs[i] == '\0')
            {
                /* faço os mesmos processos do primeiro if*/
                iniciacao++;
                j = iniciacao;
                i = 0;
                /*mudo essa posicao, porque se eu cheguei no fim do caracter é porque todas deram não iguais e essa posicao é válida*/
                posicao++;
                /*como pulei de linha, mudo meu limitador*/
                limitador++;
                /*Continue para reiniciar o while*/
                continue;
            }

            /*Toda vez que nao forem iguais, pular o caractere de cifrada*/
            j++;
            
        }

    }
    printf("%hu\n", posicao);


        
}