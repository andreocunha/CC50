#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>


int 
main(void)
{
    srand(time(NULL));

    int numBalas = rand() % 1024;
    int numUsuario = -1;

    while (numBalas != numUsuario)
    {
        printf("Quantas balas tem na máquina? ");
        scanf("%d", &numUsuario);

        if(numBalas != numUsuario)
        {
            printf("Quase! Seu numero foi %d e a quantidade era %d\n", numUsuario, numBalas);
        }
    }    

    printf("Obrigado por jogar!\n");
  
    return 0;
}