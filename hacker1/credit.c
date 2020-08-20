#include <stdio.h>

int primeiraSoma(long long cartao, int i);
int segundaSoma(long long cartao, int i);
int primeiroDigitoCartao(long long cartao);

int
main(void)
{
    long long cartao = 0;
    int soma = 0, primeiroDigito = 0;

    printf("Numero: ");
    scanf("%lld", &cartao);

    int i = 0;
    for(long long numCartao = cartao; numCartao > 0; i++)
    {
        numCartao /= 10;
    }
    if(i % 2 == 0)
        i = 2;
    else
        i = 1;
    
    
    soma = primeiraSoma(cartao, i);
    soma += segundaSoma(cartao, i);
    printf("%d\n", soma);

    primeiroDigito = primeiroDigitoCartao(cartao);

    if(soma % 10 == 0 && cartao > 1000000000000)
    {
        if(primeiroDigito == 3)
        {
            printf("American Express\n");
        }
        else if(primeiroDigito == 4)
        {
            printf("Visa\n");
        }
        else if(primeiroDigito == 5)
        {
            printf("MasterCard\n");
        }
        else
        {
            printf("Cartao valido!\n");
        }
        
    }
    else
    {
        printf("Invalid\n");
    }
}


int primeiraSoma(long long cartao, int i)
{
    if(i == 1)
    {
        cartao /= 10;
    }
        
    int soma = 0, digito = 0;
    for(int x = 0; cartao > 0; x++)
    {
        digito = cartao % 10;
        cartao = cartao / 10;

        if(x % 2 == 0){
            digito *= 2; 
            if(digito >= 10){
                soma += digito % 10;
                soma += digito / 10;
            }
            else     
                soma += digito;
        }
    }
    return soma;
}

int segundaSoma(long long cartao, int i)
{
    if(i == 2)
    {
        cartao /= 10;
    }

    int soma = 0, digito = 0;
    for(int x = 0; cartao > 0; x++)
    {
        digito = cartao % 10;
        cartao = cartao / 10;

        if(x % 2 == 0)
        {
            soma += digito;
        }
    }
    return soma;
}

int primeiroDigitoCartao(long long cartao)
{
    while (cartao > 0)
    {
        cartao /= 10;

        if(cartao < 10)
        {
            return cartao;
        }
    }
    return 0;
}