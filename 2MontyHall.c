#include <stdio.h>

int main(void)
{
    int casos, porta;
    int pontos = 0;

    scanf("%d", &casos);

    while(casos--)
    {
        scanf("%d", &porta);

        /*Basicamente todos os meus pontos sao aqueles diferente de 1, então sempre atribuia 1 a pontos*/
        if (porta != 1)
        {
            pontos++;
        }
    }

    printf("%d\n", pontos);



}

