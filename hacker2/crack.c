#define _XOPEN_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int crackPassword(char salt[], char senha[]);

int 
main()
{
    char salt[2];
    char senha[30];

    printf("introduza a senha: ");
    scanf("%s", senha);

    printf("introduza o salt: ");
    scanf("%s", salt);

    int x = crackPassword(salt, senha);

    return 0;

} 


int crackPassword(char salt[], char senha[])
{
    // char *senhaCriptografada;
    char palavra[30];
    char *hash;

    FILE *arq;
    char Linha[30];
    char *result;
    int i;

    // Abre um arquivo TEXTO para LEITURA
    arq = fopen("andre_wordlist.txt", "rt");
    if (arq == NULL)  // Se houve erro na abertura
    {
        printf("Problemas na abertura do arquivo\n");
        return 1;
    }

    // senhaCriptografada = crypt(senha, salt);
    // puts(senhaCriptografada);

    i = 1;
    while (!feof(arq))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 30, arq);  // o 'fgets' lê até 29 caracteres ou até o '\n'

        if (result)// Se foi possível ler
        {
            for(int j=0; j< 30; j++)
            {
                palavra[j] = '\0';
            }
            strncpy(palavra, Linha, strlen(Linha)-1);
            hash = crypt(palavra, salt); 
            // printf("Linha %d : %s - %s\n", i, hash, palavra);

        
            if(strcmp(senha, hash) == 0)
            {
                printf("Linha %d : %s - SENHA: %s\n", i, hash, palavra);
                return 0;
            }
        }  
        
        i++;
    }
    fclose(arq);

    return 1;
}