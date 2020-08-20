#include<stdio.h>

int proporcao(int valor, int soma);
void imprimeGrafico(int barra1, int barra2, int barra3, int barra4);

int
main(void)
{
    int barra1 = 0, barra2 = 0, barra3 = 0, barra4 = 0;

    printf("M procurando F: ");
    scanf("%d", &barra1);

    printf("F procurando M: ");
    scanf("%d", &barra2);

    printf("F procurando F: ");
    scanf("%d", &barra3);

    printf("M procurando M: ");
    scanf("%d", &barra4);

    int soma = 0;

    soma = barra1 + barra2 + barra3 + barra4;

    barra1 = proporcao(barra1, soma);
    barra2 = proporcao(barra2, soma);
    barra3 = proporcao(barra3, soma);
    barra4 = proporcao(barra4, soma);

    for(int i = 0; i < 20; i++)
    {
        if(i >= 20 - barra1)
        {
            printf("###  ");
        }
        else
        {
            printf("     ");
        }
        if(i >= 20 - barra2)
        {
            printf("###  ");
        }
        else
        {
            printf("     ");
        }
        if(i >= 20 - barra3)
        {
            printf("###  ");
        }
        else
        {
            printf("     ");
        }
        if(i >= 20 - barra4)
        {
            printf("###  ");
        }
        else
        {
            printf("     ");
        }
        printf("\n");
    }
    printf("M-F  F-M  F-F  M-M\n");
}

int proporcao(int valor, int soma)
{
    return (20.0 * (float)valor/soma) + 0.5;
}