#include <stdio.h>
#include <stdlib.h>

typedef struct Lista lista;

struct Lista
{
    int num;
    lista *proximo;
};


int
main(void)
{
    lista *inicio;
    lista *aux;

    inicio = (lista *) malloc(sizeof(lista));
    aux = (lista *) malloc(sizeof(lista));

    inicio = NULL;
    aux = NULL;

    for (int i = 0; i < 5; i++)
    {
        lista *p = (lista *) malloc(sizeof(lista));
        p->num = i * 10;
        p->proximo = NULL;

        if(inicio == NULL)
        {
            inicio = p;
        }

        else
        {
            aux ->proximo = p;
        }

        aux = p;
    }

    lista *l;

    l = (lista *) malloc(sizeof(lista));
    l = inicio;

    while (l->proximo != NULL)
    {
        printf("%d\n", l->num);
        l = l->proximo;
    }
    
    printf("%d\n", l->num);

    // Liberar as memorias alocadas
    while (inicio->proximo != NULL)
    {
        inicio->proximo = (inicio->proximo)->proximo;
        free(inicio->proximo);
    }
    
    free(inicio);

    return 0;
}