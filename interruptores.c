#include <stdio.h>

#define MAX 100

int Verificacao(int *lampsAce, int interruptores[MAX][MAX],int l);
int Calculo(int *lampsAce, int interruptores[MAX][MAX],int l, int inte);
int main(void)
{
    int quantInte, quantLampOn;
    scanf("%d%d", &quantInte, &quantLampOn);
    int resultado;
    /* matriz dupla, cada interruptor possui sua quantidade de lampadas */
    int inte[quantInte][MAX];
    /* array de lampadas acesas */
    int lampOn[quantLampOn];
    for (int i = 0; i < quantLampOn; i++)
    {
        scanf("%d", &lampOn[i]);
    }
    char limite;
    
    /* Utilizado para armazenas as lampadas de cada interruptor */
    for (int i = 0; i < quantInte; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d%c", &inte[i][j], &limite);
            //printf("i:%d , j:%d  , valor:%d\n", i, j,inte[i][j]);
            if (limite == '\n')
            {
                break;
            }     
        }         
    }
    /* Verifica se é possivel desligar todas as luzes de uma vez */
    if(Verificacao(lampOn, inte, quantLampOn))
    {
        printf("-1\n");
        return 0;
    }
    resultado = Calculo(lampOn, inte, quantLampOn, quantInte);
    printf("%d\n", resultado);
}

/***
 * Verificação(): Verifica se existe em uma linha todos os valores das lampadas
 *                acesas.
 * 
 * Parâmetros: 
 *             lampsAce(entrada): ponteiro que recebe o endereço de todas as lampadas acesas.
 *             Interruptores(entrada) : recebe os valores ligados a cada interruptor.
 *             l(entrada) : receber a quantidade de lampadas acesas.
 * 
 * Retorno: 
 *          0 : caso encontre todas as lampadas em uma linha
 *          1: caso não encontre nenhuma linha com todos os valores das lampadas acesas.
 ***/          
int Verificacao(int *lampsAce, int interruptores[MAX][MAX],int l)
{
    int contador = 0;
    int n = 0;
    
    /*Inicio da linha */
    for(int i = 0; i < MAX; i++)
    {
        
        /*se eu chegar no final da linha, eu reseto todos os valores e pulo de linha */
        if(interruptores[n][i] == '\0')
        {
            i  = -1;
            n++;
            contador = 0;
            continue;
        }
        /*Verifico se algum valor da lampada está na linha de interruptores*/
        for (int j = 0; j < l; j++)
        {
            /*Se está, eu somo meu contador mais um*/
            if(lampsAce[j] == interruptores[n][i])
            {
                
                contador++;
            }
    
        }
        /*Caso meu contador for igual ao numero de lampadas,é porque todas estão em uma linha
        então é possivel ligar todas ao mesmo tempo, logo retorne zero e feche a função*/
        if (contador == l)
        {
            return 0;
        }
        

    }
    /*Caso eu não encontrar nenhuma linha com todas as lampadas, não é possivel desligar todas as lampadas
    então retorne 1 e fecha função*/
    return 1;

}

int Calculo(int *lampsAce, int interruptores[MAX][MAX],int l, int inte)
{
    int estado[l];
   
    /*Deixa o estado das lampadas acesas = 1 */
    for (int i = 0; i < l; i++)
    {
        estado[i] = 1;
    }
    int contador = 0;
    int n = 0;
    int sum = 0;

    /*Inicio da linha */
    for(int i = 0; i < MAX; i++)
    {
        
        /*se eu chegar no final da linha, eu reseto todos os valores e pulo de linha */
        if(interruptores[n][i] == '\0')
        {
            i  = -1;
            n++;
            continue;
        }
        
        /*Verifico se algum valor da lampada está na linha de interruptores*/
        for (int j = 0; j < l; j++)
        {
            
            /*Se está, eu somo meu contador mais um*/
            if(lampsAce[j] == interruptores[n][i])
            {
                if (estado[j] == 1)
                {
                    estado[j] = 0;
                }
                else if (estado[j] == 0)
                {
                    estado[j] = 1;
                }

                
            }
    
        }
        if(n == inte - 1)
        {
            contador++;
            for (int i = 0; i < l; i++)
            {
                sum = estado[i] + sum;
            }
            
            if (sum == l)
            {
                return contador;
            }

        }
    
    }

}