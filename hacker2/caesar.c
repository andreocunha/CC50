#include<stdio.h>
#include<stdlib.h>

void criptografaMaiuscula(char letra, int chave);
void criptografaMinuscula(char letra, int chave);

int
main(int argc, char *argv[])
{
    int chave = atoi(argv[1]);
    // printf("%d\n", chave);

    printf("Digite a frase que sera criptografada: ");
    char frase[100];
    scanf("%[^\n]s", frase);
    setbuf(stdin, NULL);

    printf("\n%s\n", frase);

    for(int i = 0; frase[i] != '\0'; i++)
    {
        if(frase[i] >= 'A' && frase[i] <= 'Z')
        {
            criptografaMaiuscula(frase[i], chave);
        }
        else if(frase[i] >= 'a' && frase[i] <= 'z')
        {
            criptografaMinuscula(frase[i], chave);
        }
        else if(frase[i] == ' ')
        {
            printf(" ");
        }
        
    }
    
    printf("\n");

    return 0;
}

void criptografaMaiuscula(char letra, int chave){
    int l = letra + chave;

    while(l > 'Z')
    {
        l = l - 'Z';
        l = l + 'A' - 1;
    }
    printf("%c", l);
}

void criptografaMinuscula(char letra, int chave){
    int l = letra + chave;

    while(l > 'z')
    {
        l = l - 'z';
        l = l + 'a' - 1;
    }
    printf("%c", l);
}